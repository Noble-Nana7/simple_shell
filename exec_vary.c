#include "main.h"

/**
 * exec_std_cmd - This function handles simple commands 
 * typically found in "PATH".
 * @cmd: The command in PATH to handle.
 */

void exec_std_cmd(char *cmd)
{
	char *cmdpath;
	char *argv[100];
	char *tok;
	int i = 0;

	tok = strtok(cmd, " ");
	while (tok != NULL)
	{
		argv[i++] = tok;
		tok = strtok(NULL, " ");
	}
	argv[i] = NULL;
	
	cmdpath = find_cmd(cmd);
	if (!cmdpath)
	{
		printerr(cmd);
		return;
	}
	if (fork() == 0)
	{
		if (execve(cmdpath, argv, NULL) == -1)
		{
			printerr(cmdpath);
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		wait(NULL);
	}
	free(cmdpath);
}

/**
 * exec_path_cmd - This func handles commands that
 * specify a path,
 * either relative or absolute
 * @cmd: The path command
 */

void exec_path_cmd(char *cmd)
{
	char *argv[100];
	int i = 0;
	char *tok;

	tok = strtok(cmd, " ");
	while (tok != NULL)
	{
		argv[i++] = tok;
		tok = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (access(cmd, X_OK) != 0)
	{
		printerr(cmd);
		return;
	}
	
	if (fork() == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			printerr(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		wait(NULL);
	}
}

/**
 * exec_copy_cmd - This function handles commands that
 * involves copying a file before
 * execution.
 * @cmd: The command.
 */
void exec_copy_cmd(char *cmd)
{
	char src[PATH_MAX];
	char dest[PATH_MAX];
	char *argv[2];
	pid_t pid;

	argv[0] = NULL;
	argv[1] = NULL;

	if (sscanf(cmd, "%s %s", src, dest) != 2)
	{
		printerr("Invalid command format");
		return;
	}

	if (copy_file(src, dest) != 0)
	{
		printerr("copy failed");
		return;
	}
	argv[0] = dest;

	pid = fork();
	if (pid == -1)
	{
		printerr("fork failed");
		return;
	}

	if (pid == 0)
	{
		if (execve(dest, argv, NULL) == -1)
		{
			printerr(dest);
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		wait(NULL);
	}
	remove(dest);
}

/**
 * This func specifially handles exit
 * and terminates the shell process.
 */
void exec_exit(void)
{
	exit(EXIT_SUCCESS);
}

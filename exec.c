#include "main.h"

/**
 * exec_command - This function executes a command
 * using execve.
 * @cmd: The command to execute
 */

void exec_command(char *cmd)
{
	pid_t pid;
	char *argv[100];
	char *tok;
	int i = 0;
	char *cmdpath;

	tok = strtok(cmd, " ");
	while (tok != NULL)
	{
		argv[i++] = tok;
		tok = strtok(NULL, " ");
	}

	argv[i] = NULL;

	if (strchr(argv[0], '/') != NULL)
	{
		cmdpath = argv[0];
		if (access(cmdpath, X_OK) != 0)
		{
			printerr(argv[0]);
			return;
		}
	}
	else
	{
		cmdpath = find_cmd(argv[0]);
		if (!cmdpath)
		{
			printerr(argv[0]);
			return;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		printerr("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
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

	if (cmdpath != argv[0])
	{
		free(cmdpath);
	}
}

#include "main.h"

/**
 * read_in - THis function read the input from
 * the user.
 *
 * Return: The input string.
 */

char *read_in(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	line[strcspn(line, "\n")] = '\0';
	return (line);
}

/**
 * exec_command - This functions executes a command using
 * execve.
 * @cmd: The command to execute.
 */

void exec_command(char *cmd)
{
	pid_t pid;
	char *argv[2];

	argv[0] = cmd;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(cmd);
			exit(-1);
		}
	}
	else
	{
		wait(NULL);
	}
}


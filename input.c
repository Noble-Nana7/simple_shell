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
		printerr("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			printerr(cmd);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * trim_ws - Removes leading and trailing
 * whitespace from a string
 * @str: The string to trim
 * Return: The trimmed string.
 */
char *trim_ws(char *str)
{
	char *start = str;
	char *end;

	while (isspace((unsigned char)*start))
	{
		start++;
	}
	end = start + strlen(start) - 1;
	while (end > start && isspace((unsigned char)*end))
	{
		end--;
	}
	end[1] = '\0';

	return (start);
}

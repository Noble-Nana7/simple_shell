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
	char *argv[100];
	char *tok;
	int i = 0;

	tok = strtok(cmd, " ");
	while (tok != NULL)
	{
		argv[i++] = tok;
		tok = strtok(NULL,  " ");
	}

	argv[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		printerr("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			printerr(argv[0]);
			exit(EXIT_FAILURE);
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

	if (str == NULL || *str == '\0')
	{
		return (str);
	}

	while (isspace((unsigned char)*start))
	{
		start++;
	}

	if (*start == '0')
	{
		return (start);
	}

	end = start + strlen(start) - 1;
	while (end > start && isspace((unsigned char)*end))
	{
		end--;
	}
	end[1] = '\0';

	return (start);
}

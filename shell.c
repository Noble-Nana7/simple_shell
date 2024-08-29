#include "main.h"

/**
 * shell - The ,main loop of the shell
 */

void shell(void)
{
	char *line;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

		line = read_in();
		if (line == NULL)
		{
			perror("read_in");
			exit(1);
		}

		if (line[0] != '\0')
		{
			exec_command(line);
		}

		free(line);
	}
}

/**
 * main - The entry point of the shell
 * Return: o on success, or an error code.
 */
int main(void)
{
	shell();
	return (0);
}

#include "main.h"

/**
 * shell - The ,main loop of the shell
 */

void shell(void)
{
	char *line;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		}

		line = read_in();
		if (line == NULL)
		{
			exit(EXIT_SUCCESS);
		}

		line = trim_ws(line);

		if (line[0] != '\0')
		{
			exec_command(line);
		}

		free(line);
	}
}
/**
 * main - the entry
 * Return: 0 Always success
 */

int main(void)
{
	shell();
	return (0);
}

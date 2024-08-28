#include "main.h"

/**
 * main - The entry point of the shell.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *input;
	char **args;
	int stats;

	while (stats)
	{
		prompt();
		input = readin();
		args = tokenin(input);
		stats = exec_command(args);

		free(input);
		free(args);
	}

	return(0);
}

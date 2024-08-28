#include "main.h"

extern char **environ;

/**
 * prompt - Handles the prompts display
 * on stdout.
 */

void prompt(void)
{
	printf("Nana$ ");
}


/**
 * readin - Reads a line of input from the standard input (stdin).
 *
 * Return: A pointer to the line of input read. The caller is responsible for
 * freeing this memory when it is no longer needed.
 */
char *readin(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(0);
		}
		else
		{
			perror("getline");
			exit(1);
		}
	}
	return (input);
}

/**
 * tokenin - This function splits a string into an array of tokens.
 * @input: The input string to be tokenized.
 *
 * Return: A pointer to an array of tokens (strings).
 *         The last element of the array is NULL to indicate the end.
 */
char **tokenin(char *input)
{
	int bufsize = 64;
	int i = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char*));

	if (!tokens)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(input, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char*));

			if (!tokens)
			{
				perror("realloc");
				exit(1);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * exec_command - This function forks a process to execute a command.
 * @args: An array of arguments where the first element is the command to execute.
 *
 * Return: 1 to indicate the shell should continue running.
 */
int exec_command(char **args)
{
	pid_t pid;
	int stats;

	if (args[0] == NULL)
	{
		/* An empty command was entered. */
		return 1;
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("fork");
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &stats, WUNTRACED);
		} while (!WIFEXITED(stats) && !WIFSIGNALED(stats));
	}

	return (1);
}

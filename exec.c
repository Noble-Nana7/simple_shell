#include "main.h"

/**
 * exec_command - This command executes a command
 * based on a specific
 * implementation for handling using execve.
 * @cmd: a particular command to exec
 */

void exec_command(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (is_cpy(cmd))
	{
		exec_copy_cmd(cmd);
	}
	else if (is_path(cmd))
	{
		exec_path_cmd(cmd);
	}
	else
	{
		exec_std_cmd(cmd);
	}
}

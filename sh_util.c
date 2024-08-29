#include "main.h"

/**
 * printerr - Prints an error message
 * @cmd: The command that caused the error
 */

void printerr(char *cmd)
{
	perror(cmd);
}

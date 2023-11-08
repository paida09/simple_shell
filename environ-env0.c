#include "shell.h"

/**
 * environ_clear - ...
 * @env: ...
 *
 * Return: void
 */

void environ_clear(char **env)
{
	unsigned int y;

	for (y = 0; env[y] != NULL; y++)
	{
		free(env[y]);
	}
	free(env);
}

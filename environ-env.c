#include "shell.h"

/**
 * environ_create - ...
 * @env: ...
 *
 * Return: Pointer
 */
char **environ_create(char **env)
{
	char **updated_env = NULL;
	size_t y;

	for (y = 0; env[y] != NULL; y++)
		;
	updated_env = malloc(sizeof(char *) * (y + 1));
	if (updated_env == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (y = 0; env[y] != NULL; y++)
	{
		updated_env[y] = dupstr(env[y]);
	}
	updated_env[y] = NULL;
	return (updated_env);
}

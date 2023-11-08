#include "shell.h"

/**
 * key_add - ...
 * @myvars: ...
 *
 * Return: void
 */

void key_add(vars_t *myvars)
{
	unsigned int y;
	char **new_env;

	for (y = 0; myvars->env[y] != NULL; y++)
		;
	new_env = malloc(sizeof(char *) * (y + 2));
	if (new_env == NULL)
	{
		error_print(myvars, NULL);
		myvars->status = 127;
		quit(myvars);
	}
	for (y = 0; myvars->env[y] != NULL; y++)
	{
		new_env[y] = myvars->env[y];
	}
	new_env[y] = value_add(myvars->av[1], myvars->av[2]);
	if (new_env[y] == NULL)
	{
		error_print(myvars, NULL);
		free(myvars->buffer);
		free(myvars->commands);
		free(myvars->av);
		environ_clear(myvars->env);
		free(new_env);
		exit(127);
	}
	new_env[y + 1] = NULL;
	free(myvars->env);
	myvars->env = new_env;
}

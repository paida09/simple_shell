#include "shell.h"

/**
 * unset_environ - Deletes a variable
 * @myvars: Pointer
 *
 * Return: void
 */
void unset_environ(vars_t *myvars)
{
	char **key, **new_env;

	unsigned int x, y;

	if (myvars->av[1] == NULL)
	{
		error_print(myvars, ": Incorrect number of arguments\n");
		myvars->status = 2;
		return;
	}
	key = find_lock(myvars->env, myvars->av[1]);
	if (key == NULL)
	{
		error_print(myvars, ": No variable to unset");
		return;
	}
	for (x = 0; myvars->env[x] != NULL; x++)
		;
	new_env = malloc(sizeof(char *) * x);
	if (new_env == NULL)
	{
		error_print(myvars, NULL);
		myvars->status = 127;
		quit(myvars);
	}
	for (x = 0; myvars->env[x] != *key; x++)
	{
		new_env[x] = myvars->env[x];
	}
	for (y = x + 1; myvars->env[y] != NULL; y++, x++)
		new_env[x] = myvars->env[y];
	new_env[x] = NULL;
	free(*key);
	free(myvars->env);
	myvars->env = new_env;
	myvars->status = 0;
}

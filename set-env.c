#include "shell.h"

/**
 * set_environ - ...
 * @myvars: ...
 *
 * Return: ...
 */
void set_environ(vars_t *myvars)
{
	char **theKey;
	char *w;

	if (myvars->av[1] == NULL || myvars->av[2] == NULL)
	{
		error_print(myvars, ": Incorrect number of arguments\n");
		myvars->status = 2;
		return;
	}
	theKey = &(myvars->env[0]);
	if (theKey == NULL)
	{
		key_add(myvars);
	}
	else
	{
		w = value_add(myvars->av[1], myvars->av[2]);
		if (w == NULL)
		{
			error_print(myvars, NULL);
			free(myvars->buffer);
			free(myvars->commands);
			free(myvars->av);
			environ_clear(myvars->env);
			exit(127);
		}
		free(*theKey);
		*theKey = w;
	}
	myvars->status = 0;
}

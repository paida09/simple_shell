#include "shell.h"

/**
 * quit - ...
 * @myvars: ...
 *
 * Return type: void.
 */

void quit(vars_t *myvars)
{
	int exit_status;

		while (cmprstr(myvars->av[0], "exit") == 0 && myvars->av[1] != NULL)
	{
		exit_status = _atoi(myvars->av[1]);

		if (exit_status == -1)
		{
			myvars->status = 2;
			error_print(myvars, ": Illegal number: ");
			puts_in(myvars->av[1]);
			puts_in("\n");
			free(myvars->commands);
			myvars->commands = NULL;
			return;
		}

		myvars->status = exit_status;
		break;
	}

	free(myvars->buffer);
	free(myvars->av);
	free(myvars->commands);
	environ_clear(myvars->env);
	exit(myvars->status);
}

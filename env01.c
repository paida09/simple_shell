#include "shell.h"

/**
 * my_env - ...
 * @myvars: ...
 *
 * Return: void
 */

void my_env(vars_t *myvars)
{
	unsigned int y = 0;

	while (myvars->env[y])
	{
		my_puts(myvars->env[y]);

		my_puts("\n");
		y++;
	}
	myvars->status = 0;
}

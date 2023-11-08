#include "shell.h"

/**
 * env - ...
 * @myvars: ...
 *
 * Return: void
 */

void env(vars_t *myvars)
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

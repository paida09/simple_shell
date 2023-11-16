#include "shell.h"

/**
 * pathCheck - ...
 * @myvars: ...
 *
 * Return: void.
 */
void pathCheck(vars_t *myvars)
{
	char *path;
	char **paths;
	int l;

	if (checkdir(myvars->av[0]))
	{
		exec_func(myvars);
		return;
	}

	path = pathFind(myvars->env);
	if (path == NULL)
	{
		error_print(myvars, ": PATH environment variable is not set\n");
		myvars->status = 127;
		quit(myvars);
	}

	paths = my_token(path, ":");
	for (l = 0; paths && paths[l]; l++)
	{
		char *full_path = strcat(paths[l], myvars->av[0]);

		struct stat buff;

		if (stat(full_path, &buff) == 0)
		{
			path_exe(full_path, myvars);
			free(full_path);
			break;
		}
		free(full_path);
	}
	free(paths);
	if (paths[l] == NULL)
	{
		error_print(myvars, ": not found\n");
		myvars->status = 127;
		quit(myvars);
	}
}

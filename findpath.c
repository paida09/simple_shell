#include "shell.h"
#include <string.h>

/**
 * pathFind - ...
 * @env: ...
 *
 * Return: Pointer to the node containing PATH, or NULL on failure.
 */
char *pathFind(char **env)
{
	char *path_var = "PATH=";
	size_t path_length = strlength(path_var);
	size_t l;

	if (env == NULL)
		return (NULL);

	while (*env)
	{
		char *env_var = *env;

		for (l = 0; env_var[l] != '\0' && l < path_length; l++)
		{
			if (env_var[l] != path_var[l])
				break;
		}

		if (l == path_length)
		{
			return (env_var);
		}

		env++;
	}
	return (NULL);
}

#include "shell.h"

/**
 * find_lock - ...
 * @env: ...
 * @key: ...
 *
 * Return: Pointer to the address of the specified environment variable.
 */
char **find_lock(char **env, char *key)
{
	unsigned int x, y, length;

	length = strlength(key);
	for (x = 0; env[x] != NULL; x++)
	{
		for (y = 0; y < length; y++)
			if (key[y] != env[x][y])
			{
				break;
			}
		if (y == length && env[x][y] == '=')
		{
			return (&env[x]);
		}
	}
	return (NULL);
}

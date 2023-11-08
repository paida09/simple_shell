#include "shell.h"

/**
 * my_token - ...
 * @buff: ...
 * @dlimiter: ...
 *
 * Return:  ...
 */
char **my_token(char *buff, char *dlimiter)
{
	char **token = NULL;
	size_t y = 0;
	size_t l_count = 10;

	if (buff == NULL)
	{
		return (NULL);
	}

	token = malloc(sizeof(char *) * l_count);
	if (token == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}

	for (; y < l_count; y++)
	{
		token[y] = strtoken(buff, dlimiter);
		if (token[y] == NULL)
			break;
		if (y == l_count - 1)
		{
			token = rellocat(token, &l_count);
			if (token == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buff = NULL;
	}

	return (token);
}

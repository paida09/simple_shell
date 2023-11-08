#include "shell.h"

/**
 * value_add - ...
 * @key: ...
 * @myvalue: ...
 *
 * Return:...
 */
char *value_add(char *key, char *myvalue)
{
	unsigned int length1, length2, a, b;
	char *new_env;

	length1 = strlength(key);
	length2 = strlength(myvalue);
	new_env = malloc(sizeof(char) * (length1 + length2 + 2));
	if (new_env == NULL)
	{
		return (NULL);
	}
	for (a = 0; key[a] != '\0'; a++)
	{
		new_env[a] = key[a];
	}
	new_env[a] = '=';
	for (b = 0; myvalue[b] != '\0'; b++)
	{
		new_env[a + 1 + b] = myvalue[b];
	}
	new_env[a + 1 + b] = '\0';
	return (new_env);
}

#include "shell.h"
/**
 * checkMatch - ...
 * @c: ...
 * @str: ...
 *
 * Return: 1 if there is a match, 0 if not.
 */
unsigned int checkMatch(char c, const char *str)
{
	unsigned int y;

	for (y = 0; str[y] != '\0'; y++)
	{
		if (c == str[y])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * strtoken - Custom token.
 * @mystr: String.
 * @delim: Delimiter.
 *
 * Return: Pointer or NULL.
 */
char *strtoken(char *mystr, const char *delim)
{
	static char *start_tok;
	static char *tokenext;
	unsigned int y;

	if (mystr != NULL)
		tokenext = mystr;
	start_tok = tokenext;
	if (start_tok == NULL)
		return (NULL);
	for (y = 0; tokenext[y] != '\0'; y++)
	{
		if (checkMatch(tokenext[y], delim) == 0)
		{
			break;
		}
	}

	start_tok = tokenext + y;
	tokenext = start_tok;
	for (y = 0; tokenext[y] != '\0'; y++)
	{
		if (checkMatch(tokenext[y], delim) == 1)
			break;
	}
	if (tokenext[y] == '\0')
	{
		tokenext = NULL;
	}
	else
	{
		tokenext[y] = '\0';
		tokenext = tokenext + y + 1;
		if (*tokenext == '\0')
			tokenext = NULL;
	}
	return (start_tok);
}

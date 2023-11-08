#include "shell.h"

/**
 * checkdir - checks if the command is a part of a path
 * @mystr: command
 *
 * Return: 1 on success, 0 on failure
 */
int checkdir(char *mystr)
{
	unsigned int y;

	for (y = 0; mystr[y]; y++)
	{
		if (mystr[y] == '/')
		{
			return (1);
		}
	}
	return (0);
}

#include "shell.h"

/**
 * puts_in - ...
 * @mystr: ...
 */
void puts_in(char *mystr)
{
	ssize_t length;

	char *current = mystr;

	while (*current)
	{
		length = write(STDERR_FILENO, current, 1);

		if (length != 1)
		{
			perror("Fatal Error");
			exit(1);
		}

		current++;
	}
}

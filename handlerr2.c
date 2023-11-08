#include "shell.h"

/**
 * uitoa - This program converts an unsigned int into a string.
 * @mycount: ...
 *
 * Return: Pointer.
 */

char *uitoa(unsigned int mycount)
{
	char *numstring;
	int start = 0, end;

	if (mycount == 0)
	{
		numstring = malloc(sizeof(char) * 2);
		if (numstring == NULL)
		{
			perror("Fatal Error1");
			exit(127);
		}
		numstring[0] = '0';
		numstring[1] = '\0';
		return (numstring);
	}

	numstring = uitoa(mycount / 10);
	end = strlen(numstring) - 1;
	numstring = realloc(numstring, sizeof(char) * (strlen(numstring) + 2));
	if (numstring == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}

	while (start < end)
	{
		char temp = numstring[start];

		numstring[start] = numstring[end];

		numstring[end] = temp;
		start++;
		end--;
	}

	return (numstring);
}

/**
 * error_print - ...
 * @myvars: ...
 * @word: ...
 *
 * Return: void
 */

void error_print(vars_t *myvars, char *word)
{
	char *count = uitoa(myvars->count);

	if (!count)
	{
		perror("uitoa failed");
		exit(EXIT_FAILURE);
	}

	puts_in(myvars->argv[0]);
	puts_in(": ");
	puts_in(count);
	puts_in(": ");
	puts_in(myvars->av[0]);

	if (word)
	{
		puts_in(word);
	}
	else
	{
		perror("");
	}

	free(count);
}

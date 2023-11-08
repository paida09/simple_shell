#include "shell.h"

/**
 * cmprstr - this program compares strings.
 * @mystrcmp1: first string to compare.
 * @mystrcmp2: second string to compare.
 *
 * Return: 0 on success.
 */
int cmprstr(char *mystrcmp1, char *mystrcmp2)
{
	int j = 0;

	while (mystrcmp1[j] && mystrcmp2[j] && mystrcmp1[j] == mystrcmp2[j])
	{
		j++;
	}

	return (mystrcmp1[j] - mystrcmp2[j]);
}

/**
 * strlength - ...
 * @strng: ...
 * Return: ...
 */
unsigned int strlength(char *strng)
{
	unsigned int length = 0;

	while (strng[length] != '\0')
	{
		length++;
	}

	return (length);
}

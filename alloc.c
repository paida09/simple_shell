#include "shell.h"

/**
 * rellocat - ...
 * @oldptr: ...
 * @oldsize: ...
 *
 * Return: Pointer to the new size array.
 */
char **rellocat(char **oldptr, size_t *oldsize)
{
	size_t new_size = (*oldsize) * 2 + 10;
	size_t y;

	char **new_ptr = malloc(sizeof(char *) * new_size);

	if (new_ptr == NULL)
	{
		free(oldptr);
		return (NULL);
	}

	for (y = 0; y < (*oldsize); y++)
	{
		new_ptr[y] = oldptr[y];
	}

	for (y = (*oldsize); y < new_size; y++)
	{
		new_ptr[y] = NULL;
	}

	*oldsize = new_size;

	free(oldptr);

	return (new_ptr);
}

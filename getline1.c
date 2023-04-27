#include "shell.h"

/**
 * read_line - reads input from stdin
 * @data: contains information about our shell
 * @buffer: where to store the input
 * @len: where to store the len of input
 * Return: len of the input
 */
ssize_t read_line(shell_data *data, char *buffer, size_t *len)
{
	ssize_t rd = 0;

	if (*len)
		return (0);

	rd = read(data->readfd, buffer, RD_BUFFER_SIZE);
	if (rd >= 0)
		*len = rd;
	return (rd);
}

/**
 * _realloc - reallocates a memory space
 * @ptr: pointer to memory space
 * @old: old size of the memory
 * @new: new size of the memory
 * Return: pointer to old mem
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *p;

	if (!ptr)
		return (malloc(new));
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	if (new == old)
		return (ptr);
	p = malloc(new);
	if (!p)
		return (NULL);

	/*
	 * determines the number of bytes to copy from the old memory block
	 * to the new memory block.
	 */
	old = old < new ? old : new;
	/*
	 * since we copying from the end, we want to ensure that we only
	 * copy bytes that exist in the old memory block.
	 */

	while (old--)
		p[old] = ((char *)ptr)[old];
	free(ptr);
	return (p);
}

#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: string
 * Return: new string
 */
char *_strdup(const char *str)
{
	char *new;
	int len;

	len = _strlen(str);
	new = malloc(sizeof(char) * len + 1);

	if (new == NULL)
		return (NULL);

	_memcpy(new, str, len + 1);

	return (new);
}



/**
 * _memcpy - copies data from src to dest
 * @dest: destination to copy the data to
 * @src: source of data
 * @n: number of bytes to copy
 * Return: a void pointer to the new data
 */
void _memcpy(void *dest, const void *src, int n)
{
	int i;

	char *des = (char *)dest;
	char *sr = (char *)src;

	for (i = 0; i < n; i++)
		des[i] = sr[i];
}

/**
 * _memset - intitiazes a buffer to a specific value
 * @ptr: pointer to the memory to fill
 * @val: ponter to fill it with
 * @n: how no. of bytes to fill
 * Return: pointer to initialized memory
 */
char *_memset(char *ptr, char val, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		ptr[i] = val;

	}
	return (ptr);
}

/**
 * _strncat - cat n no. of strings
 * @dest: First string
 * @src: Second String
 * @n: no. of strings to copy from src
 * Return: new concantenated strings
 */

char *_strncat(char *dest, char *src, int n)
{
	int len, i;

	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';

	return (dest);
}

/**
 * _strncpy - copies n no. of string
 * @dest: destination
 * @src: Source
 * @n: no. of string to copy
 * Return: new copied string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

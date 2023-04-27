#include "shell.h"

/**
 * _strlen - calculates the length of a string
 * @s: array of character
 * Return: lenght of string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * _strcpy - copies the second arg and stores in the first arg
 * @dest: destinaton to copy to
 * @src: source to copy from
 * Return: pointer to the new string
 */
char *_strcpy(char *dest, const char *src)
{
	int index = 0;

	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}

	dest[index] = '\0';
	return (dest);
}

/**
 * _strcat - concantenates two strings
 * @dest: destination to store new string
 * @src: added to the end of dest
 * Return: Pointer to the new string
 */
char *_strcat(char *dest, const char *src)
{
	int len, i;

	len = _strlen(dest);

	for (i = 0; src[i]; i++)
		dest[len + i] = src[i];

	dest[len + i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal
 *		or their difference if not
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strcspn - counts the number character that doesn't include rej
 * @src: string to parse
 * @rej: characters not needed
 * Return: count
 */
size_t _strcspn(const char *src, const char *rej)
{
	size_t count = 0;
	const char *s = src;
	const char *r;

	while (*s)
	{
		r = rej;
		while (*r)
		{
			if (*s == *r)
				return (count);
			r++;
		}
		s++;

		count++;
	}

	return (count);
}

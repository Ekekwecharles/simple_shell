#include "shell.h"

/**
 * itoa - convert integer to ascii
 * @number: integer to convert
 * @base: base to which the number should be converted
 * @flags: Optional flags that modify the behavior of the
 * function
 *
 * Return: string
 */
char *itoa(long int number, int base, int flags)
{
	static char buf[50];
	static char *arr;
	char sign = 0;
	char *ptr;
	unsigned long num = number;

	if (!(flags & UNSIGNED) && number < 0)
	{
		num = -number;
		sign = '-';
	}

	arr = flags & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';
	do {
		/* *--ptr = arr[num % base];*/
		--ptr;
		*ptr = arr[num % base];
		num /= base;
	} while (num != 0);

	if (sign)
	{
		--ptr;
		*ptr = sign;
	}
	return (ptr);
}


/**
 * str_str - checks if haystack contains needle at the beginning
 * @haystack: string to search
 * @needle: string we are looking for
 * Return: pointer to the address of the next char after needle or
 *		Null if not found
 */
char *str_str(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}

/**
 * _strchr - a function that locates a character in a string.
 * @s: string to be parsed
 * @c: character to look for
 * Return: A pointer the newly found character
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (NULL);
}


/**
 * _strtok - breaks a string into tokens
 * @str: string to parse
 * @c: delimiter to tokenize the string
 * Return: pointer to the new string
 */
char **_strtok(char *str, char *c)
{
	int a, b, len, index, toks = 0;
	char **buf;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!c)/* if c wasn't provided, it defaults to " " */
		c = " ";
	/*
	 * counts the number of tokens/words in the string. considers a word to be a
	 * sequence of non-delim chars followed by a delim or the end of the string
	 */
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delimiter(str[a], c) && (is_delimiter(str[a + 1], c) || !str[a + 1]))
			toks++;
	if (toks == 0)
		return (NULL);
	buf = malloc((1 + toks) * sizeof(char *));/*create memory of pointers*/
	if (!buf)/*if (buf == NULL)*/
		return (NULL);
	for (a = 0, b = 0; b < toks; b++)
	{
		while (is_delimiter(str[a], c))/* skip delimiter charactr */
			a++;
		len = 0;
		while (!is_delimiter(str[a + len], c) && str[a + len])
			len++;/*finds d len of each word*/
		buf[b] = malloc((len + 1) * sizeof(char));/*create memory for each string*/
		if (!buf[b])/*if (buf[b] == NULL)*/
		{
			for (len = 0; len < b; len++)
				free(buf[len]);
			free(buf);
			return (NULL);
		}
		for (index = 0; index < len; index++)
			buf[b][index] = str[a++];
		buf[b][index] = 0;
	}
	buf[b] = NULL;
	return (buf);
}


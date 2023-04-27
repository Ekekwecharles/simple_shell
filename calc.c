#include <stdio.h>
#include <stdlib.h>

/**
 * add - adds two numbers
 * @n: first number
 * @m: second number
 *
 * Return: result of the operation
 */

int add(int n, int m)
{
	return (n + m);
}
/**
 * mul - multiplies two numbers
 * @n: first number
 * @m: second number
 *
 * Return: result of the operation
 */
int mul(int n, int m)
{
	return (n * m);
}
/**
 * sub - subtracts two numbers
 * @n: first number
 * @m: second number
 *
 * Return: result of the operation
 */
int sub(int n, int m)
{
	return (n - m);
}
/**
 * divv - divides two numbers
 * @n: first number
 * @m: second number
 *
 * Return: result of the operation
 */
int divv(int n, int m)
{
	return (n / m);
}


/**
 * main - a basic calculator
 * @argc: argument count
 * @argv: array arguments
 *
 * Return: result of the operation
 *		of 0 if failed
 */
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("usage: %s int1 operator  int2\n", argv[0]);
		return (0);
	}

	if (argv[2][0] == '+')
		printf("%d\n", add(atoi(argv[1]), atoi(argv[3])));
	else if (argv[2][0] == '*')
		printf("%d\n", mul(atoi(argv[1]), atoi(argv[3])));
	else if (argv[2][0] == '-')
		printf("%d\n", sub(atoi(argv[1]), atoi(argv[3])));
	else if (argv[2][0] == '/')
		printf("%d\n", divv(atoi(argv[1]), atoi(argv[3])));


	return (0);
}

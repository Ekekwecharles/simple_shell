#include "shell.h"

/**
 * main - start of a simple shell
 * @argc: argument count
 * @argv: array of string arguments
 * Return: 0 if success
 *		1 if fail
 */
int main(int argc, char *argv[])
{
	shell_data data[] = {SHELL_DATA_INIT};
	int fd = 2;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				eff_puts(argv[0]);
				eff_puts(": 0: Can't open ");
				eff_puts(argv[1]);
				eff_putchr('\n');
				eff_putchr(FLUSH);
				exit(127);
			}
			return (1);
		}
		data->readfd = fd;
	}
	/*
	 * gets and save the parent enviromental varaible and
	 * save a pointer to it in the data struct
	 */
	set_env_list(data);
	prompt(data, argv);
	return (0);
}

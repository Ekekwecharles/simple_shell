#include "shell.h"

/**
 * my_unsetenv - this removes usee defined environment vars
 * @data: contains infomation about our shell
 * Return: 0
 */
int my_unsetenv(shell_data *data)
{
	int j;

	/*
	 * after a command typed by the user is parsed, argc holds the number
	 * of tokens in the in the command
	 * if you passed only unsetenv, this function wont execute
	 * usage: unsetenv VARIABLE_NAME
	 */
	if (data->argc == 1)
	{
		eff_puts("Too few arguments.\n");
		return (1);
	}
	/*
	 * this makes sure you can unset any number of variables you previously
	 * set. usage:
	 * unsetenv VAR1 VAR2 VAR3 ....
	 */
	for (j = 1; j <= data->argc; j++)
		_unsetenv(data, data->argv[j]);

	return (0);
}

/**
 * my_env - this prints all the env variables
 * @data: contains infomation about shell
 *
 * Description: when the keyword env is passes by the user
 * this function gets callde from the check_builtin, and
 * prints all the environment variables
 * Return: Always 0
 */
int my_env(shell_data *data)
{
	print_list_data(data->env);

	return (0);
}


/**
 * _setenv - updates and env or add a new one
 * @data: contains information about our shell
 * @var: environmental variables
 * @val: value to update
 * Return: 0 on success
 *		1 on failure
 */
int _setenv(shell_data *data, char *var, char *val)
{
	char *buffer = NULL, *ptr;
	list_t *node;

	if (!var || !val)
		return (0);

	/* 2 is added to account for the '=' and the null terminator (\0)*/
	buffer = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, val);
	node = data->env;

	while (node)
	{
		ptr = str_str(node->data, var);
		if (ptr && *ptr == '=')
		{
			free(node->data);
			node->data = buffer;
			data->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(data->env), buffer, 0);
	free(buffer);
	data->env_changed = 1;
	return (0);
}



/**
 * _getenv - gets the value of an environment variable
 * @data: contains information about our shell
 * @var: variable name in the form of "HOME="
 * Return: ptr to value on sucess
 *		NULL if fail
 */
char *_getenv(shell_data *data, const char *var)
{
	list_t *node = data->env;
	char *ptr;

	while (node)
	{
		ptr = str_str(node->data, var);
		/*
		 * if ptr is not NULL and the value it points to is not '\0'
		 * (null character), execute the code inside the if statement".
		 */
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_env_list - saves the parent enviroment
 * @data: data->env points to the node head
 * Return: 0
 */
int set_env_list(shell_data *data)
{
	size_t j;
	list_t *node = NULL;

	for (j = 0; environ[j]; j++)
	{
		add_node_end(&node, environ[j], 0);
	}

	data->env = node;
	return (0);
}


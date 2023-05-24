#include "shell.h"

/**
 * builtin_set_env - setting environment variable using the provided key-value
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_set_env(data_of_program *data)
{
	/* validate args */
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_set_key(data->tokens[1], data->tokens[2], data);
	return (0);
}

#include "shell.h"

/**
 * builtin_unset_env - unsetting/remo environment variable based on provid key
 * @data: struct for the program's data'
 * Return: 0 to indicate success
 */
int builtin_unset_env(data_of_program *data)
{
	/* validate args */
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}

#include "shell.h"

/**
 * print_environ - prints the current environ
 * @data: struct for the program's data
 * Return: nothing
 */
void print_environ(data_of_program *data)
{
	int k;

	for (k = 0; data->env[k]; k++)
	{
		_print(data->env[k]);
		_print("\n");
	}
}

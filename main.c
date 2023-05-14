#include "shell.h"

/**
 * main - This is the main Simple_Shell
 * Return: 0
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		/* Run read function */
		readInput(input);

		/* Check if the user wants to exit */
		if (strcmp(input, "exit") == 0)
			break; /* Exit the loop and terminate the shell */

		/* Run execute function */
		executeCommand(input);
	}

	return (0);
}

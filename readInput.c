#include "shell.h"

/**
 * readInput - function that read input
 * @input: char input by user
 * Return: void
 */

void readInput(char *input)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);

	fgets(input, MAX_INPUT_LENGTH, stdin);

	/* Remove newline character from input */
	input[strcspn(input, "\n")] = '\0';
}

#include "shell.h"

/**
 * readInput - function that read input
 * @input: char input by user
 * Return: void
 */

void readInput(char *input)
{
	if (isatty(STDIN_FILENO))
		printf("($) ");

	fgets(input, MAX_INPUT_LENGTH, stdin);

	/* Remove newline character from input */
	input[strcspn(input, "\n")] = '\0';
}

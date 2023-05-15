#include "shell.h"

/**
 * executeCommand - function that execute the code
 * @input: user input
 * Return: void
 */
void executeCommand(char *input)
{
	char *args[64]; /* Maximum 64 arguments */
	int status;
	pid_t pid = fork(); /* Fork a child process */

	/* Tokenize input */
	char *token = strtok(input, " ");
	int i = 0;

	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL; /* Set the last argument to NULL */

	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
			perror("execvp error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		/* Forking failed */
		perror("fork error");
	else
		/* Parent process */
		waitpid(pid, &status, 0);
}

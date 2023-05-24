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
		if (strcmp(args[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		else if (strcmp(args[0], "env") == 0)
		{
			extern char **environ;
			char **env = environ;
			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Execute the command */
			if (execvp(args[0], args) == -1)
			{
				perror("execvp error");
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (pid < 0)
		/* Forking failed */
		perror("fork error");
	else
		/* Parent process */
		waitpid(pid, &status, 0);
}

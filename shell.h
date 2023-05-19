#ifndef SHeLL_H
#define SHELL_H

			/* Libraris */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

			/* Buffers */
#define MAX_INPUT_LENGTH 1024

			/* Prototypes */
void readInput(char *input);
void executeCommand(char *input);
ssize_t my_getline(char **pline, size_t *num, FILE *stream);

#endif /* SHELL_H */

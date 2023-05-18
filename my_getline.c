#include "shell.h"

/**
 * my_getline - function that read input like getline
 * @pline: pointer to a pointer to a character
 * @num:  pointer to a size_t
 * @streem: file stream from which
 * Return: number of characters read
 */
ssize_t my_getline(char **pline, size_t *num, FILE *streem)
{
	ssize_t bytesRead = 0;
	size_t bufferSize = 0;
	int c;

	if (pline == NULL || num == NULL || streem == NULL)
		return (-1); /* invalid arguments */
	/* initial buffer if necessary */
	if (*pline == NULL || *num == 0)
	{
		*num = 128; /* Initial buffer size */
		*pline = (char*)malloc(*num);
		if (*pline == NULL)
			return (-1); /* Memory allocation error */
	}
	/* Read characters until a newline or EOF is encountered */
	while ((c = fgetc(streem)) != '\n' && c != EOF)
	{
		if (bytesRead + 1 >= *num)
		{
			/* Resize buffer if necessary */
			*num *= 2; /* Double the buffer size */
			char* temp = (char*)realloc(*pline, *num);
			if (temp == NULL)
				return (-1); /* Memory reallocation error */
			*pline = temp;
		}
		(*pline)[bytesRead++] = (char)c;
	}
	/* Check for end-of-file without any characters read */
	if (bytesRead == 0 && c == EOF)
		return (-1);

	(*pline)[bytesRead] = '\0'; /* Add  NULL-terminate */

	return (bytesRead + 1); /* Return the number of characters read +1 to work like getline*/
}

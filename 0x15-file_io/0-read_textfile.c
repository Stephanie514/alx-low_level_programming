#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
* read_textfile- function that reads a text file and
*                prints it to the POSIX standard output.
* @filename: the file being read
* @letters: number of letters to be read and printed
* Return: actual number of letters it could read and print,
*        0 when function fails or filename is NULL.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	ssize_t b, c;
	char *buffer;

	if (filename == NULL)
		return (0);
	file = fopen(filename, "r");
	if (file == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	b = fread(buffer, sizeof(char), letters, file);
	c = fwrite(buffer, sizeof(char), b, stdout);
	free(buffer);
	fclose(file);
	return (c);
}

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
	char *buffer;
	ssize_t file, b, c;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	c = read(file, buffer, letters);
	b = write(STDOUT_FILENO, buffer, c);
	free(buffer);
	close(file);
	return (b);
}

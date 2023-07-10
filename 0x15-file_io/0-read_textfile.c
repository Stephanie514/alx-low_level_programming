#include "main.h"

/**
 * read_textfile - function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: The file being read.
 * @letters: Number of letters to be read and printed.
 * Return: Actual number of letters it could read and print,
 *         0 when the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t b, c;
	char *buffer;

	if (filename == NULL)
		return (0);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file);
		return (0);
	}
	b = read(file, buffer, letters);
	if (b == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}
	c = write(STDOUT_FILENO, buffer, b);
	if (c != b)
	{
		free(buffer);
		close(file);
		return (0);
	}
	free(buffer);
	close(file);
	return (c);
}

#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: name of the file.
 * @text_content: content written in the file.
 *
 * Return: 1 (success) -1 (fail)
 */
int create_file(const char *filename, char *text_content)
{
	int file, num_chars, read_write;

	if (!filename)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (num_chars = 0; text_content[num_chars]; num_chars++)
		;

	read_write = write(file, text_content, num_chars);

	if (read_write == -1)
		return (-1);

	close(file);

	return (1);
}


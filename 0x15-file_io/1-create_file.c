#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: the name of the file
 * @text_content: content written in the file.
 *
 * Return: 1 (success), -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int cont, _write;

	if (filename == NULL)
		return (-1);
	cont = open(filename, O_WRONLY | O_APPEND);
	if (cont == -1)
		return (-1);
	if (text_content == NULL)
	{
		close(cont);
		return (1);
	}
	_write = write(cont, text_content, strlen(text_content));
	if (_write == -1 || _write != (int)strlen(text_content))
	{
		close(cont);
		return (-1);
	}
	close(cont);
	return (1);
}

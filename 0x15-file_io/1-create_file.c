#include "main.h"

/**
 * create_file - Creates a file with given text content
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int file, val = 1, num = 0;

	if (filename == NULL)
		return (-1);
	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[num])
			num++;
		val = write(file, text_content, num);
	}
	if (val == -1)
		return (-1);

	close(file);
	return (1);
}

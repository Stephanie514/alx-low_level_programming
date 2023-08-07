#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int g, h, size = 0;

	if (!filename)
		return (-1);
	if (text_content)
	{
		size = 0;
		while (text_content[size] != '\0')
		{
			size++;
		}
	}
	g = open(filename, O_WRONLY | O_APPEND);
	h = write(g, text_content, size);
	if (h == -1 || g == -1)
		return (-1);
	close(g);
	return (1);
}

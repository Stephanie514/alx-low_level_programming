#include "main.h"
#include <string.h>

/**
* append_text_to_file - function that appends text at the end of a file.
* @filename: pointer to the name of the file.
* @text_content: NULL terminated string to add at the end of the file
*
* Return: 1 on success and -1 on failure, 1 if the file exists and -1
*        if the file does not exist, -1 if finename is NULL
*/

int append_text_to_file(const char *filename, char *text_content)
{
int file, _write;

if (filename == NULL)
return (-1);

file = open(filename, O_WRONLY | O_APPEND);
if (file == -1)
return (-1);
if (text_content == NULL)
{
close(file);
return (1);
}
_write = write(file, text_content, strlen(text_content));
if (_write == -1 || _write != (int)strlen(text_content))
{
close(file);
return (-1);
}

close(file);
return (1);
}

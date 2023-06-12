#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void source_file(int file_descript);

/**
* main - Copies the contents of one file to another
* @argc: number of arguments
* @argv: array of pointers to arguments.
*
* Return: 0 on success.
*/

int main(int argc, char *argv[])
{
	int input_fd, output_fd, byt_read, byt_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	output_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (output_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((byt_read = read(input_fd, buffer, sizeof(buffer))) > 0)
	{
		byt_written = write(output_fd, buffer, byt_read);
		if (byt_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (byt_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	source_file(input_fd);
	source_file(output_fd);

	return (0);
}
/**
* source_file - Closes a file descriptor.
* @file_descript: can be closed
*/

void source_file(int file_descript)
{
	int result = close(file_descript);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descript);
		exit(100);
	}
}


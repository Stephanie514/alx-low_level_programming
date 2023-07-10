#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void close_file(int file_descriptor);

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
int input_fd, output_fd, bytes_read, bytes_written;
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
while ((bytes_read = read(input_fd, buffer, sizeof(buffer))) > 0)
{
bytes_written = write(output_fd, buffer, bytes_read);
if (bytes_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
close_file(input_fd);
close_file(output_fd);
return (0);
}
/**
* close_file - Closes a file descriptor.
* @file_descriptor: The file descriptor to be closed.
*/
void close_file(int file_descriptor)
{
int result = close(file_descriptor);

if (result == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
exit(100);
}
}

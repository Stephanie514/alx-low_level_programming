#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - this prints the result of simple operations.
 * @argc: number of arguments supplied to the program.
 * @argv: array of pointers to the arguments.
 *
 * Return: Always 0.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
int dig1, dig2;
char *conn;
if (argc != 4)
{
printf("Error\n");
exit(98);
}
dig1 = atoi(argv[1]);
conn = argv[2];
dig2 = atoi(argv[3]);
if (get_op_func(conn) == NULL || conn[1] != '\0')
{
printf("Error\n");
exit(99);
}
if ((*conn == '/' && dig2 == 0) ||
(*conn == '%' && dig2 == 0))
{
printf("Error\n");
exit(100);
}
printf("%d\n", get_op_func(conn)(dig1, dig2));
return (0);
}


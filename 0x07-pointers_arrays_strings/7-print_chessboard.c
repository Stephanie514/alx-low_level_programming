#include "main.h"

/**
 * print_chessboard - function that prints the chessboard.
 *@a: pointer to the piece to print
 * Return: 0
 */

void print_chessboard(char (*a)[8])
{
int r, s;
for (r = 0; r < 8; r++)
{
for (s = 0; s < 8; s++)
{
_putchar(a[r][s]);
}
_putchar('\n');
}
}


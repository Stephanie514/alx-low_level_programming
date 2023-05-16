#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* free_grid - function that frees a 2 dimensional
* grid previously created by your alloc_grid function.
* @grid: 2d grid
* @height: the height dimension of grid
* Returns: NULL
*/

void free_grid(int **grid, int height)
{
int b;
for (b = 0; b < height; b++)
{
free(grid[b]);
}
free(grid);
}

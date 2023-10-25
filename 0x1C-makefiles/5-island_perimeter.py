#!/usr/bin/python3
"""Defines a function for calculating the perimeter of an island."""


def island_perimeter(grid):
    """Calculate and return the perimeter of an island.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in the grid.
    """
    num_columns = len(grid[0])
    num_rows = len(grid)
    perimeter = 0

    for row in range(num_rows):
        for col in range(num_columns):
            if grid[row][col] == 1:
                perimeter += 4
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2

    return perimeter

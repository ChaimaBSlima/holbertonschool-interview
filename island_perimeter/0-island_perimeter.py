#!/usr/bin/python3
"""
Island Perimeter Module
Calculates the perimeter of an island described in a grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    grid: list of list of integers (0 = water, 1 = land)
    """
    if not grid or not grid[0]:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                # Check for neighbor above
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                # Check for neighbor to the left
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter

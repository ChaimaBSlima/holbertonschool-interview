#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * is_blank - Checks if a position in the Menger sponge should be blank.
 * @row: Row index.
 * @col: Column index.
 *
 * Return: 1 if the position should be blank, 0 otherwise.
 */
int is_blank(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge of given level.
 * @level: The level of the Menger Sponge.
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_blank(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}

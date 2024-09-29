#include "sandpiles.h"
/**
* sandpiles_sum - Computes the sum of two
*  3x3 sandpiles and stabilizes the result
* @grid1: First 3x3 grid (sandpile)
* @grid2: Second 3x3 grid (sandpile)
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Step 1: Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Step 2: Stabilize grid1 */
	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}

/**
* is_unstable - Checks if the sandpile is unstable (any cell > 3)
* @grid: 3x3 grid (sandpile)
* Return: 1 if unstable, 0 otherwise
*/
int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
* topple - Topples the sandpile (distributes grains from unstable cells)
* @grid: 3x3 grid (sandpile)
*/
void topple(int grid[3][3])
{
	int i, j;

	int temp[3][3] = {0};

	/* Distribute grains */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}

	/* Update the grid with toppled values */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}

/**
* print_grid - Prints a 3x3 grid
* @grid: 3x3 grid (sandpile)
*/
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

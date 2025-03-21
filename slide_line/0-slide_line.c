#include "slide_line.h"

/**
 * slide_left - Slides and merges the array to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 *
 * Return: 1 on success, 0 on failure
 */
static int slide_left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
				line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j++;
		}
	}
	for (i = 0; i < j - 1; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}
	j = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j++;
		}
	}

	return (1);
}

/**
  * slide_right - Slides and merges the array to the right
  * @line: Pointer to the array of integers
  * @size: Number of elements in the array
  *
  * Return: 1 on success, 0 on failure
*/
static int slide_right(int *line, size_t size)
{
	 size_t i, j = size - 1;

	for (i = size - 1; i != (size_t)-1; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j--;
		}
	}

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1])
		{
			 line[i] *= 2;
			 line[i - 1] = 0;
			 i--;
		}
	}

	j = size - 1;
	for (i = size - 1; i != (size_t)-1; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j--;
		}
	}

	return (1);
}

/**
* slide_line - Slides and merges a line of integers
* @line: Pointer to the array of integers
* @size: Number of elements in the array
* @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
*
* Return: 1 on success, 0 on failure
*/
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	else
		return (slide_right(line, size));
}

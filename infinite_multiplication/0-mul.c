#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * _print_error - prints Error and exits with status 98
 */
void _print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * print_result - prints the result stored in an int array
 * @result: pointer to result array
 * @len: length of the array
 */
void print_result(int *result, int len)
{
	int i = 0;

	while (i < len && result[i] == 0)
		i++;
	if (i == len)
		putchar('0');
	else
	{
		for (; i < len; i++)
			putchar(result[i] + '0');
	}
	putchar('\n');
}

/**
 * multiply - performs the multiplication of two digit strings
 * @num1: first number
 * @num2: second number
 * Return: pointer to result array
 */
int *multiply(char *num1, char *num2)
{
	int len1 = strlen(num1), len2 = strlen(num2);
	int i, j, n1, n2, *result;

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		return (NULL);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			result[i + j + 1] += n1 * n2;
		}
	}
	for (i = len1 + len2 - 1; i > 0; i--)
	{
		if (result[i] >= 10)
		{
			result[i - 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	return (result);
}

/**
 * main - Entry point. Multiplies two positive numbers.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int *result, len;
	char *num1, *num2;

	if (argc != 3)
		_print_error();
	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit(num1) || !is_digit(num2))
		_print_error();
	len = strlen(num1) + strlen(num2);
	result = multiply(num1, num2);
	if (!result)
		return (1);
	print_result(result, len);
	free(result);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - checks if a string consists only of digits
 * @s: input string
 *
 * Return: 1 if only digits, 0 otherwise
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
 * _print_error - prints Error and exits with code 98
 */
void _print_error(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, len, i, j, *result, n1, n2;


    if (argc != 3)
        _print_error();

    num1 = argv[1];
    num2 = argv[2];

    if (!is_digit(num1) || !is_digit(num2))
        _print_error();

    len1 = strlen(num1);
    len2 = strlen(num2);
    len = len1 + len2;

    result = calloc(len, sizeof(int));
    if (!result)
        return (1);

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            result[i + j + 1] += n1 * n2;
        }
    }

    for (i = len - 1; i > 0; i--)
    {
        if (result[i] >= 10)
        {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    i = 0;
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

    free(result);
    return (0);
}

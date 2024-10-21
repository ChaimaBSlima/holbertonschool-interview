#include "palindrome.h"

/**
* is_palindrome - Checks if a given unsigned integer is a palindrome.
* @n: The unsigned long integer to check.
*
* Return: 1 if the number is a palindrome, 0 otherwise.
*/
int is_palindrome(unsigned long n)
{
	unsigned long original = n, reversed = 0, remainder;

	/* Reverse the number */
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	/* Compare the reversed number with the original */
	if (original == reversed)
		return (1);
	else
		return (0);
}

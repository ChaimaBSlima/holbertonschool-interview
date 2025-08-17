#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * cmp_str - compare two strings for qsort
 * @a: first string
 * @b: second string
 *
 * Return: result of strcmp
 */
int cmp_str(const void *a, const void *b)
{
	return (strcmp(*(char * const *)a, *(char * const *)b));
}

/**
 * check_match - check if substring matches concatenation of words
 * @s: pointer to substring
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 *
 * Return: 1 if valid concatenation, 0 otherwise
 */
int check_match(const char *s, const char **words,
		int nb_words, int word_len)
{
	char **copy;
	int i, j;

	copy = malloc(sizeof(char *) * nb_words);
	if (!copy)
		return (0);

	for (i = 0; i < nb_words; i++)
		copy[i] = (char *)words[i];

	qsort(copy, nb_words, sizeof(char *), cmp_str);

	for (i = 0; i < nb_words; i++)
	{
		int found = 0;

		for (j = 0; j < nb_words; j++)
		{
			if (copy[j] && strncmp(s + i * word_len, copy[j], word_len) == 0)
			{
				copy[j] = NULL;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(copy);
			return (0);
		}
	}

	free(copy);
	return (1);
}

/**
 * find_substring - finds all starting indices of substrings
 *                  that are concatenations of words
 * @s: input string
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to store number of results
 *
 * Return: array of indices or NULL
 */
int *find_substring(char const *s, char const **words,
	int nb_words, int *n)
{
	int s_len, word_len, sub_len, i, count = 0;
	int *indices;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	*n = 0;
	s_len = strlen(s);
	word_len = strlen(words[0]);
	sub_len = word_len * nb_words;

	if (s_len < sub_len)
		return (NULL);

	indices = malloc(sizeof(int) * (s_len - sub_len + 1));
	if (!indices)
		return (NULL);

	for (i = 0; i <= s_len - sub_len; i++)
	{
		if (check_match(s + i, words, nb_words, word_len))
			indices[count++] = i;
	}

	if (count == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = count;
	return (indices);
}

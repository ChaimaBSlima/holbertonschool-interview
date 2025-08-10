#include "regex.h"

/**
* regex_match - recursive regular expression matcher that supports:
* @s: input string to match
* @p: pattern string that may contain:
* Return:  1 if pattern matches entire string, 0 otherwise.
*/
int regex_match(char const *s, char const *p)
{
	/* If pattern is empty, match only if string is also empty */
	if (*p == '\0')
		return (*s == '\0');

	/* Check if first character matches (s must not be at end) */
	int first_match = (*s != '\0') && (*p == *s || *p == '.');

	if (p[1] == '*')
	{
		if (regex_match(s, p + 2))
			return (1);
		if (first_match && regex_match(s + 1, p))
			return (1);
		return (0);
	}

	/* Otherwise, consume one char from both if first matches */
	if (first_match)
		return (regex_match(s + 1, p + 1));

	return (0);
}

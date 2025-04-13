#include "search.h"
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *express_node;

	if (!list)
		return (NULL);

	node = list;
	express_node = node->express;

	/* Traverse the express lane to find the block where the value could be */
	while (express_node && express_node->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express_node->index, express_node->n);
		node = express_node;
		express_node = express_node->express;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		 node->index, express_node ? express_node->index : node->index);

	/* Now linear search between node and express_node */
	while (node && node->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}

	return (NULL);
}

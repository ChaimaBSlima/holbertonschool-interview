#include "binary_trees.h"

/**
* heapify_up - Restores the max heap property by swapping with parent
* @node: Pointer to the newly inserted node
*
* Return: Pointer to the node after heapification
*/
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
* find_insertion_point - Performs a level-order traversal to find
* the correct insertion point in the heap.
* @root: Pointer to the root of the heap
*
* Return: Pointer to the node where insertion can happen
*/
heap_t *find_insertion_point(heap_t *root)
{
	heap_t *insert_node;
	heap_t *queue[1024];
	int head = 0, tail = 0;

	if (!root)
		return (NULL);

	/* Use a queue for level-order traversal */
	queue[tail++] = root;
	while (head < tail)
	{
		insert_node = queue[head++];

		if (!insert_node->left)
			return (insert_node);
		if (!insert_node->right)
			return (insert_node);

		/* Add children to the queue */
		queue[tail++] = insert_node->left;
		queue[tail++] = insert_node->right;
	}

	return (NULL);
}

/**
* heap_insert - Inserts a value into a Max Binary Heap
* @root: Double pointer to the root node of the Heap
* @value: Value to store in the node to be inserted
*
* Return: Pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	heap_t *insertion_point;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	insertion_point = find_insertion_point(*root);

	if (!insertion_point->left)
	{
		insertion_point->left = binary_tree_node(insertion_point, value);
		new_node = insertion_point->left;
	}
	else
	{
		insertion_point->right = binary_tree_node(insertion_point, value);
		new_node = insertion_point->right;
	}

	return (heapify_up(new_node));
}

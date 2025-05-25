#include "binary_trees.h"

/**
 * swap - swaps two node values
 * @a: first node
 * @b: second node
 */
void swap(heap_t *a, heap_t *b)
{
	int tmp = a->n;

	a->n = b->n;
	b->n = tmp;
}

/**
 * heapify_down - restores the Max Heap property from a
 * node downward
 * @root: pointer to the root node
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;

	while (1)
	{
		heap_t *left = root->left;
		heap_t *right = root->right;

		if (left && left->n > largest->n)
			largest = left;
		if (right && right->n > largest->n)
			largest = right;

		if (largest == root)
			break;

		swap(root, largest);
		root = largest;
	}
}

/**
 * get_last_node - returns the last node in a level-order traversal
 * @root: root node
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *last = NULL;
	heap_t **queue;
	size_t i = 0, j = 0, size = 1024;

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[j++] = root;
	while (i < j)
	{
		last = queue[i];
		if (last->left)
			queue[j++] = last->left;
		if (last->right)
			queue[j++] = last->right;
		i++;
	}
	free(queue);
	return (last);
}

/**
 * heap_extract - extracts the root of a Max Binary Heap
 * @root: double pointer to the root node
 * Return: value of the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root);
	if (!last)
		return (0);

	(*root)->n = last->n;

	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;
	free(last);

	heapify_down(*root);
	return (value);
}

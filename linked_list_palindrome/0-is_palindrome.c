#include "lists.h"

/**
* reverse_list - Reverses a linked list.
* @head: Double pointer to the head of the list.
* Return: Pointer to the new head of the reversed list.
*/
listint_t *reverse_list(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL, *current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return (*head);
}

/**
* is_palindrome - Checks if a singly linked list is a palindrome.
* @head: Double pointer to the head of the linked list.
* Return: 1 if it's a palindrome, 0 otherwise.
*/
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	listint_t *slow = *head, *fast = *head, *first_half, *second_half;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	second_half = reverse_list(&slow);

	first_half = *head;
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
			return (0);
		first_half = first_half->next;
		second_half = second_half->next;
	}

	return (1);
}

#include "sort.h"

/**
 * swapNodes - swaps 2 nodes in a listint_t doubly linked list
 * @head: pointer to the head of the list
 * @first: pointer first node to be swapped
 * @second: pointer to second node to be swapped
 */
void swapNodes(listint_t **head, listint_t *first, listint_t *second)
{
	if (first->next != NULL)
		first->next->prev = second;

	second->next = first->next;
	first->next = second;
	first->prev = second->prev;

	if (second->prev == NULL)
		*head = first;
	else
		second->prev->next = first;

	second->prev = first;

	print_list(*head);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers,
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *node = *list;

	if (list == NULL || node->next == NULL)
		return;

	while (!sorted)
	{
		sorted = 1;
		while (node)
		{
			if (node->prev && node->n < node->prev->n)
			{
				sorted = 0;
				swapNodes(list, node, node->prev);
			}
			if (!node->next)
				break;
			node = node->next;
		}
		while (node->prev)
		{
			if (node->next && node->n > node->next->n)
			{
				sorted = 0;
				swapNodes(list, node->next, node);
			}
			node = node->prev;
		}
	}
}

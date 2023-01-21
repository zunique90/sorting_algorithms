#include "sort.h"

/**
 * swap_nodes - swaps 2 nodes in a listint_t doubly linked list
 * @head: pointer to the head of the list
 * @node1: pointer to the first node to swap
 * @node2: the second node
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers,
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the had of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *temp, *key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		key = i->prev;
		while (key != NULL && i->n < key->n)
		{
			swap_nodes(list, &key, i);
			print_list((const listint_t *)*list);
		}
	}
}

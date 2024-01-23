#include "sort.h"

/**
 * swap - swaps the two node places
 * @node1: the node being swabed with node2
 * @node2: the node being swaped with node1
 * @list: the list of nodes to print after the swap
 */
void swap(listint_t *node1, listint_t *node2, listint_t *list)
{
	int *temp = (int *)&node2->n;
	int t = *temp;

	*temp = node1->n;
	temp = (int *)&node1->n;
	*temp = t;
	print_list(list);
}
/**
 * insertion_sort_list - sorts the list using insertion algorithm
 * @list: the list being sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *my_list, *front, *back, *temp;

	if (list)
	{
		my_list = *list;
		front = my_list;
		while (front)
		{
			back = front;
			while (back)
			{
				temp = back->prev;
				if (!temp)
					break;
				if (back->n < temp->n)
					swap(back, temp, my_list);
				back = back->prev;
			}
			front = front->next;
		}
	}
}

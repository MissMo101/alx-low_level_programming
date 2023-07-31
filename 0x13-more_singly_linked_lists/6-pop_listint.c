#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint -  deletes the head node of a listint_t linked list.
 * @head: pointer to the pointer of the head of the list.
 * Return: The data(n) of the deleted head node,
 * or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	data = (*head)->n;
	*head = (*head)->next;
	free(temp);

	return (data);
}

#include "monty.h"

/**
* enable_queue_mode - function that prints the top of the queue
* @head: head of queue
* @counter: line count
*
* Return: nothing
*/
void enable_queue_mode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
* add_node_to_tail - function that add node to the tail the queue
* @n: new value
* @head: head of the queue
*
* Return: nothing
*/
void add_node_to_tail(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}


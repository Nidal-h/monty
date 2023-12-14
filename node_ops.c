#include "monty.h"

/**
* add_node_stack - function that adds node to the head stack
* @head: head of the stack
* @n: new value
*
* Return: nothing
*/
void add_node_stack(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}


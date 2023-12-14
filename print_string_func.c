#include "monty.h"

/**
* print_str_stack - function that prints the string starting at the top of the stack,
* followed by a new
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void print_str_stack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}


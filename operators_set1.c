#include "monty.h"

/**
* add_stack - function that adds node to the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void add_stack(stack_t **head, unsigned int counter)
{
	int i, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			freeStack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node_stack(head, i);
	else
		add_queue_stack(head, i);
}


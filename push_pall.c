#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Return: void
 */ 
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int n;

	if (arg == NULL || _isdigit(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (*stack == NULL)
	{
		*stack = create_node(n);
	}
	else
	{
		add_node(stack, n);
	}
}

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

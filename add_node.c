#include "monty.h"

/**
 * add_node - adds a new node to the top of the stack
 * @stack: double pointer to the top of the stack
 * @n: value of the new node
 */
void add_node(stack_t **stack, int n)
{
	stack_t *node;

	node = create_node(n);
	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
}

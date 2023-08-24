#include "monty.h"

/**
 * create_node - creates a new node
 * @n: value of the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

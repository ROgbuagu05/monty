#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * queue_node - adds a node to a stack_t stack in queue mode
 * @stack: pointer to head of stack
 * @n: number of the node
 * Return: newly created node, if memory allocation fails,
 * the function will return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current;

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	current = *stack;
	while (current->next)
		current = current->next;

	new->prev = current;
	current->next = new;

	return (new);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: pointer to head of stack
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t c = 0;

	if (!stack)
	{
		return (0);
	}

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}
	return (c);
}

#include "monty.h"
/**
 * free_stack - frees stack_t list
 * @stack: pointer to head of stack
 */
void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

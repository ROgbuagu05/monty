#include "monty.h"
/**
 * pall - prints the values on stack
 * @stack: pointer to head of stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d ", current->n);
		current = current->next;
	}
}

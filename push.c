#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (glob.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!is_number(glob.arg))
	{
		fprintf(stderr, "L%d: invalid integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(glob.arg);
	if (add_node(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * is_number - checks if a string is a number or not
 * @str: string to check
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

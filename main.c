#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"
/**
 * error_usage - prints usage message and exits
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: ammount of args
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (getline(&buffer, &buf_len, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_number;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_number;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_number);
		line_number++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}

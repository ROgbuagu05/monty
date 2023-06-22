#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void file_error(const char *argv);
void error_usage(void);
int status = 0;

/**
 * main - entry point
 * @argv: arguments passed to a program
 * @argc: argument count
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	global.data_struct = 1;
	if (argc != 2)
	{
		error_usage();
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		file_error(argv[1]);
	}

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
		{
			break;
		}
		if (*buffer == '\n')
		{
			line_number++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_number++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		line_number++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
/**
 * file_error - prints file error message and exits
 * @argv: argv given by main()
 * Description: print msg if  not possible to open the file
 * Return: nothing
 */
void file_error(const char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
/**
 * error_usage - prints usage message and exits
 * Descriptio: if user does not give any file or
 * more than one argument to your program
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

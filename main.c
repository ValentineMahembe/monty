#include "monty.h"

/**
 * parse_arguments - parses command line arguments
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: pointer to input file name
 */
char *parse_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (argv[1]);
}

/**
 * open_file - opens an input file
 * @file_name: name of the input file
 *
 * Return: pointer to the opened file
 */
FILE *open_file(char *file_name)
{
	FILE *fp;

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fp);
}

/**
 * process_line - processes a line from the input file
 * @line: line to process
 * @line_number: line number
 * @stack: double pointer to the top of the stack
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;
	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			break;
		}
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	parse_arguments(argc, argv);
	fp = open_file(argv[1]);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		process_line(line, line_number, &stack);
	}
	free(line);
	fclose(fp);
	return (0);
}

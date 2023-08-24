#include "monty.h"
#include <stdio.h>

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
	char *line = NULL, *opcode;
	size_t len = 0;
	ssize_t read;
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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp  == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		for (i = 0; opcodes[i].opcode; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unkown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(fp);
	return (0);
}

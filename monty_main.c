#include "monty.h"
/**
 * main - Handles Monty function
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: SUCCESS.
 **/
int main(int argc, char *argv[])
{
	stack_t *MHead = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	MOpenFile(argv[1], &MHead);
	exit(EXIT_SUCCESS);
}
/**
 * MOpenFile - Opens the files.
 * @FileName: Character for the file's name.
 * @stack: Structure for doubly linked list.
 * Return: Exit Success.
 **/
int MOpenFile(char *FileName, stack_t **stack)
{
	char *Line = NULL;
	size_t LEN;
	FILE *FD;
	char *CMD;
	unsigned int line_number = 0;

	if (!FileName)
	{
		fprintf(stderr, "Error: Can't open file %s\n", FileName);
		exit(EXIT_FAILURE);
	}
	FD = fopen(FileName, "r");
	if (FD == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", FileName);
		exit(EXIT_FAILURE);
	}
	while (getline(&Line, &LEN, FD) != EOF)
	{
		CMD = strtok(Line, " \n\t\r$");
		line_number++;
		if (CMD)
			MParseCMD(stack, CMD, line_number);
	}
	fclose(FD);
	free(Line);
	freelist(*stack);
	return (EXIT_SUCCESS);
}
/**
 * MParseCMD - Parses lines and searches commands
 * @stack: First Node
 * @OP: Monty's commands
 * @line_number: Number of lines.
 **/
void MParseCMD(stack_t **stack, char *OP, unsigned int line_number)
{
	int I;
	instruction_t COM[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (I = 0; COM[I].opcode; I++)
	{
		if (strcmp(OP, COM[I].opcode) == 0)
		{
			COM[I].f(stack, line_number);
			return;
		}
	}

	if (strlen(OP) != 0 && OP[0] != '#')
	{
		fprintf(stderr, "L%i: unkown instruction %s\n", line_number, OP);
		freelist(*stack);
		exit(EXIT_FAILURE);
	}
}

#include "monty.h"

/**
 * push - adds a new element to the stack.
 * @stack: doubly linked list que nos pasan.
 * @line_number: El valor que va dentro del node.
 *
 * Return: el nuevo node que creamos (new_head).
 **/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *MNewHead;
	char *OP;
	char *EndPTR;
	int NUM;

	MNewHead = malloc(sizeof(stack_t));
	if (MNewHead == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freelist(MNewHead);
		freelist(*stack);
		exit(EXIT_FAILURE);
	}

	OP = strtok(NULL, " \n$");

	if (OP != NULL)
	{
		NUM = strtol(OP, &EndPTR, 10);
	}

	MNewHead->n = NUM;
	MNewHead->prev = NULL;

	if (isdigit(MNewHead->n))
	{
		fprintf(stdout, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	MNewHead->next = *stack;

	*stack = MNewHead;
}

/**
 * pall - prints all elements of the stack
 * @stack: stack that needs to be printed
 * @line_number: unused variable.
 *
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *Element;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	Element = *stack;

	while (Element != NULL)
	{
		fprintf(stdout, "%i\n", Element->n);
		Element = Element->next;
	}
}

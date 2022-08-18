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
	stack_t *new_head;
	char *OP; /*parametro del push*/
	char *endptr;
	int num;

	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freedlist(new_head);
		freedlist(*stack);
		exit(EXIT_FAILURE);
	}


	OP = strtok(NULL, " \n$");

	if (OP != NULL)
	{
		num = strtol(OP, &endptr, 10);
	}

	new_head->n = num;
	new_head->prev = NULL;

	if (isdigit(new_head->n))
	{
		fprintf(stderr "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_head->next = *stack;

	*stack = new_head;
}

/**
 * pall - prints all elements of the stack
 * @stack: stack that needs to be printed
 * @line_number: unused variable.
 *
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	element = *stack;

	while (element != NULL)
	{
		printf("%i\n", element->n);
		element = element->next;
	}
}

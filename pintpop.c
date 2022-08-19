#include "monty.h"
/**
 * pint - prints a value at the top of the stack
 * @stack: doubly linked list
 * @Value: ...
 *
 **/
void pint(stack_t **stack, unsigned int Value)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", value);
			exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: head of the doubly linked list
 * @Value: ...
 *
 **/
void pop(stack_t **stack, unsigned int Value)
{
	stack_t  *TMP;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", Value);
		freedlist(*stack);
		exit(EXIT_FAILURE);
	}
	TMP = *stack;
		(*stack) = TMP->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(TMP);
}

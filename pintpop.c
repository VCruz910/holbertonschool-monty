#include "monty.h"
/**
 * pint - Prints a value at the top of the stack
 * @stack: doubly linked list
 * @Val: ...
 *
 **/
void pint(stack_t **stack, unsigned int Val)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%i: can't pint, stack empty\n", Val);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - Removes the top element of the stack
 * @stack: Head of the doubly linked list
 * @Val: ...
 *
 **/
void pop(stack_t **stack, unsigned int Val)
{
	stack_t  *TMP;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", Val);
		freelist(*stack);
		exit(EXIT_FAILURE);
	}
	TMP = *stack;
	(*stack) = TMP->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(TMP);
}

#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Head of the list.
 * @Val: Value of the input
 **/
void swap(stack_t **stack, unsigned int Val)
{
	stack_t *TMP;
	(void)Val;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", Val);
		exit(EXIT_FAILURE);
	}
	TMP = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = TMP->next;
	TMP->prev = NULL;
	(*stack)->prev = TMP;
	if (TMP->next)
	{
		TMP->next->prev = *stack;
	}
	TMP->next = *stack;
	(*stack) = (*stack)->prev;
}

/**
 * add - Adds two top elements to the stack.
 * @stack: Head of the list.
 * @Val: Value of the input.
 **/
void add(stack_t **stack, unsigned int Val)
{
	int TMP;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", Val);
		exit(EXIT_FAILURE);
	}
	TMP = (*stack)->n;
	pop(stack, Val);
	(*stack)->n += TMP;
}

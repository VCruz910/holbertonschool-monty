#include "monty.h"
/**
 * freelist - Frees a doubly linked list.
 * @MHead: Beginning of the list.
 **/
void freelist(stack_t *MHead)
{
	stack_t *TMP;

	while (MHead != NULL)
	{
		TMP = MHead;
		MHead = MHead->next;
		free(TMP);
	}
	free(MHead);
}

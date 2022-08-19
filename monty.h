#ifndef _MONTY_
#define _MONTY_

/*Libraries*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/*Structure Data*/
/*-Stack Structure Data*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/*-Instruction Structure Data*/
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*-Global Variable Structure Data*/
/**
 * struct GlobVar - Holds the input FILEstream and buffer.
 * @InputF: FILEstream's input.
 * @TMP: buffer to save line input.
 * @Mode: switches between queue and stack modes.
 */
struct GlobVar
{
	FILE *InputF;
	char *TMP;
	int Mode;
};

extern struct GlobVar GV;

/*Prototypes*/

/*-Monty_Main-*/
int MOpenFile(char *FileName, stack_t **stack);
void MParseCMD(stack_t **stack, char *OP, unsigned int LineNum);

/*-MSwapAndAdd-*/
void swap(stack_t **stack, unsigned int Val);
void add(stack_t **stack, unsigned int Val);

/*-pushpall-*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/*-pintpop-*/
void pint(stack_t **stack, unsigned int Val);
void pop(stack_t **stack, unsigned int Val);

/*-nop-*/
void nop(stack_t **stack, unsigned int Val);

/*-MFreeList-*/
void freelist(stack_t *MHead);

#endif

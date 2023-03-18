#include "include/stack.h"
#include <stdio.h>

struct cStack
{
    int size;
    int qtd_itens;
    int *itens;
};

int cStackCreate(cStack *stack, int size)
{
    stack->size = size;
    stack->qtd_itens = 0;
    stack->itens = (int *)malloc(stack->size * sizeof(int));

    return 0;
}

void cStackInsert()
{
}

int cStackTop()
{
}

void cStackPop()
{
}
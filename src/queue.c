#include "include/queue.h"
#include <stdio.h>

struct cQueue
{
    int size;
    int qtd_itens;
    int *itens;
    int first_item;
    int last_item;
};

int cQueueCreate(cQueue *queue, int size)
{
    queue->size = size;
    queue->qtd_itens = 0;
    queue->first_item = -1;
    queue->last_item = -1;
    queue->itens = (int *)malloc(queue->size * sizeof(int));

    return 0;
}

int cQueueisEmpty(cQueue queue)
{
    return (queue.qtd_itens == 0);
}

int cQueueisFull(cQueue queue)
{
    return (queue.qtd_itens == queue.size);
}

void cShowQueue(cQueue queue)
{
    printf("%s\n", cQueue_TAG);

    for (int i = 0, index = queue.first_item; i < queue.qtd_itens; i++)
    {
        printf("%d ", queue.itens[index]);

        index++;

        if (index == queue.size)
        {
            index = 0;
        }
    }

    printf("\n");
}

int *cQueuetoArray(cQueue queue)
{
    int *array = (int *)malloc(queue.size * sizeof(int));

    for (int i = 0, index = queue.first_item; i < queue.qtd_itens; i++)
    {
        array[i] = queue.itens[index];

        index++;

        if (index == queue.size)
        {
            index = 0;
        }
    }
}

int cQueueFirst(cQueue queue)
{
    return queue.itens[queue.first_item];
}

int cQueuePop(cQueue *queue)
{
    if (cQueueisEmpty(*queue))
    {
        return -1;
    }

    int item = queue->itens[queue->first_item];

    queue->first_item++;

    if (queue->first_item == queue->size)
    {
        queue->first_item = 0;
    }

    queue->qtd_itens--;

    return item;
}

int cQueueInsert(cQueue *queue, int v)
{
    if (cQueueisFull(*queue))
    {
        return -1;
    }

    queue->last_item++;

    if (queue->last_item == queue->size)
    {
        queue->last_item = 0;
    }

    queue->itens[queue->last_item] = v;

    return v;
}
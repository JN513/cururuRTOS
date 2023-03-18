#ifndef __C_QUEUE_H
#define __C_QUEUE_H

const char *cQueue_TAG = "Queue: ";

typedef struct cQueue cQueue;

#endif

#include "include/cRTOS.h"
#include <stdio.h>

struct cQueue
{
    int size;
    int qtd_itens;
    int *itens;
    int first_item;
    int last_item;
};

int cQueueCreate(cQueue *queue, int size);

int cQueueisEmpty(cQueue queue);

int cQueueisFull(cQueue queue);

void cShowQueue(cQueue queue);

int *cQueuetoArray(cQueue queue);

int cQueueFirst(cQueue queue);

int cQueuePop(cQueue *queue);

int cQueueInsert(cQueue *queue, int v);
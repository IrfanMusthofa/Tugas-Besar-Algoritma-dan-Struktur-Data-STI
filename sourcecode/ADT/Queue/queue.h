/* File : queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "../../main/ADT.h"

#define NMAX 20
#define IDX_UNDEF -999

typedef struct {
    Song buffer[NMAX];
    int idxTail;
} queue;

void CreateQueue(Queue *q);


boolean isEmpty(Queue q);


boolean isFull(Queue q);


int length(Queue q);


void enqueue(Queue *q, Song val);


void dequeue(Queue *q, Song *val);


void displayQueue(Queue q);


void swapQueueElements(Queue *q, int idx1, int idx2);

#endif

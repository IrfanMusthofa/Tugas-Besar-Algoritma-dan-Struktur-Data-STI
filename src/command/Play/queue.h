/* File : queue.h */
/* Queue dengan alternatif 1 array statik rata kiri*/
#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "ADT.h"

#define NMAX 20
#define IDX_UNDEF -999


void CreateQueue(queue *q);


boolean isEmpty(queue q);


boolean isFull(queue q);


int length(queue q);


void enqueue(queue *q, Song val);


void dequeue(queue *q, Song *val);


void displayQueue(queue q);


void swapQueueElements(queue *q, int idx1, int idx2);

#endif

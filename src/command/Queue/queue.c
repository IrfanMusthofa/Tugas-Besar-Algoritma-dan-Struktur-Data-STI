/* File : queue.c */
#include "queue.h"
#include <stdio.h>

void CreateQueue(queue *q) {
    q->idxTail = IDX_UNDEF;
}

boolean isEmpty(queue q) {
    return (q.idxTail == IDX_UNDEF);
}

boolean isFull(queue q) {
    return (q.idxTail == NMAX - 1);
}

int length(queue q) {
    if (q.idxTail == IDX_UNDEF){
        return 0;
    } 
    else {
        return q.idxTail + 1;
    }
}

void enqueue(queue *q, Song val) {
    if (!isFull(*q)) {
        if (isEmpty(*q)) {
            q->idxTail = 0;
        } else {
            q->idxTail++;
        }
        q->buffer[q->idxTail] = val;
    }
}

void dequeue(queue *q, Song *val) {
    if (!isEmpty(*q)) {
        *val = q->buffer[0];
        for (int i = 0; i < q->idxTail; ++i) {
            q->buffer[i] = q->buffer[i + 1];
        }
        q->idxTail--;
    }
}

void displayQueue(queue q) {
    for (int i = 0; i <= q.idxTail; ++i) {
        if (i > 0) {
            printf(",");
        }
        printf("{%s, %s, %s}\n", q.buffer[i].namaP, q.buffer[i].namaA, q.buffer[i].namaS);
    }
}

void swapQueueElements(queue *q, int idx1, int idx2) {
    if (idx1 >= 0 && idx1 <= q->idxTail && idx2 >= 0 && idx2 <= q->idxTail && idx1 != idx2) {
        Song temp = q->buffer[idx1];
        q->buffer[idx1] = q->buffer[idx2];
        q->buffer[idx2] = temp;
    }
}
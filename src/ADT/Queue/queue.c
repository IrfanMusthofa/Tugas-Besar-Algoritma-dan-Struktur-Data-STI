/* File : queue.c */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../../main/ADT.h"

/* Membuat Queue kosong */
/* IS : queue terdefinisi */
/* FS : queue kosong, ditandai dengan index tail adalah index undef*/
void CreateQueue(queue *q) {
    q->idxTail = IDX_UNDEF;
}

/* Mengecek Queue kosong */
/* IS : queue terdefinisi */
/* FS : mengirimkan true jika kosong, false jika tidak */
boolean isEmpty(queue q) {
    return (q.idxTail == IDX_UNDEF);
}

/* Mengecek Queue penuh */
/* IS : queue terdefinisi */
/* FS : mengirimkan true jika penuh, false jika tidak */
boolean isFull(queue q) {
    return (q.idxTail == NMAX - 1);
}

/* Banyak elemen queue */
/* IS : queue terdefinisi */
/* FS : mengembalikan banyak elemen queue */
int length(queue q) {
    if (q.idxTail == IDX_UNDEF){
        return 0;
    } 
    else {
        return q.idxTail + 1;
    }
}

/* Menambahkan elemen */
/* IS : queue terdefinisi, song terdefinisi */
/* FS : elemen akan berada di akhir queue */
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

/* Mengurangi elemen */
/* IS : queue terdefinisi */
/* FS : elemen yang akan dihapus akan disimpan di val, elemen awal queue akan dihapus */
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
    
        printf("%d. %s - %s - %s\n", i+1, q.buffer[i].namaP, q.buffer[i].namaA, q.buffer[i].namaS);
    }
}

/* Menukar isi queue */
/* IS : queue terdefinisi, idx1 dan 2 juga terdefinisi */
/* FS : menukar urutan elemen idx1 dan idx2 */
void swapQueueElements(queue *q, int idx1, int idx2) {
    if (idx1 >= 0 && idx1 <= q->idxTail && idx2 >= 0 && idx2 <= q->idxTail && idx1 != idx2) {
        Song temp = q->buffer[idx1];
        q->buffer[idx1] = q->buffer[idx2];
        q->buffer[idx2] = temp;
    }
}

/* Menghapus queue pada urutan tertentu */
/* IS : queue terdefinisi, index terdefinisi */
/* FS : elemen queue pada urutan index akan terhapus */
void removeAtIndex(queue *q, int index) {
    if (index >= 0 && index <= q->idxTail) {
        for (int i = index; i < q->idxTail; i++) {
            q->buffer[i] = q->buffer[i + 1];
        }
        q->idxTail--;
    }
}

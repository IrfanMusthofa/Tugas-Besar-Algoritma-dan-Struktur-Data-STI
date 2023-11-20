/* File : queue.h */
/* Queue dengan alternatif 1 array statik rata kiri*/
#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "../../main/ADT.h"


/* Membuat Queue kosong */
/* IS : queue terdefinisi */
/* FS : queue kosong, ditandai dengan index tail adalah index undef*/
void CreateQueue(queue *q);

/* Mengecek Queue kosong */
/* IS : queue terdefinisi */
/* FS : mengirimkan true jika kosong, false jika tidak */
boolean isEmpty(queue q);

/* Mengecek Queue penuh */
/* IS : queue terdefinisi */
/* FS : mengirimkan true jika penuh, false jika tidak */
boolean isFull(queue q);

/* Banyak elemen queue */
/* IS : queue terdefinisi */
/* FS : mengembalikan banyak elemen queue */
int length(queue q);

/* Menambahkan elemen */
/* IS : queue terdefinisi, song terdefinisi */
/* FS : elemen akan berada di akhir queue */
void enqueue(queue *q, Song val);

/* Mengurangi elemen */
/* IS : queue terdefinisi */
/* FS : elemen yang akan dihapus akan disimpan di val, elemen awal queue akan dihapus */
void dequeue(queue *q, Song *val);

/* Menampilkan isi queue */
/* IS : queue terdefinisi */
/* FS : menampilkan elemen yang ada di queue */
void displayQueue(queue q);

/* Menukar isi queue */
/* IS : queue terdefinisi, idx1 dan 2 juga terdefinisi */
/* FS : menukar urutan elemen idx1 dan idx2 */
void swapQueueElements(queue *q, int idx1, int idx2);

/* Menghapus queue pada urutan tertentu */
/* IS : queue terdefinisi, index terdefinisi */
/* FS : elemen queue pada urutan index akan terhapus */
void removeAtIndex(queue *q, int index) ;

#endif

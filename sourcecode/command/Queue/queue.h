/* File : queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "ADT.h"

#define NMAX 100

void CreateQueue(queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

boolean isEmpty(queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */

int length(queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

void enqueue(queue *q, Song val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru. */

void dequeue(queue *q, Song *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S. q mungkin kosong */

void displayQueue(queue q);


void swapQueueElements(queue *q, Song song1, Song song2);

#endif

#ifndef __queue__
#define __queue__

#include "../../main/ADT.h"
#include "../../ADT/Queue/queue.h"
#include <stdio.h>
#include "../../ADT/Playlist/playlist.h"
/* Menambahkan lagu pada queue */
/* IS: queue, listpenyanyi, mapalbum, set song terdefinisi */
/* FS: lagu yang dipilih akan ditambahkan ke queue*/
void queuelagu(queue* currentqueue, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu,boolean* mutarplaylist,valuetype namaPl, ArrayDinPlaylist listpl);

/* Menambahkan lagu playlist pada queue */
/* IS: queue, arraydinplaylist terdefinisi */
/* FS: playlist yang dipilih, lagunya akan ditambahkan ke queue*/
void queueplaylist(ArrayDinPlaylist playlist, queue* currentqueue,valuetype *namaPl,boolean* mutarplaylist, CurrentSong cs);

/* Menukar queue */
/* IS: queue, indeks terdefinisi */
/* FS: queue pada urutan indeks 1,2 akan ditukar apabila valid */
void swapqueue(int indeks1, int indeks2, queue *currentqueue);

/* Menghapuskan queue pada urutan tertentu */
/* IS: queue, indeks terdefinisi */
/* FS: queue pada urutan indeks akan terhapus apabila valid */
// ini indeks yang dimasukkan dari command, jadi hitungan kita 1,2,3..
void removequeue(int indeks, queue* currentqueue);

/*Mengkosongkan isi queue*/
void clearqueue(queue *currentqueue);

#endif

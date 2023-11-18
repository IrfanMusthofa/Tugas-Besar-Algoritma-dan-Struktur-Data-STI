#ifndef __queue__
#define __queue__

#include "ADT.h"
#include "queue.h"
#include <stdio.h>

IDs idpenyanyi(char* penyanyi, ListPenyanyi daftarpenyanyi);

IDs idalbum(char* album, MapAlbum daftaralbum); 

void queuelagu(Queue currentqueue, ListPenyanyi penyanyi, MapAlbum map, Song lagu);

void queueplaylist();

void swapqueue(int indeks1, int indeks2, Queue *currentqueue);

void removequeue(Queue *currentqueue);

#endif
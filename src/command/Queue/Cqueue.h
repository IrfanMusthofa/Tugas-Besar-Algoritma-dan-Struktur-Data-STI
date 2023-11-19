#ifndef __queue__
#define __queue__

#include "../../main/ADT.h"
#include "../../ADT/Queue/queue.h"
#include <stdio.h>

void queuelagu(queue* currentqueue, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu);

void queueplaylist(ArrayDinPlaylist playlist, queue* currentqueue);

void swapqueue(int indeks1, int indeks2, queue *currentqueue);

void removequeue(int indeks, queue* currentqueue);

void clearqueue(queue *currentqueue);

#endif

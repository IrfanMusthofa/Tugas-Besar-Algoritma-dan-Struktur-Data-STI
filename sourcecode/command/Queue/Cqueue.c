#include "ADT.h"
#include "cqueue.h"
#include "queue.h"
#include <stdio.h>

void queuelagu(queue currentqueue, ListPenyanyi penyanyi, MapAlbum map, Song lagu){
    
}

void queueplaylist(){

}

void swapqueue(int indeks1, int indeks2, queue *currentqueue){
    swapQueueElements(currentqueue, currentqueue->buffer[indeks1 + 1], currentqueue->buffer[indeks2 + 1]);
    // print (Lagu “Kokoro wo Komete” berhasil ditukar dengan “Mirror”)
    // print (Lagu dengan urutan ke 80 tidak terdapat dalam queue!)
}

void removequeue(queue *currentqueue){
    CreateQueue(currentqueue);
}


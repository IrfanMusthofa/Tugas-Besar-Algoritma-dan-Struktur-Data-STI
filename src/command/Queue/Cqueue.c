#include "Cqueue.h"
#include <stdio.h>
#include "../Pick/pick.h"
#include "boolean.h"
#include "../../main/ADT.h"
#include "../../ADT/Queue/queue.h"

void queuelagu(queue* currentqueue, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu){
    listp(penyanyi);
    valuetype pickp = pickpenyanyi(penyanyi); int idx;
    listalbum(penyanyi, map, pickp, &idx);
    valuetype picka = pickalbum(map, idx);
    ListStatic L = MakeListStatis();
    listlagu(map, lagu, picka, &L, pickp);
    valuetype pickl = picklagu(L);

    Song pilihan;
    pilihan.namaA = picka;
    pilihan.namaP = pickp;
    pilihan.namaS = pickl;

    enqueue(currentqueue, pilihan);

    printf("Berhasil menambahkan lagu “%s” oleh “%s” ke queue.\n", pickl, picka);
}

void queueplaylist(ArrayDinPlaylist playlist, queue* currentqueue){
    int pilihan = pickplaylist(playlist); address P = playlist.playlist[pilihan].First;
    while (P != NULL){
        enqueue(currentqueue, P->info);
        P = P->next;
    }
    printf("Berhasil menambahkan playlist “%s” ke queue.", playlist.playlist[pilihan].namaPlaylist);
}

void swapqueue(int indeks1, int indeks2, queue *currentqueue){
    if ((indeks1 - 1 >= 0) && (indeks1 - 1 <= currentqueue->idxTail) && (indeks2 - 1 >= 0) && (indeks2 - 1 <= currentqueue->idxTail) && (indeks1 != indeks2)){
        swapQueueElements(currentqueue, (indeks1-1), (indeks2-1));
        printf("Lagu “%s” berhasil ditukar dengan “%s”\n", currentqueue->buffer[indeks1 - 1].namaS, currentqueue->buffer[indeks2 - 1].namaS);
    }
    else {
        if (indeks1 - 1 > currentqueue->idxTail && indeks2 - 1 > currentqueue->idxTail) {
            printf("Lagu dengan urutan ke %d dan ke %d tidak terdapat dalam queue!\n", indeks1, indeks2);
        } 
        else if (((indeks1 - 1) > currentqueue->idxTail) || (indeks1 - 1) < 0){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", indeks1);
        }
        else if (((indeks2 - 1) > currentqueue->idxTail) || (indeks2 - 1 < 0)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", indeks2);
        }   
        else {
            printf("Lagu dengan urutan ke %d dan ke %d tidak terdapat dalam queue!\n", indeks1, indeks2);
        }
    }
}

void removequeue(queue *currentqueue){
    CreateQueue(currentqueue);
    printf("Queue berhasil dikosongkan.\n");
}


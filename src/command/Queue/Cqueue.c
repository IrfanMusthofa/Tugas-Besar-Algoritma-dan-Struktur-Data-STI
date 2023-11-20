#include "Cqueue.h"
#include <stdio.h>
#include "../Pick/pick.h"
#include "boolean.h"
#include "../../main/ADT.h"
#include "../../ADT/Queue/queue.h"

/* Menambahkan lagu pada queue */
/* IS: queue, listpenyanyi, mapalbum, set song terdefinisi */
/* FS: lagu yang dipilih akan ditambahkan ke queue*/
void queuelagu(queue* currentqueue, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu,boolean* mutarplaylist){
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

    *mutarplaylist = false;
    printf("Berhasil menambahkan lagu '%s' oleh '%s' ke queue.\n", pickl, picka);
}

/* Menambahkan lagu playlist pada queue */
/* IS: queue, arraydinplaylist terdefinisi */
/* FS: playlist yang dipilih, lagunya akan ditambahkan ke queue*/
void queueplaylist(ArrayDinPlaylist playlist, queue* currentqueue,valuetype *namaPl,boolean* mutarplaylist){
    int pilihan = pickplaylist(playlist); address P = playlist.playlist[pilihan].First;
    while (P != NULL){
        enqueue(currentqueue, P->info);
        P = P->next;
    }
    if (!isEmpty(*currentqueue)){
        *mutarplaylist = false;
    }
    else{
        *namaPl = playlist.playlist[pilihan].namaPlaylist;
        *mutarplaylist = true;
    }
    printf("Berhasil menambahkan playlist '%s' ke queue.\n", playlist.playlist[pilihan].namaPlaylist);
}

/* Menukar queue */
/* IS: queue, indeks terdefinisi */
/* FS: queue pada urutan indeks 1,2 akan ditukar apabila valid */
void swapqueue(int indeks1, int indeks2, queue *currentqueue, boolean* mutarplaylist){
    if ((indeks1 - 1 >= 0) && (indeks1 - 1 <= currentqueue->idxTail) && (indeks2 - 1 >= 0) && (indeks2 - 1 <= currentqueue->idxTail) && (indeks1 != indeks2)){
        swapQueueElements(currentqueue, (indeks1-1), (indeks2-1));
        *mutarplaylist = false;
        printf("Lagu '%s' berhasil ditukar dengan '%s'\n", currentqueue->buffer[indeks1 - 1].namaS, currentqueue->buffer[indeks2 - 1].namaS);
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

/* Menghapuskan queue pada urutan tertentu */
/* IS: queue, indeks terdefinisi */
/* FS: queue pada urutan indeks akan terhapus apabila valid */
// ini indeks yang dimasukkan dari command, jadi hitungan kita 1,2,3..
void removequeue(int indeks, queue* currentqueue, boolean* mutarplaylist){
    if ((indeks - 1) >= 0 && (indeks - 1) <= currentqueue->idxTail){
        Song removed = currentqueue->buffer[indeks - 1];
        removeAtIndex(currentqueue, indeks - 1);
        *mutarplaylist = false;
        printf("Lagu '%s' oleh '%s' telah dihapus dari queue!\n", removed.namaS, removed.namaP);
    }
    else {
        printf("Lagu dengan urutan ke %d tidak ada.\n", indeks);
    }
}

/*Mengkosongkan isi queue*/
void clearqueue(queue *currentqueue, boolean* mutarplaylist){
    CreateQueue(currentqueue);
    *mutarplaylist = false;
    printf("Queue berhasil dikosongkan.\n");
}


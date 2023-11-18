#include "play.h"
#include <stdio.h>

void playsong(CurrentSong *nowplay, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu, queue *currentqueue, Stack *previous){
    listp(penyanyi);
    valuetype pickp = pickpenyanyi(penyanyi); int idx;
    listalbum(penyanyi, map, pickp, &idx);
    valuetype picka = pickalbum(map, idx);
    ListStatic L = MakeListStatis();
    listlagu(map, lagu, picka, &L);
    valuetype pickl = picklagu(L);

    nowplay->NamaA = picka;
    nowplay->NamaP = pickp;
    nowplay->NamaS = pickl;

    CreateQueue(currentqueue);
    CreateEmpty(previous);

    previous->T[0].namaA = nowplay->NamaA;
    previous->T[0].namaP = nowplay->NamaP;
    previous->T[0].namaS = nowplay->NamaS;

    printf("Memutar lagu “%s” oleh %s.", nowplay->NamaS, nowplay->NamaP);
}

void playplaylist(CurrentSong *nowplay, ArrayDinPlaylist playlist, queue *currentqueue, Stack *previous){
    int pilihan = pickplaylist(playlist); address P = playlist.playlist[pilihan].First;
    nowplay->NamaS = playlist.playlist[0].First->info.namaS;
    nowplay->NamaP = playlist.playlist[0].First->info.namaP;
    nowplay->NamaA = playlist.playlist[0].First->info.namaA;

    CreateQueue(currentqueue);

    P = P->next;
    while (P != NULL){
        enqueue(currentqueue, P->info);
        P = P->next;
    }

    CreateEmpty(previous);

    previous->T[0].namaA = nowplay->NamaA;
    previous->T[0].namaP = nowplay->NamaP;
    previous->T[0].namaS = nowplay->NamaS;

    printf("Memutar playlist “%s”.", nowplay->NamaA);
}
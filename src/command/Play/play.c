#include "play.h"
#include <stdio.h>
#include "../../main/ADT.h"

/* Memainkan lagu */
/* IS: CurrentSong, ListPenyanyi, MapAlbum, Setsong, Queue, dan Stack previous terdefinisi */
/* FS: currentsong berisi lagu yang dimasukkan, stack dan queue kosong*/
void playsong(CurrentSong *nowplay, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu, queue *currentqueue, Stack *previous){
    listp(penyanyi);
    valuetype pickp = pickpenyanyi(penyanyi); 
    int idx;
    listalbum(penyanyi, map, pickp, &idx);
    valuetype picka = pickalbum(map, idx);
    ListStatic L = MakeListStatis();
    listlagu(map, lagu, picka, &L, pickp);
    valuetype pickl = picklagu(L);
    //define current song
    nowplay->namaA= picka;
    nowplay->namaP = pickp;
    nowplay->namaS = pickl;
    //mengosongkan queue dan stack
    CreateQueue(currentqueue);
    CreateEmptyS(previous);

    printf("Memutar lagu '%s' oleh '%s'.\n", pickl, pickp);
}

/* Memainkan playlist */
/* IS: CurrentSong, ListPenyanyi, MapAlbum, Setsong, Queue, ArrayDinPlaylist dan Stack previous terdefinisi */
/* FS: currentsong berisi playlist lagu pertama, stack kosong, dan queue berisi lagu playlist kedua dst*/
void playplaylist(CurrentSong *nowplay, ArrayDinPlaylist playlist, queue *currentqueue, Stack *previous){
    if (IsEmptyArrayDin(playlist)){
        printf("Playlist kosong, tidak ada yang bisa dimainkan.\n");
    } else {
        int pilihan = pickplaylist(playlist); 
        address P = playlist.playlist[pilihan].First;
        nowplay->namaS = playlist.playlist[pilihan].First->info.namaS;
        nowplay->namaP = playlist.playlist[pilihan].First->info.namaP;
        nowplay->namaA = playlist.playlist[pilihan].First->info.namaA;

        CreateQueue(currentqueue);

        P = Next(P);
        while (P != NULL){
            enqueue(currentqueue, Info(P));
            P = Next(P);
        }

        CreateEmptyS(previous);

        printf("Memutar playlist '%s'.\n", playlist.playlist[pilihan].namaPlaylist);
    }
}
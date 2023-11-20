#include "status.h"
#include <stdio.h>

/* Mengecek current song dan queue */
/* IS: current song dan queue terdefinisi */
/* FS: menampilkan kondisi current song dan queue */
void status(CurrentSong lagu, queue Q, boolean mutarplaylist, valuetype namaplaylist)
{
    if (mutarplaylist){
        printf("\nCurrent Playlist: %s\n", namaplaylist);
    }
    char *song = "-";
    if (IsEqualString(song, lagu.namaP) && isEmpty(Q)) //gak ada current song, queue kosong
    {
        printf("\nNow Playing:\n");
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
        printf("\nQueue:\n");
        printf("Your queue is empty.\n");
    }
    else if ((!IsEqualString(song, lagu.namaP)) && isEmpty(Q)) //ada CS, gak ada queue
    {
        printf("\nNow Playing:\n");
        printf("%s - %s - %s\n", lagu.namaP, lagu.namaA, lagu.namaS);
        printf("\nQueue:\n");
        printf("Your queue is empty.\n");
    }
    else if(!(IsEqualString(song, lagu.namaP)) && !isEmpty(Q)) //ada CS, ada queue
    {
        printf("\nNow Playing:\n");
        printf("%s - %s - %s\n", lagu.namaP, lagu.namaA, lagu.namaS);
        printf("\nQueue:\n");
        displayQueue(Q);
    }
    else { // gak ada CS, ada queue
        printf("\nNow Playing:\n");
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
        printf("\nQueue:\n");
        displayQueue(Q);

    }
}
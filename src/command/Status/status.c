#include "status.h"
#include <stdio.h>

/* Mengecek current song dan queue */
/* IS: current song dan queue terdefinisi */
/* FS: menampilkan kondisi current song dan queue */
void status(CurrentSong lagu, queue Q, boolean mutarplaylist, valuetype namaplaylist)
{
    char *song = "-";
    if (IsEqualString(song, lagu.namaP) && isEmpty(Q))
    {
        printf("\nNow Playing:\n");
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
        printf("\nQueue:\n");
        printf("Your queue is empty.");
    }
    else if ((!IsEqualString(song, lagu.namaP)) && isEmpty(Q))
    {
        printf("\nNow Playing:\n");
        printf("%s - %s - %s\n", lagu.namaP, lagu.namaA, lagu.namaS);
        printf("\nQueue:\n");
        printf("Your queue is empty.");
    }
    else if(!(IsEqualString(song, lagu.namaP)) && isEmpty(Q))
    {
        //boolean mutarplaylist;
        //valuetype namaplaylist;
        if (mutarplaylist) /* true */
        {
            printf("\nCurrent Playlist: %s\n", namaplaylist);
            printf("\nNow Playing:\n");
            printf("%s - %s - %s\n", lagu.namaP, lagu.namaA, lagu.namaS);
            printf("\nQueue:\n");
            displayQueue(Q);
        }
        else{
            printf("\nNow Playing:\n");
            printf("%s - %s - %s\n", lagu.namaP, lagu.namaA, lagu.namaS);
            printf("\nQueue:\n");
            displayQueue(Q);
        }
    }
}
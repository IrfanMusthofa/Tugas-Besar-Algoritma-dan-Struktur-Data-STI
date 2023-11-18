#include "listplaylist.h"
#include <stdio.h>

void show_listplaylist(ArrayDinPlaylist P)
{
    printf("Daftar Playlist yang kamu miliki:\n");
    if(!IsEmptyArrayDin(P))
    {
        for (int i = 0;i < P.Neff; i++)
        {
            printf("%d. %s\n", i + 1, P.playlist[i].namaPlaylist);
        }
    }
    else{ //IsEmptyArrayDin(P)
        printf("Kamu tidak memiliki playlist.");
    }
    
}
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "pick.h"
#include "list.h"
#include "Cplaylist.h"
#include "playlist.h"


int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong song;
    char *file = "config.txt";
    STARTCOM(&Penyanyi,&Album,&song, file);
    // listp(Penyanyi);
    // valuetype Singer = pickpenyanyi(Penyanyi);
    // int idP;
    // listalbum(Penyanyi, Album, Singer, &idP);   
    // valuetype a = pickalbum(Album, idP);
    // ListStatic L = MakeListStatis();
    // listlagu(Album, song, a, &L);
    // valuetype l = picklagu(L);
    // printf("%s", l);
    ArrayDinPlaylist arr = MakeArrayDin();
    playlistcreate(&arr);
    playlistcreate(&arr);
    tambahalbumplaylist(Penyanyi, Album, song, &arr);
    PrintInfo(arr.playlist[0]);
    printf("\n");
    swapplaylist(&arr, 1, 2, 3);
    removeplaylist(&arr, 1, 1);
    hapusplaylist(&arr);
    PrintInfo(arr.playlist[0]);
    for (int i = 0; i < arr.Neff; i++){
        printf("%s", arr.playlist[i].namaPlaylist);
    }





    
    

    
}
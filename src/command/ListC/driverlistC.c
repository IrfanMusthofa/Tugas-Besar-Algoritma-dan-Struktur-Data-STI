#include "mesinkata.h"
#include "ADT.h"
#include "pick.h"
#include "Clist.h"
#include "Cplaylist.h"

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong song;
    char *file = "config.txt";
    STARTCOM(&Penyanyi,&Album,&song, file);
    listdefault(Penyanyi, Album, song);
    ArrayDinPlaylist arr = MakeArrayDin();
    Dlistplaylist(arr);
    playlistcreate(&arr);
    playlistcreate(&arr);
    Dlistplaylist(arr);

}
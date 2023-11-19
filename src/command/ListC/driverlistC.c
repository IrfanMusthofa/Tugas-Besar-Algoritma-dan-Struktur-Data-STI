#include "mesinkata.h"
#include "ADT.h"
#include "pick.h"
#include "Clist.h"
#include "playlist2.h"
#include "mesinkarakter.h"

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong song;
    char *file = "config.txt";
    STARTCOM(&Penyanyi,&Album,&song, file);
    listdefault(Penyanyi, Album, song);
    ArrayDinPlaylist C;
    listplaylist(C);
}
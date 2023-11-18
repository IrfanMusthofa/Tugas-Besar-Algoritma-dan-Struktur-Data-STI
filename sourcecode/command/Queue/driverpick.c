#include "ADT.h"
#include "pick.h"
#include "mesinkata.h"

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong song;
    char *file = "config.txt";

     STARTCOM(&Penyanyi,&Album,&song, file);
     listp(Penyanyi);
     
}
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "pick.h"
#include "list.h"


int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;

    SetSong Song;
    char *file = "config.txt";
    STARTCOM(&Penyanyi,&Album,&Song, file);
    listp(Penyanyi);
    valuetype Singer = pickpenyanyi(Penyanyi);
    int idP;
    listalbum(Penyanyi, Album, Singer, &idP);   
    valuetype a = pickalbum(Album, idP);
    ListStatic L = MakeList();
    listlagu(Album, Song, a, &L);
    valuetype l = picklagu(L);
    printf("%s", l);
    

    
}
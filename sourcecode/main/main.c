#include "./sourcecode/ADT/MesinKalimat/mesinkarakter.h"
#include "./sourcecode/ADT/MesinKalimat/mesinkata.h"
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong Song;
    //ID PasID;
    //MakeEmpty(&Penyanyi,&Album,&Song);
    printf(">>> ");
    char *start = "START;";
    STARTINPUTKATA();
    if (IsEqual(currentWord,start)){
        printf("starting game..\n");

        STARTCOM(&Penyanyi,&Album,&Song);

        for(int i = 0;i<Penyanyi.neff;i++){
            printf("%d. %s\n",i+1,Penyanyi.A[i]);
        }

        for(int i = 0;i<Album.count;i++){
            printf("  %d. %s\n",Album.Elements[i].IdPenyanyi,Album.Elements[i].valueAlbum);
        }

        for(int i = 0;i<Song.count;i++){
            printf("    %d. %s\n",Song.Elements[i].IdAlbum,Song.Elements[i].namaS);
        }
    }
}
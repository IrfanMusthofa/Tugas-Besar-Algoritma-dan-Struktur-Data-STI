#include "./src/mesinkarakter.h"
#include "./src/mesinkata.h"
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List Penyanyi;
    MapAlbum Album;
    MapSong Song;
    //ID PasID;
    //MakeEmpty(&Penyanyi,&Album,&Song);
    
    printf("starting game..\n");

    STARTCOM(&Penyanyi,&Album,&Song);

    for(int i = 0;i<Penyanyi.neff;i++){
        printf("%d. %s\n",i+1,Penyanyi.A[i]);
    }

    for(int i = 0;i<Album.count;i++){
        printf("  %d. %s\n",Album.Elements[i].keyAlbum+1,Album.Elements[i].valueAlbum);
    }

    for(int i = 0;i<Song.count;i++){
        printf("    %d. %s\n",Song.Elements[i].keySong+1,Song.Elements[i].valueSong);
    }
}
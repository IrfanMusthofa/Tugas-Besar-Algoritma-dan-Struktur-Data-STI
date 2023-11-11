#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "../command/Help/help.h"


int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong Song;
    //ID PasID;
    //MakeEmpty(&Penyanyi,&Album,&Song);
    printf(">>> ");
    char *start = "START;";
    char *help = "HELP;";
    STARTINPUTKATA();
    if (IsEqual(currentWord,start)){
        printf("starting game..\n");
        char *file = "./sourcecode/config/config.txt";
        STARTCOM(&Penyanyi,&Album,&Song, file);

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
    else if (IsEqual(currentWord,help)){
        help_before();
    }
}
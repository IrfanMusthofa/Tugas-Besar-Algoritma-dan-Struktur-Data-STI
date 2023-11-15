#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
//#include "../ADT/Queue/queue.h"
//#include "../ADT/Stack/stack.h"
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "../command/Help/help.h"
#include "../command/Load/load.h"

void mainafter(ListPenyanyi inpenyanyi, MapAlbum inalbum, SetSong insong, queue inqueue, Stack instack, ArrayDinPlaylist inplaylist){
    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);
    while(true){
        if (IsEqual(input,"QUIT;")){
            break;
        }
        printf("masih di dalam mainafter\n");
        printf("%s\n",input.TabWord);
        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }
    printf("mau di save?\n");
}
    

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong Song;
    queue antrian;
    Stack history;
    ArrayDinPlaylist playlist;
    MakeEmpty(&Penyanyi,&Album,&Song);


    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);
    while (true){
        if (IsEqual(input,"START;")){
            printf("starting game..\n");
            char *file = "./sourcecode/config/config.txt";
            STARTCOM(&Penyanyi,&Album,&Song, file);

            printf("Berhasil masuk kedalam aplikasi, selamat menikmati!\n");
            mainafter(Penyanyi,Album,Song,antrian,history,playlist);
            break;
        }
        else if (IsEqual(input,"HELP;")){
            help_before();
        }
        else if (IsEqual(input,"LOAD")){
            char* filename = WordToString(takeword(currentWord,2));
            printf("%s\n",filename);
        }
        else{
            printf("command tidak valid\n");
        }
        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }
}

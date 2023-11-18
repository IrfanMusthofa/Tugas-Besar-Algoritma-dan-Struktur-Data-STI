#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Stack/stack.h"
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>
#include "../command/Help/help.h"
//#include "../command/Load/load.h"
#include "../ADT/playlist/pick.h"

void mainafter(ListPenyanyi inpenyanyi, MapAlbum inalbum, SetSong insong, queue inqueue, Stack instack, ArrayDinPlaylist inplaylist){
    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);
    while(true){
        if (IsEqual(input,"QUIT;")){
            break;
        }
        else if (IsEqual(input,"LIST")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"DEFAULT;")){
                //listp(inpenyanyi);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){

            }
        }
        else if (IsEqual(input,"HELP;")){
            help_after();
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
    CreateEmpty(&history);
    CreateQueue(&antrian);
    playlist.Neff = 0;


    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);
    while (true){
        if (IsEqual(input,"START;")){
            printf("starting game..\n");
            char *file = "./sourcecode/config/config.txt";
            STARTCOM(&Penyanyi,&Album,&Song, file);

            for (int i = 0;i<Penyanyi.neff;i++){
                printf("%s\n", Penyanyi.A[i]);
            }
            printf("Berhasil masuk kedalam aplikasi, selamat menikmati!\n");
            mainafter(Penyanyi,Album,Song,antrian,history,playlist);
            break;
        }
        else if (IsEqual(input,"HELP;")){
            help_before();
        }
        else if (IsEqual(input,"LOAD")){
            char *input2 = commWordToString(takeword(currentWord,2));
            char *filename = ConcateChar("./sourcecode/config/",input2);
            printf("%s\n",filename);
            //panggil load;

            mainafter(Penyanyi,Album,Song,antrian,history,playlist);
            break;
        }
        else{
            printf("command tidak valid, masukkan command \"HELP;\" untuk melihat list command\n");
        }
        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }
}

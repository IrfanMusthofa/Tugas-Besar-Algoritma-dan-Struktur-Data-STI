#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

#include "../ADT/List/list.h"
#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
#include "../ADT/Playlist/playlist.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Stack/stack.h"

#include "../command/Help/help.h"
#include "../command/Load/load.h"
#include "../command/Pick/pick.h"
#include "../command/Playlist/Cplaylist.h"

void mainafter(ListPenyanyi inpenyanyi, MapAlbum inalbum, SetSong insong, queue inqueue, Stack instack, ArrayDinPlaylist inplaylist, CurrentSong incursong){
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
                //run list default
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                //run list playlist
            }
        }
        else if (IsEqual(input,"PLAYLIST")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"CREATE;")){
                playlistcreate(&inplaylist);
            }
            else if (IsEqual(nextinput,"ADD")){
                Word inputadd = takeword(currentWord,3);
                if (IsEqual(nextinput,"SONG;")){
                    tambahlaguplaylist(inpenyanyi,inalbum,insong,&inplaylist);
                }
                else if (IsEqual(nextinput,"ALBUM;")){
                    tambahalbumplaylist(inpenyanyi,inalbum,insong,&inplaylist);
                }
            }
            else if (IsEqual(nextinput,"SWAP")){
                int validasi = currentWord.Length-14;
                int IDplaylist = -1, x = -1,y=-1;
                if(validasi >= 6){
                    IDplaylist = WordToInt(takeword(currentWord,3));
                    x = WordToInt(takeword(currentWord,4));
                    y = WordToInt(takeword(currentWord,5));
                }
                printf("%s\n",takeword(currentWord,4).TabWord);
                printf("%d\n%d\n%d\n",IDplaylist,x,y);
                //swapplaylist(&inplaylist,idP,x,y);
            }
            else if (IsEqual(nextinput,"SWAP")){
                int idP = WordToInt(takeword(currentWord,3));
                int x = WordToInt(takeword(currentWord,4));
            }
        }
        else if (IsEqual(input,"HELP;")){
            help_after();
        }





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
    ArrayDinPlaylist playlist = MakeArrayDin();
    MakeEmpty(&Penyanyi,&Album,&Song);
    CreateEmptyS(&history);
    CreateQueue(&antrian);
    CurrentSong LaguSkrg;
    LaguSkrg.NamaP = "-";

    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);
    while (true){
        if (IsEqual(input,"START;")){
            printf("starting game..\n");
            char *file = "./src/config/config.txt";
            STARTCOM(&Penyanyi,&Album,&Song, file);

            for (int i = 0;i<Penyanyi.neff;i++){
                printf("%s\n", Penyanyi.A[i]);
            }
            printf("Berhasil masuk kedalam aplikasi, selamat menikmati!\n");
            mainafter(Penyanyi,Album,Song,antrian,history,playlist,LaguSkrg);
            break;
        }
        else if (IsEqual(input,"HELP;")){
            help_before();
        }
        else if (IsEqual(input,"LOAD")){
            hapustikom(&currentWord);
            char *input2 = WordToString(takeword(currentWord,2));
            char *filename = "./src/config/tesload.txt";
            printf("%s\n",filename);
            if (Checkload(filename)){
                Load(&Penyanyi,&Album,&Song,filename,&antrian,&history,&playlist,&LaguSkrg);
            }
            else{
                printf("tidak ada file dengan nama tersebut\n");
            }

            mainafter(Penyanyi,Album,Song,antrian,history,playlist,LaguSkrg);
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

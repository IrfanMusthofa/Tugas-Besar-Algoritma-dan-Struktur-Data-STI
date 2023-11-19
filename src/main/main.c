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
#include "../command/Quit/quit.h"
#include "../command/invalidcommand/invalidcommand.h"
#include "../command/Song/song.h"
#include "../command/ListC/Clist.h"
#include "../command/Play/play.h"
#include "../command/Queue/Cqueue.h"

void mainafter(ListPenyanyi inpenyanyi, MapAlbum inalbum, SetSong insong, queue inqueue, Stack instack, ArrayDinPlaylist inplaylist, CurrentSong incursong){
    // input command
    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);

    while(true){
        //quit
        if (IsEqual(input,"QUIT;")){
            break;
        }
        else if (IsEqual(input,"LIST")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"DEFAULT;")){
                listdefault(inpenyanyi,inalbum,insong);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                listplaylist(inplaylist);
            }
        }
        else if (IsEqual(input,"PLAY")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"SONG;")){
                playsong(&incursong,inpenyanyi,inalbum,insong,&inqueue,&instack);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                playplaylist(&incursong,inplaylist,&inqueue,&instack);
            }
        }
        else if (IsEqual(input,"QUEUE")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"SONG;")){
                queuelagu(&inqueue,inpenyanyi,inalbum,insong);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                queueplaylist(inplaylist,&inqueue);
            }
            else if (IsEqual(nextinput,"SWAP")){
                int validasi = currentWord.Length-11;
                hapustikom(&currentWord);
                int id1 = -99, id2 = -99;
                if (validasi>=4){
                    id1 = WordToInt(takeword(currentWord,3));
                    id2 = WordToInt(takeword(currentWord,4));
                    swapqueue(id1,id2,&inqueue);
                }
                else{
                    printf("mohon masukkan input yang sesuai\n");
                }
            }
            else if (IsEqual(nextinput,"REMOVE")){
                int validasi = currentWord.Length-13;
                hapustikom(&currentWord);
                if (validasi>=2){
                    int id = WordToInt(takeword(currentWord,3));
                    //
                }
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
                hapustikom(&currentWord);
                int IDplaylist = -99, x = -99,y=-99;
                if(validasi >= 6){
                    IDplaylist = WordToInt(takeword(currentWord,3));
                    x = WordToInt(takeword(currentWord,4));
                    y = WordToInt(takeword(currentWord,5));
                    swapplaylist(&inplaylist,IDplaylist,x,y);
                }
                printf("%s\n",takeword(currentWord,4).TabWord);
                printf("%d\n%d\n%d\n",IDplaylist,x,y);
            }
            else if (IsEqual(nextinput,"REMOVE")){
                int validasi = currentWord.Length-16;
                int IDplaylist = -99, x = -99;
                if (validasi >=4){
                    IDplaylist = WordToInt(takeword(currentWord,3));
                    x = WordToInt(takeword(currentWord,4));
                }
                removeplaylist(&inplaylist,IDplaylist,x);
            }
            else if (IsEqual(nextinput,"DELETE;")){
                hapusplaylist(&inplaylist);
            }
        }




        else if (IsEqual(input,"HELP;")){
            help_after();
        }





        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }
    quit();
}
    

void displaywayangwave(){                                                                                                                  
printf(" __   __   __   ______   __    __   ______   _______    ______         __   __   __   ______   __     __  ______  \n");
printf("/  | /  | /  | /      / /  |  /  | /      | /       / /      |       /  | /  | /  | /      / /  /   /  |/      | \n");
printf("$$ | $$ | $$ | $$$$$$  |$$ |  $$ | $$$$$$  |$$$$$$$  |/$$$$$$  |      $$ | $$ | $$ | $$$$$$  |$$    /$$//$$$$$$  |\n");
printf("$$ | $$ | $$ | /    $$ |$$ |  $$ | /    $$ |$$ |  $$ |$$ |  $$ |      $$ | $$ | $$ | /    $$ | $$  /$$/ $$    $$ |\n");
printf("$$ /_$$ /_$$ |/$$$$$$$ |$$ /__$$ |/$$$$$$$ |$$ |  $$ |$$ |__$$ |      $$ /_$$ /_$$ |/$$$$$$$ |  $$ $$/  $$$$$$$$/ \n");
printf("$$   $$   $$/ $$    $$ |$$    $$ |$$    $$ |$$ |  $$ |$$    $$ |      $$   $$   $$/ $$    $$ |   $$$/   $$       |\n");
printf(" $$$$$/$$$$/   $$$$$$$/  $$$$$$$ | $$$$$$$/ $$/   $$/  $$$$$$$ |       $$$$$/$$$$/   $$$$$$$/     $/     $$$$$$$/ \n");
printf("                        /  /__$$ |                    /  /__$$ |                                                  \n");
printf("                        $$    $$/                     $$    $$/                                                   \n");
printf("                         $$$$$$/                       $$$$$$/                                                    \n");

}

int main(){
    // inisiasi semua variabel
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong Song;
    queue antrian;
    Stack history;
    ArrayDinPlaylist playlist = MakeArrayDin();
    CurrentSong LaguSkrg;

    // kosongkan variabel
    MakeEmpty(&Penyanyi,&Album,&Song);
    CreateEmptyS(&history);
    CreateQueue(&antrian);
    LaguSkrg.namaP = "-";
    displaywayangwave();

    // input command
    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);

    while (true){
        // start
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

        // help
        else if (IsEqual(input,"HELP;")){
            help_before();
        }

        // load
        else if (IsEqual(input,"LOAD")){
            hapustikom(&currentWord);
            char *input2 = WordToString(takeword(currentWord,2));
            char *filename = ConcateChar("src/config/",input2);
            printf("%s\n",filename);
            if (Checkload(filename)){
                Load(&Penyanyi,&Album,&Song,filename,&antrian,&history,&playlist,&LaguSkrg);
                mainafter(Penyanyi,Album,Song,antrian,history,playlist,LaguSkrg);
                break;
            }
            else{
                printf("tidak ada file dengan nama tersebut\n");
            }
        }
        //invalid command
        else{
            printf("command tidak valid, masukkan command \"HELP;\" untuk melihat list command\n");
        }

        // input command
        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }
}

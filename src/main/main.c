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
#include "../command/invalidcommand/invalidcommand.h"
#include "../command/Song/song.h"
#include "../command/ListC/Clist.h"
#include "../command/Play/play.h"
#include "../command/Queue/Cqueue.h"
//#include "../command/Status/status.h"

void mainafter(ListPenyanyi inpenyanyi, MapAlbum inalbum, SetSong insong, queue inqueue, Stack instack, ArrayDinPlaylist inplaylist, CurrentSong incursong, valuetype innamaplaylist, boolean inputisplayplaylist){
    // input command
    printf(">>> ");
    STARTINPUTKATA();
    Word input = takeword(currentWord,1);

    while(true){
        //quit
        if (IsEqual(input,"QUIT;")){
            break;
        }

        //list
        else if (IsEqual(input,"LIST")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"DEFAULT;")){
                listdefault(inpenyanyi,inalbum,insong);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                listplaylist(inplaylist);
            }
        }

        //play
        else if (IsEqual(input,"PLAY")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"SONG;")){
                playsong(&incursong,inpenyanyi,inalbum,insong,&inqueue,&instack,&inputisplayplaylist);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                playplaylist(&incursong,inplaylist,&inqueue,&instack,&innamaplaylist,&inputisplayplaylist);
                printf("%s\n",innamaplaylist);
            }
        }

        //queue
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
                    removequeue(id,&inqueue);
                }
            }
            else if (IsEqual(nextinput,"CLEAR;")){
                clearqueue(&inqueue);
            }
        }

        //song
        else if (IsEqual(input,"SONG")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"NEXT;")){
                songnext(&incursong,&inqueue,&instack);
            }
            else if (IsEqual(nextinput,"PREVIOUS;")){
                songprevious(&incursong,&inqueue,&instack);
            }
        }

        //playlist
        else if (IsEqual(input,"PLAYLIST")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"CREATE;")){
                playlistcreate(&inplaylist);
            }
            else if (IsEqual(nextinput,"ADD")){
                Word inputadd = takeword(currentWord,3);
                if (IsEqual(inputadd,"SONG;")){
                    tambahlaguplaylist(inpenyanyi,inalbum,insong,&inplaylist);
                }
                else if (IsEqual(inputadd,"ALBUM;")){
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

        //status
        else if (IsEqual(input,"STATUS;")){
            //status(incursong,inqueue);
        }

        //save
        else if (IsEqual(input, "SAVE")){
            hapustikom(&currentWord);
            char *filename = WordToString(takeword(currentWord,2));
            //call save

        }

        //help
        else if (IsEqual(input,"HELP;")){
            help_after();
        }

        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }

    //quit nya disini aj ya 
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    STARTINPUTKATA();
    //printf("\n");
    while (!(IsEqual(currentWord, "Y") || !IsEqual(currentWord, "N")))
    {
        printf("Input tidak valid. Silakan memasukkan 'Y;' jika ingin menyimpan data sesi sekarang dan 'N;' jika tidak ingin menyimpan data sesi sekarang (Y/N): ");
        STARTINPUTKATA();
    }
    if (IsEqual(currentWord, "Y;"))
    {
        char *filename;
        queue *antrian;
        printf("Masukkan nama file penyimpanan: ");
        STARTINPUTKATA();
        filename = WordToString(currentWord);
        //save(filename,Penyanyi,Album,Song,antrian,history,playlist,LaguSekarang);
        //printf("\nThank you for using WayangWave.\n");
        exit(0);
    }
    else if(IsEqual(currentWord, "N;"))
    {
        printf("Kamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/\n");
    }
}
                            
void displaywayangwave(){
printf("                                                  WELCOME TO                                                      \n");                                                                                                                 
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
printf("\n");
printf("                                            CREATED BY GROUP 10 K-2                                               \n");   
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

    valuetype namaplaylist= "-";
    boolean isplayplaylist = false;

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
            mainafter(Penyanyi,Album,Song,antrian,history,playlist,LaguSkrg,namaplaylist,isplayplaylist);
            break;
        }

        // help
        else if (IsEqual(input,"HELP;")){
            help_before();
        }

        // load
        else if (IsEqual(input,"LOAD")){
            hapustikom(&currentWord);
            char *checkCWord = WordToString(currentWord);
            printf("Current Word setelah hapustikom: %s\n",checkCWord);
            char *input2 = WordToString(takeword(currentWord,2));
            Word inputke2 = StringtoWord (input2);
            printf("Banyak char input: %d\n", inputke2.Length);



            printf("Banyak char word takeword (1 kalimat): %d\n", currentWord.Length);
            printf("Banyak char word ke 1: %d\n", takeword(currentWord, 1).Length);
            printf("Banyak char word ke 2: %d\n", takeword(currentWord, 2).Length);

            char *filename = ConcateChar("src/config/",input2);
            printf("Hasil concate src dir + input filename: %s\n",filename);

            Word hasilconcate = StringtoWord(filename);
            printf("Banyak char hasil concate src dir + input filename: %d\n", hasilconcate.Length);

            if (Checkload(filename)){
                Load(&Penyanyi,&Album,&Song,filename,&antrian,&history,&playlist,&LaguSkrg);
                mainafter(Penyanyi,Album,Song,antrian,history,playlist,LaguSkrg,namaplaylist,isplayplaylist);
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

void quit(ListPenyanyi Penyanyi, MapAlbum Album, SetSong Song, Stack history, ArrayDinPlaylist playlist, CurrentSong LaguSekarang)
{
    
}
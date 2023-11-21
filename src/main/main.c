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
#include "../command/Status/status.h"
#include "../command/Enhance/enhance.h"
#include "../command/Save/save.h"

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

        //invalid comm 2
        else if (IsEqual(input,"START;") || IsEqual(input,"LOAD")){
            invalid_command2();
        }

        //list
        else if (IsEqual(input,"LIST")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"DEFAULT;")){
                listdefault(inpenyanyi,inalbum,insong);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                Dlistplaylist(inplaylist);
            }
            else{
                invalid_command4();
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
            }
            else{
                invalid_command4();
            }
        }

        //queue
        else if (IsEqual(input,"QUEUE")){
            Word nextinput = takeword(currentWord,2);
            if (IsEqual(nextinput,"SONG;")){
                queuelagu(&inqueue,inpenyanyi,inalbum,insong,&inputisplayplaylist,innamaplaylist,inplaylist);
            }
            else if (IsEqual(nextinput,"PLAYLIST;")){
                queueplaylist(inplaylist,&inqueue,&innamaplaylist,&inputisplayplaylist,incursong);
            }
            else if (IsEqual(nextinput,"SWAP")){
                int validasi = currentWord.Length-11;
                hapustikom(&currentWord);
                int id1 = -99, id2 = -99;
                if (validasi>=4){
                    id1 = WordToInt(takeword(currentWord,3));
                    id2 = WordToInt(takeword(currentWord,4));
                    swapqueue(id1,id2,&inqueue,&inputisplayplaylist);
                }
                else{
                    invalid_command4();
                }
            }
            else if (IsEqual(nextinput,"REMOVE")){
                int validasi = currentWord.Length-13;
                hapustikom(&currentWord);
                if (validasi>=2){
                    int id = WordToInt(takeword(currentWord,3));
                    removequeue(id,&inqueue,&inputisplayplaylist);
                }
            }
            else if (IsEqual(nextinput,"CLEAR;")){
                clearqueue(&inqueue,&inputisplayplaylist);
            }
            else{invalid_command4();}
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
            else{
                invalid_command4();
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
                else{
                    invalid_command4();
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
                else{
                    invalid_command4();
                }
            }
            else if (IsEqual(nextinput,"REMOVE")){
                int validasi = currentWord.Length-16;
                int IDplaylist = -99, x = -99;
                if (validasi >=4){
                    IDplaylist = WordToInt(takeword(currentWord,3));
                    x = WordToInt(takeword(currentWord,4));
                    removeplaylist(&inplaylist,IDplaylist,x);
                }
                else{
                    invalid_command4();
                }
            }
            else if (IsEqual(nextinput,"DELETE;")){
                hapusplaylist(&inplaylist);
            }
            else{
                invalid_command4();
            }
        }
        //enhance
        else if(IsEqual(input, "ENHANCE;")){
            enhanceplaylist(&inplaylist, inpenyanyi, inalbum, insong);
        }
        //status
        else if (IsEqual(input,"STATUS;")){
            status(incursong,inqueue,inputisplayplaylist,innamaplaylist);
        }

        //save
        else if (IsEqual(input, "SAVE")){
            hapustikom(&currentWord);
            char *filename = WordToString(takeword(currentWord,2));
            save(filename,inpenyanyi,inalbum,insong,inqueue,instack,inplaylist,incursong);

        }

        //help
        else if (IsEqual(input,"HELP;")){
            help_after();
        }
        
        //invalid comm 1
        else{
            invalid_command5();
        }
        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }

    //quit
    printf("\nApakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    STARTINPUTKATA();
    hapustikom(&currentWord);
    //printf("\n");
    while (!(IsEqual(currentWord, "Y") || IsEqual(currentWord, "N")))
    {
        printf("Input tidak valid. Silakan memasukkan 'Y;' jika ingin menyimpan data sesi sekarang dan 'N;' jika tidak ingin menyimpan data sesi sekarang (Y/N): ");
        STARTINPUTKATA();
        hapustikom(&currentWord);
    }
    if (IsEqual(currentWord, "Y"))
    {
        char *filename;
        printf("Masukkan nama file penyimpanan: ");
        STARTINPUTKATA();
        hapustikom(&currentWord);
        filename = WordToString(currentWord);

        //save(filename,Penyanyi,Album,Song,antrian,history,playlist,LaguSekarang);
        printf("\nData sesi sekarang milik kamu telah berhasil disimpan.\n");
    }
    else if(IsEqual(currentWord, "N"))
    {
        printf("\nKamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/\n");
    }
    printf("Thank you for using WayangWave :D\n");
    printf("\n");
    exit(0);
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
            char *input2 = WordToString(takeword(currentWord,2));
            char *filename = ConcateChar("src/config/",input2);

            if (Checkload(filename)){
                printf("Load file %s..\n",input2);
                Load(&Penyanyi,&Album,&Song,filename,&antrian,&history,&playlist,&LaguSkrg);
                printf("Berhasil masuk kedalam aplikasi, selamat menikmati!\n");
                mainafter(Penyanyi,Album,Song,antrian,history,playlist,LaguSkrg,namaplaylist,isplayplaylist);
                break;
            }
            else{
                invalid_command3();
            }
        }
        if (IsEqual(input,"LIST") || IsEqual(input,"PLAY") || IsEqual(input,"QUEUE") || IsEqual(input,"SONG") || IsEqual(input,"PLAYLIST") || IsEqual(input,"STATUS;") || IsEqual(input,"SAVE") || IsEqual(input,"QUIT;")){
            invalid_command3();
        }

        //invalid command
        else{
            invalid_command5();
        }

        // input command
        printf(">>> ");
        STARTINPUTKATA();
        input = takeword(currentWord,1);
    }
}
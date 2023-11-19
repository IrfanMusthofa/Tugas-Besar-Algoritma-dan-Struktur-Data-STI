#include "quit.h"
#include <stdio.h>
#include <stdlib.h>

void quit(ListPenyanyi Penyanyi, MapAlbum Album, SetSong Song, Stack history, ArrayDinPlaylist playlist, CurrentSong LaguSekarang)
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)?\n ");
    STARTINPUTKATA();
    //printf("\n");
    while (!(IsEqual(currentWord, 'Y') || IsEqual(currentWord, 'N')))
    {
        printf("Input tidak valid. Silakan memasukkan 'Y' jika ingin menyimpan data sesi sekarang dan 'N' jika tidak ingin menyimpan data sesi sekarang (Y/N): \n");
        STARTINPUTKATA();
    }
    if (IsEqual(currentWord, 'Y'))
    {
        char *filename;
        queue *antrian;
        printf("Masukkan nama file penyimpanan: ");
        STARTINPUTKATA();
        filename = WordToString(currentWord);
        save(filename,Penyanyi,Album,Song,antrian,history,playlist,LaguSekarang);
        //printf("\nThank you for using WayangWave.\n");
        exit(0);
    }
    else if(IsEqual(currentWord, 'N'))
    {
        printf("Kamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/");
    }

}
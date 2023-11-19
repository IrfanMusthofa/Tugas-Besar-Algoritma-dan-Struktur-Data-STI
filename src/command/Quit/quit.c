#include "quit.h"
#include <stdio.h>
#include <stdlib.h>

void quit()
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    STARTINPUTKATA();
    printf("\n");
    while (!(IsEqual(currentWord, 'Y') || IsEqual(currentWord, 'N')))
    {
        printf("Input tidak valid. Silakan memasukkan 'Y' jika ingin menyimpan data sesi sekarang dan 'N' jika tidak ingin menyimpan data sesi sekarang (Y/N): \n");
        STARTINPUTKATA();
    }
    if (IsEqual(currentWord, 'Y'))
    {
        //char *savefile;

        save();
        printf("Thank you for using WayangWave");
        exit(0);
    }
    else if(IsEqual(currentWord, 'N'))
    {
        printf("\n Kamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/");
    }

}
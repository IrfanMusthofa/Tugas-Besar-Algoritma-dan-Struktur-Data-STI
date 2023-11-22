#include "invalidcommand.h"
#include <stdio.h>

/* Tidak ada command dengan nama berikut*/
void invalid_command1()
{
    printf("Command tidak diketahui!\n");
}

/*command tidak ada tikom*/
void invalid_command2()
{
    printf("Command tidak bisa dieksekusi, jangan lupa setiap command diakhiri dengan titik koma (;).\n");
}

/*Mengeksekusi sebelum/sesudah memasuki sesi*/
void invalid_command3()
{
    printf("Command tidak bisa dieksekusi!\n");
}
void invalid_command4(){
    printf("Command tidak sesuai, masukkan command \"HELP;\" untuk melihat list command.\n");
}

void invalid_command5(){
    printf("Command tidak diketahui, masukkan command \"HELP;\" untuk melihat list command\n");
}

void invalid_command6(){
    printf("Tidak ada file dengan nama tersebut.\n");
}
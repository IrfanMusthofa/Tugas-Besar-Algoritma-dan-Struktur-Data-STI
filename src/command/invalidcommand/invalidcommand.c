#include "invalidcommand.h"
#include <stdio.h>

/* Tidak ada command dengan nama berikut*/
void invalid_command1()
{
    printf("Command tidak diketahui!\n");
}

/* Mengeksekusi sesudah memasuki sesi*/
void invalid_command2()
{
    printf("Command tidak bisa dieksekusi!\n");
}

/*Mengeksekusi sebelum memasuki sesi*/
void invalid_command3()
{
    printf("Command tidak bisa dieksekusi!\n");
}
/*File: header*/
/*Definisi struktur data penyanyi, album, lagu, playlist, stack, queue*/

#ifndef __HEADER__
#define __HEADER__

#include "boolean.h"

#define NMAX 100

typedef int Eltype;
typedef int address;
typedef int keytype;
typedef char* valuetype;



typedef struct
{
    valuetype lagu[NMAX];
    address Count;
    valuetype namaalbumlagu;
    valuetype namapenyanyilagu;
} SetLagu;

typedef struct {
    keytype KeySong;
    valuetype namalagu;
} MapSong;


typedef struct {
    valuetype namaalbum;
    MapSong ElementsAlbum[NMAX];
    address CountSong;
} Album;


typedef struct {
    keytype KeyAlbum;
    valuetype namaalbum;
} MapAlbum;


typedef struct {
    char *namapenyanyi;
    MapAlbum ElementsPenyanyi[NMAX];
    address CountAlbum;
} Penyanyi;


typedef struct {
    Penyanyi contents[NMAX];
    Eltype nEff;
} List;

/*typedef struct {
    keytype SetLagu;
    address SetLagu;
} */

#endif

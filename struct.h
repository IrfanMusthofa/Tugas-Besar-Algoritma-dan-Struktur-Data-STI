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

// /*type bentukan set*/
// typedef struct
// {
//     Song lagu [NMAX];
//     address Count;
// } SetSongs;

typedef struct
{
    valuetype nlagu;
    valuetype nalbum;
    valuetype npenyanyi;
} Song;


/*type bentukan list penyanyi dengan albumnya*/
typedef struct {
    keytype KeySong;
    valuetype lagu;
} MapSong;


typedef struct {
    keytype KeyAlbum;
    MapSong ElementsAlbum[NMAX];
    address CountSong;
} Album;

/*type bentukan list penyanyi dengan albumnya*/
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

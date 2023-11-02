/*File: header*/
/*Definisi struktur data penyanyi, album, lagu, playlist, stack, queue*/

#ifndef __HEADER__
#define __HEADER__

#include "boolean.h"

#define NMAX 100

typedef int Eltype;
typedef int address;
typedef int keytype;

// Aliaskan struktur Song
typedef struct {
    char *namalagu;
    char *namapenyanyilagu;
    char *namaalbumlagu;
} Song;

// Aliaskan struktur MapSong
typedef struct {
    keytype KeySong;
    Song ValueSong;
} MapSong;

// Aliaskan struktur Album
typedef struct {
    char *namaalbum;
    MapSong ElementsAlbum[NMAX];
    address CountSong;
} Album;

// Aliaskan struktur MapAlbum
typedef struct {
    keytype KeyAlbum;
    Album ValueAlbum;
} MapAlbum;

// Aliaskan struktur Penyanyi
typedef struct {
    char *namapenyanyi;
    MapAlbum ElementsPenyanyi[NMAX];
    address CountPenyanyi;
} Penyanyi;

// Aliaskan struktur List
typedef struct {
    Penyanyi contents[NMAX];
    Eltype nEff;
} List;

#endif

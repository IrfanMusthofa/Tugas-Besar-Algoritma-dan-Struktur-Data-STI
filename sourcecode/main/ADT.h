#ifndef __adt__
#define __adt__

#include "boolean.h"
#include "../ADT/MesinKalimat/mesinkata.h"


#define NMAX 100
#define EMPTY ""

typedef int keytype;
typedef char *valuetype;
typedef char *infotype;
typedef int IDs;
typedef struct tElmtlist *address;

typedef struct{
    IDs IdAlbum;
    valuetype namaP; 
    valuetype namaA;
    valuetype namaS;
} Song;

typedef struct tElmtlist { 
	Song info;
	address next;
} ElmtList;

typedef struct{
    address First;
	valuetype namaPlaylist;
} List;

typedef struct
{
    List *playlist;
    int Capacity;
    int Neff;
} ArrayDinPlaylist;

typedef struct
{
    Song T[NMAX];
    int TOP;
} Stack;


typedef struct
{
    Song buffer [NMAX];
    int idxTail;
} Queue;

typedef struct{
    keytype keyAlbum;
    IDs IdPenyanyi;
    valuetype valueAlbum;
} Album;

typedef struct{
    Song Elements[NMAX];
    int count;
} SetSong;

typedef struct{
    Album Elements[NMAX];
    int count;
} MapAlbum;

typedef char* Eltype;

typedef struct{
    Eltype A[NMAX];
    int neff;
} ListPenyanyi;

// typedef struct{
//     IDs idpenyanyi;
//     IDs idalbum;
//     IDs idlagu;
// } ID;

void MakeEmpty(ListPenyanyi *Penyanyi,MapAlbum *Album,SetSong *Song);

void STARTCOM(ListPenyanyi *Penyanyi,MapAlbum *Album,SetSong *Song, char *file);

IDs GetPenyanyiID(ListPenyanyi List, char *penyanyi);

IDs GetAlbumID (MapAlbum album, char *namaalbum);

int JumlahAlbum (MapAlbum album, IDs idpenyanyi);

int JumlahLagu (SetSong song, IDs idalbum);

#endif
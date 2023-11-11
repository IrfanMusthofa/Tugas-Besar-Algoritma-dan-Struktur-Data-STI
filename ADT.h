#ifndef __adt__
#define __adt__

#include "./src/boolean.h"
// #include "./src/set.h"

#define Nil 0
#define NMAX 100
#define EMPTY ""

typedef int keytype;
typedef char *valuetype;
typedef int infotype;
typedef struct tElmtlist *address;

typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtList;

typedef struct{
    address First;
} List;

typedef struct
{
    List *playlist;
    int Capacity;
    int Neff;
} ArrayDinPlaylist;

typedef struct
{
    Song T[NMax];
    int TOP;
} Stack;


typedef struct
{
    Song buffer [NMAX];
    int idxTail;
} Queue;

typedef struct{
    keytype keySong;
    valuetype valueSong;
} Song;

typedef struct{
    keytype keyAlbum;
    valuetype valueAlbum;
} Album;

typedef struct{
    Song Elements[NMAX];
    int count;
} MapSong;

typedef struct{
    Album Elements[NMAX];
    int count;
} MapAlbum;

typedef char* Eltype;

typedef struct{
    Eltype A[NMAX];
    int neff;
} List;

// typedef struct{
//     IDs idpenyanyi;
//     IDs idalbum;
//     IDs idlagu;
// } ID;

void MakeEmpty(List *Penyanyi,MapAlbum *Album,MapSong *Song);

void STARTCOM(List *Penyanyi,MapAlbum *Album,MapSong *Song);

#endif

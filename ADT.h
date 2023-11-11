#ifndef __adt__
#define __adt__

#include "./src/boolean.h"
// #include "./src/set.h"

#define Nil 0
#define NMAX 100
#define EMPTY ""

typedef int keytype;
typedef int address;
typedef char *valuetype;
typedef int IDs;

// typedef struct{
//     IDs idsong;
//     valuetype lagu;
// } SetSong;

typedef struct{
    IDs IdAlbum;
    valuetype namaP; 
    valuetype namaA;
    valuetype namaS;
} Song;

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
    address count;
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

void MakeEmpty(List *Penyanyi,MapAlbum *Album,SetSong *Song);

void STARTCOM(List *Penyanyi,MapAlbum *Album,SetSong *Song);

#endif
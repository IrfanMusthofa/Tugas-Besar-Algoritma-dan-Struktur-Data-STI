#ifndef __adt__
#define __adt__

#include "boolean.h"
#include "../ADT/MesinKalimat/mesinkata.h"


#define NMAX 20
#define EMPTY ""

typedef int keytype;
typedef char* valuetype;
typedef char* infotype;
typedef char* Eltype;
typedef int IDs;
typedef struct tElmtlist *address;

// ==============*** STRUCT AFTER DEFAULT ***==============
// struct pada queue, stack dan playlist

// Struct Song
typedef struct{
    valuetype namaP; 
    valuetype namaA;
    valuetype namaS;
} Song;

// playlist
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

// stack buat history
typedef struct
{
    Song T[NMAX];
    int TOP;
} Stack;


// queue buat queue
typedef struct
{
    Song buffer [NMAX];
    int idxTail;
} queue;

// struct khusus current song
typedef struct {
    Eltype NamaP;
    Eltype NamaA;
    Eltype NamaS;
} CurrentSong;



// ==============*** STRUCT DEFAULT ***==============
//struct pada setsong
typedef struct{
    IDs Idalbum;
    valuetype namalagu;
} elmtsong;

typedef struct{
    elmtsong Elements[NMAX*5];
    int count;
} SetSong;

//struct pada album (20 kedikitan ey 60 lah ya)
typedef struct{
    keytype keyAlbum;
    IDs IdPenyanyi;
    valuetype valueAlbum;
} Album;

typedef struct{
    Album Elements[NMAX*3];
    int count;
} MapAlbum;

//struct liststatis penyanyi
typedef struct{
    Eltype A[NMAX];
    int neff;
} ListPenyanyi;


//F.S nilai efektif ketiganya = 0
void MakeEmpty(ListPenyanyi *Penyanyi,MapAlbum *Album,SetSong *Song);

//Command START, read file default(config) dan memasukkan nilainya ke variable
void STARTCOM(ListPenyanyi *Penyanyi,MapAlbum *Album,SetSong *Song, char *file);


//I.S string penyanyi pastikan ada di list
//F.S mengembalikan ID penyanyi dari string penyanyi input
IDs GetPenyanyiID(ListPenyanyi List, char *penyanyi);

//I.S string album pastikan ada di map
//F.S mengembalikan ID album dari string album input
IDs GetAlbumID (MapAlbum album, char *namaalbum);

//I.S ID penyanyi pastikan ada
//F.S mengembalikan jmlh album yang dimiliki penyanyi tsb
int JumlahAlbum (MapAlbum album, IDs idpenyanyi);

//I.S ID album pastikan ada
//F.S mengembalikan jmlh lagu yang dimiliki album tsb
int JumlahLagu (SetSong song, IDs idalbum);

#endif

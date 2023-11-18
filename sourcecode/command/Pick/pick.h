#ifndef __pickadt__
#define __pickadt__

#include "boolean.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../ADT/MesinKalimat/mesinkarakter.h"
#include "../../main/ADT.h"
#include "../List/list.h"

/* Menampilkan list penyanyi */
/* IS : list penyanyi terdefinisi */
/* FS : akan ditampilkan list penyanyi yang ada */
void listp(ListPenyanyi Penyanyi);

/* memilih penyanyi, input dari user */
/* IS : list penyanyi terdefinisi */
/* FS : akan mengembalikan penyanyi yang diinputkan dengan benar */
valuetype pickpenyanyi(ListPenyanyi Penyanyi);

/* Menampilkan list album */
/* IS : list penyanyi, mapalbum terdefinisi, penyanyi yang ingin ditampilkan albumnya */
/* FS : akan ditampilkan list album yang ada, dan idS akan menjadi id dari id  */
void listalbum(ListPenyanyi list, MapAlbum album, valuetype penyanyi, IDs *id);

/* memilih album, input dari user */
/* IS : map album terdefinisi, id album terdefinisi */
/* FS : akan mengembalikan album yang diinputkan dengan benar */
valuetype pickalbum(MapAlbum Album, IDs id);

/* Menampilkan list lagu */
/* IS : MapAlbum, SetSong, namaalbum, dan liststatic terdefinisi */
/* FS : akan ditampilkan list lagu yang ada, dan list static L akan berisi lagu-lagu dari album tersebut  */
void listlagu(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L);

/* memilih lagu, input dari user */
/* IS : list static terdefinisi */
/* FS : akan mengembalikan lagu yang diinputkan dengan benar */
valuetype picklagu(ListStatic L);

/* Menampilkan listplaylist */
/* IS : Arraydinplaylist terdefinisi */
/* FS : akan ditampilkan  list playlist yang ada*/
void listplaylist(ArrayDinPlaylist P);

/* memilih playlist */
/* IS : Arraydinplaylist terdefinisi */
/* FS : memilih playlist, akan mengambalikan id*/
IDs pickplaylist(ArrayDinPlaylist P);

#endif
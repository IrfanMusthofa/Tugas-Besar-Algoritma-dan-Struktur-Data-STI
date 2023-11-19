#ifndef __listdefaultadt__
#define __listdefaultadt__

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "ADT.h"
#include "list.h"
#include "pick.h"
#include "playlist2.h"

/* Memilih penyanyi di list default */
/* IS: List penyanyi terdefinisi */
/* FS: Mengembalikan penyanyi yang dipilih */
valuetype pickpenyanyilist(ListPenyanyi Penyanyi);

/* Memilih album di list default */
/* IS: Album terdefinisi, dan id penyanyi terdefinisi */
/* FS: Mengembalikan penyanyi yang dipilih */
valuetype pickalbumlist(MapAlbum Album, IDs id);

/* Menampilkan list lagu */
/* IS : MapAlbum, SetSong, namaalbum, dan liststatic terdefinisi */
/* FS : akan ditampilkan list lagu yang ada, dan list static L akan berisi lagu-lagu dari album tersebut  */
void listlagudefault(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L, valuetype namaP);

/* Menampilkan list dari penyanyi, album, dan lagunya */
/* IS: Penyanyi terdefinisi, map album, dan setsong */
/* FS: Menampilkan list default */
void listdefault(ListPenyanyi Penyanyi, MapAlbum album, SetSong song);

/* Menampilkan listplaylist */
/* IS : Arraydinplaylist terdefinisi */
/* FS : akan ditampilkan  list playlist yang ada*/
void listplaylist(ArrayDinPlaylist A);

#endif


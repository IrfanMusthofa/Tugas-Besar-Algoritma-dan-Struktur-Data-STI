#ifndef __listdefaultadt__
#define __listdefaultadt__

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "ADT.h"
#include "list.h"
#include "pick.h"

/* memilih penyanyi, input dari user */
/* IS : list penyanyi terdefinisi */
/* FS : akan mengembalikan penyanyi yang diinputkan dengan benar */
valuetype pickpenyanyilist(ListPenyanyi Penyanyi);

/* memilih album, input dari user */
/* IS : map album terdefinisi, id album terdefinisi */
/* FS : akan mengembalikan album yang diinputkan dengan benar */
valuetype pickalbumlist(MapAlbum Album, IDs id);

//valuetype picklagulist(ListStatic L);

//void listplaylistlist(ArrayDinPlaylist P);

//void listlagu(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L);
//valuetype picklagu(ListStatic L);

void listdefault(ListPenyanyi Penyanyi, MapAlbum album, SetSong song);


#endif


#ifndef __pickadt__
#define __pickadt__

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "ADT.h"
#include "list.h"


void listp(ListPenyanyi Penyanyi);
valuetype pickpenyanyi(ListPenyanyi Penyanyi);

void listalbum(ListPenyanyi list, MapAlbum album, valuetype penyanyi, IDs *id);
valuetype pickalbum(MapAlbum Album, IDs id);

void listlagu(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L);
valuetype picklagu(ListStatic L);

void listplaylist(ArrayDinPlaylist P);
IDs pickplaylist(ArrayDinPlaylist P);

#endif
#ifndef __listdefaultadt__
#define __listdefaultadt__

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "ADT.h"
#include "list.h"
#include "pick.h"


valuetype pickpenyanyilist(ListPenyanyi Penyanyi);

valuetype pickalbumlist(MapAlbum Album, IDs id);

//valuetype picklagulist(ListStatic L);

//void listplaylistlist(ArrayDinPlaylist P);

//void listlagu(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L);
//valuetype picklagu(ListStatic L);

void listdefault(ListPenyanyi Penyanyi, MapAlbum album, SetSong song);


#endif


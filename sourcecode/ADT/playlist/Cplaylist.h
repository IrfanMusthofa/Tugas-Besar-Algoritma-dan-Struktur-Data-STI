#ifndef __CommandPlaylist__
#define __CommandPlaylist__

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ADT.h"
#include "mesinkata.h"
#include "playlist.h"
#include "pick.h"

void playlistcreate(ArrayDinPlaylist *array);

void tambahlaguplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array);

void tambahalbumplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array);

void swapplaylist(ArrayDinPlaylist *array, int idP, int x, int y);

void removeplaylist(ArrayDinPlaylist *array, int idP, int x);

void deleteplaylist();

#endif

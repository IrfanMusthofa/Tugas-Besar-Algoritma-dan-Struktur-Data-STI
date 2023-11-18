#ifndef __save__
#define __save__

#include "../../main/ADT.h"
#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/List/list.h"
#include "../../ADT/MesinKalimat/mesinkarakter.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../ADT/Playlist/playlist.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/stack.h"

void save(char *filename, ListPenyanyi Penyanyi, MapAlbum Album, SetSong Song, queue *anrian, Stack history, ArrayDinPlaylist playlist);

#endif
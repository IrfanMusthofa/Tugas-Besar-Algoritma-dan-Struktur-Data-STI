#ifndef __load__
#define __load__

#include "../../main/ADT.h"
#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/List/list.h"
#include "../../ADT/MesinKalimat/mesinkarakter.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../ADT/Playlist/playlist.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/stack.h"

boolean Checkload(char *file);

void Load(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *SetSong, char *file, queue *QueueSong, Stack *History, ArrayDinPlaylist *DinPlaylist, CurrentSong *LaguSekarang);

#endif
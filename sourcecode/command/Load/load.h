#ifndef __load__
#define __load__

#include "boolean.h"
#include "../../ADT/MesinKalimat/mesinkarakter.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../main/ADT.h"
#include <stdlib.h>
#include <stdio.h>

boolean checkload(char *file);

void Load(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *SetSong, char *file, queue *QueueSong, Stack *History, ArrayDinPlaylist *DinPlaylist, CurrentSong *LaguSekarang);

#endif
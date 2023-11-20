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

#include "../Help/help.h"
#include "../Load/load.h"
#include "../Pick/pick.h"
#include "../Playlist/Cplaylist.h"
#include "../invalidcommand/invalidcommand.h"
#include "../Song/song.h"
#include "../ListC/Clist.h"
#include "../Play/play.h"
#include "../Queue/Cqueue.h"
#include "../Status/status.h"
#include "../Enhance/enhance.h"

void save(char *filename, ListPenyanyi Penyanyi, MapAlbum Album, SetSong Song, queue antrian, Stack history, ArrayDinPlaylist playlist, CurrentSong LaguSekarang);

#endif
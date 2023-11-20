#ifndef __save__
#define __save__

#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

#include "../ADT/List/list.h"
#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
#include "../ADT/Playlist/playlist.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Stack/stack.h"

#include "../command/Help/help.h"
#include "../command/Load/load.h"
#include "../command/Pick/pick.h"
#include "../command/Playlist/Cplaylist.h"
#include "../command/invalidcommand/invalidcommand.h"
#include "../command/Song/song.h"
#include "../command/ListC/Clist.h"
#include "../command/Play/play.h"
#include "../command/Queue/Cqueue.h"
#include "../command/Status/status.h"
#include "../command/Enhance/enhance.h"

void save(char *filename, ListPenyanyi Penyanyi, MapAlbum Album, SetSong Song, queue antrian, Stack history, ArrayDinPlaylist playlist, CurrentSong LaguSekarang);

#endif
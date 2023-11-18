#include "ADT.h"
#include "pick.h"
#include "queue.h"
#include "stack.h"

void playsong(CurrentSong *nowplay, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu, queue *currentqueue, Stack *previous);

void playplaylist(CurrentSong *nowplay, ArrayDinPlaylist playlist, queue *currentqueue, Stack *previous);


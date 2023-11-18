#include "../../main/ADT.h"
#include "../Pick/pick.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/stack.h"
#include "../../ADT/Playlist/playlist.h"

/* Memainkan lagu */
/* IS: CurrentSong, ListPenyanyi, MapAlbum, Setsong, Queue, dan Stack previous terdefinisi */
/* FS: currentsong berisi lagu yang dimasukkan, stack dan queue kosong*/
void playsong(CurrentSong *nowplay, ListPenyanyi penyanyi, MapAlbum map, SetSong lagu, queue *currentqueue, Stack *previous);

/* Memainkan playlist */
/* IS: CurrentSong, ListPenyanyi, MapAlbum, Setsong, Queue, ArrayDinPlaylist dan Stack previous terdefinisi */
/* FS: currentsong berisi playlist lagu pertama, stack kosong, dan queue berisi lagu playlist kedua dst*/
void playplaylist(CurrentSong *nowplay, ArrayDinPlaylist playlist, queue *currentqueue, Stack *previous);


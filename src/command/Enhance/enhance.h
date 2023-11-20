#ifndef __enhance__
#define __enhance__
#include "boolean.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../main/ADT.h"
#include "../../ADT/List/list.h"
#include "../../ADT/Playlist/playlist.h"
#include "../Pick/pick.h"

/* Mengeluaarkan angka random */
/* IS: Min value dan maxvalue terdefinisi */
/* FS: Mengembalikan nilai integer rentang minvalue - maxvalue */
int generateRandomNumber(int minValue, int maxValue);

/* Menambahkan lagu random ke playlist */
/* IS: Arraydin playlist terdefinisi */
/* FS: Playlist ketambahan beberapa lagu random*/
void enhanceplaylist(ArrayDinPlaylist *array, ListPenyanyi Penyanyi, MapAlbum Album, SetSong song);

#endif

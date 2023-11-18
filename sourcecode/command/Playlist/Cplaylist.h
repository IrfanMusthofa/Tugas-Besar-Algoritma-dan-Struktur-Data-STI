#ifndef __CommandPlaylist__
#define __CommandPlaylist__

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../../main/ADT.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../ADT/playlist/playlist.h"
#include "../Pick/pick.h"

/* Membuat playlist baru */
/* IS : arraydinplaylist terdefinisi */
/* FS : akan terbentuk playlist dengan nama tertentu */
void playlistcreate(ArrayDinPlaylist *array);

/* Menambahkan lagu pada playlist tertentu */
/* IS : arraydinplaylist terdefinisi, mapalbum, set song, dan listpenyanyi  */
/* FS : akan terbentuk playlist dengan nama tertentu */
void tambahlaguplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array);

/* Menambahkan album pada playlist tertentu, apabila lagu sudah ada, tidak dimasukkan */
/* IS : arraydinplaylist terdefinisi, mapalbum, set song, dan listpenyanyi  */
/* FS : album ditambahkan pada playlist */
void tambahalbumplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array);

/* Menukar urutan lagu pada playlist tertentu */
/* IS : arraydinplaylist terdefinisi, idP adalah ID playlist yang ingin ditukar, x dan y adalah urutan lagu  */
/* FS : lagu akan ditukar dengan urutan x dan y apabila IDp, x, dan y valid*/
void swapplaylist(ArrayDinPlaylist *array, int idP, int x, int y);

/* menghapus lagu di playlist dengan ID idP, dengan urutan lagu x */
/* IS : arraydinplaylist terdefinisi, idP adalah ID playlist yang ingin ditukar, x adalah urutan lagu  */
/* FS : lagu dengan urutan x pada playlist id idP, akan terhapus apabila valid */
void removeplaylist(ArrayDinPlaylist *array, int idP, int x);

/* menghapus playlist */
/* IS : arraydinplaylist terdefinisi */
/* FS : playlist yang dipilih akan terhapus */
void hapusplaylist(ArrayDinPlaylist *array);

#endif

#include "load.h"
#include "../main/ADT.c"
#include <stdlib.h>

boolean checkload(char *file) {
    char p = fopen(file, "r");
    if (p == NULL) return false;
    else true;
}

void load(ListPenyanyi *Penyanyi, MapAlbum *Album,SetSong *Song, char *file) {

    //dijalankan pertama sebelum queue & playlist
    STARTCOM(Penyanyi, Album, Song, file);

    
}
#include "load.h"
#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
#include "../main/ADT.h"
#include <stdlib.h>

boolean checkload(char *file) {
    char p = fopen(file, "r");
    if (p == NULL) return false;
    else true;
}

void load(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *Song, char *file, Queue *QueueSong, Stack *History, ArrayDinPlaylist *DinPlaylist) {

    //dijalankan pertama sebelum queue & playlist
    STARTCOM(Penyanyi, Album, Song, file);
    ADVWORD();

    // Masukkan banyak songs ke Queue
    QueueSong->idxTail = WordToInt(takekata(currentWord)) - 1;

    // Masukkan songs ke Queue
    for (int i = 0; i < QueueSong->idxTail + 1; i++) {
        ADVWORD();


        // Ambil penyanyi, album, song dalam satu baris tsb
        valuetype namaP = takewordsemicolon(currentWord, 1);
        valuetype namaA = takewordsemicolon(currentWord, 2);
        valuetype namaS = takewordsemicolon(currentWord, 3);

        // Masukkan ke QueueSong
        
        
    }
}
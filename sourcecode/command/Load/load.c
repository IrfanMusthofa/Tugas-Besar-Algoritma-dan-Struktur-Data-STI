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

void load(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *SetSong, char *file, Queue *QueueSong, Stack *History, ArrayDinPlaylist *DinPlaylist) {

    //dijalankan pertama sebelum queue & playlist
    STARTCOM(Penyanyi, Album, SetSong, file);


    // Lanjut baca Queue, history, playlist

    // BACA QUEUE
    ADVWORD();
    CreateQueue(QueueSong);
    // Masukkan banyak songs ke Queue
    int banyakSongs = WordToInt(takekata(currentWord));

    // Masukkan songs ke Queue
    for (int i = 0; i < banyakSongs; i++) {
        ADVWORD();


        // Ambil penyanyi, album, song dalam satu baris tsb
        valuetype namaP = takewordsemicolon(currentWord, 1);
        valuetype namaA = takewordsemicolon(currentWord, 2);
        valuetype namaS = takewordsemicolon(currentWord, 3);

        // Masukkan ke QueueSong
        Song readyToInput;
        readyToInput.namaP = namaP;
        readyToInput.namaA = namaA;
        readyToInput.namaS = namaS;

        enqueue(QueueSong, readyToInput);
    }


    // BACA HISTORY
    ADVWORD();
    
}
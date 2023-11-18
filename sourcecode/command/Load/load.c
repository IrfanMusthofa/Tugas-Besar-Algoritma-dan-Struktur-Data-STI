#include "load.h"
#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
#include "../main/ADT.h"
#include <stdlib.h>

boolean checkload(char *file) {
    char check = fopen(file, "r");
    if (check == NULL) return false;
    else true;

}

void load(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *SetSong, char *file, queue *QueueSong, Stack *History, ArrayDinPlaylist *DinPlaylist) {

    //Dijalankan pertama sebelum queue & playlist
    STARTCOM(Penyanyi, Album, SetSong, file);


    // Lanjut baca Queue, history, playlist

    // BACA QUEUE
    ADVWORD();
    CreateQueue(QueueSong);
    // Masukkan banyak songs ke Queue queue
    int banyakQueueSongs = WordToInt(takekata(currentWord));

    // Masukkan songs ke Queue
    for (int i = 0; i < banyakQueueSongs; i++) {
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
    Stack HistoryRAW;
    CreateEmpty(&HistoryRAW); // Sebelum direverse
    CreateEMpty(History); // Final setelah direverse

    // Masukkan banyak songs riwayat
    int banyakHistorySongs = WordToInt(takekata(currentWord));

    // Masukkan songs ke Stack History
    for (int j = 0; j < banyakHistorySongs; j++) {
        ADVWORD();

        // Ambil penyanyi, album, song dalam satu baris tsb
        valuetype namaP = takewordsemicolon(currentWord, 1);
        valuetype namaA = takewordsemicolon(currentWord, 2);
        valuetype namaS = takewordsemicolon(currentWord, 3);

        // Masukkan ke History
        Song readyToInput;
        readyToInput.namaP = namaP;
        readyToInput.namaA = namaA;
        readyToInput.namaS = namaS;

        Push(HistoryRAW, readyToInput);
    }

    for (int j = 0; j < banyakHistorySongs; j++) {
        Song readyToReverse;
        Pop(&HistoryRAW, &readyToReverse);
        Push(History, readyToReverse);
    }
}
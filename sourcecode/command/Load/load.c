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

    // ===== ***Dijalankan pertama sebelum queue & playlist*** =====
    // ===== Baca default terlebih dahulu =====
    STARTCOM(Penyanyi, Album, SetSong, file);


    // ***Lanjut baca Current Song, Queue, History, Playlist***
    // ===== Current Song =====
    ADVWORD();
    CurrentSong LaguSekarang;
    if (IsEqual(currentWord,"-")) {
        LaguSekarang.NamaP = "-";
        LaguSekarang.NamaA = "-";
        LaguSekarang.NamaS = "-";
    } else {
        LaguSekarang.NamaP = WordToString(takewordsemicolon(currentWord, 1));
        LaguSekarang.NamaA = WordToString(takewordsemicolon(currentWord, 2));
        LaguSekarang.NamaS = WordToString(takewordsemicolon(currentWord, 3));
    }



    // ========== Queue for Queue ==========
    ADVWORD();
    CreateQueue(QueueSong);

    // Masukkan banyak songs ke Queue queue
    int banyakQueueSongs = WordToInt(takeword(currentWord, 1));

    // Masukkan songs ke Queue
    for (int i = 0; i < banyakQueueSongs; i++) {
        ADVWORD(); //Baca 1 kalimat

        // Ambil penyanyi, album, song dalam satu baris tsb
        valuetype namaP = WordToString(takewordsemicolon(currentWord, 1));
        valuetype namaA = WordToString(takewordsemicolon(currentWord, 2));
        valuetype namaS = WordToString(takewordsemicolon(currentWord, 3));

        // Masukkan ke QueueSong
        Song readyToInput;
        readyToInput.namaP = namaP;
        readyToInput.namaA = namaA;
        readyToInput.namaS = namaS;

        enqueue(QueueSong, readyToInput);
    }



    // ========== Stack for History ==========
    ADVWORD();
    Stack HistoryRAW;
    CreateEmpty(&HistoryRAW); // Sebelum direverse
    CreateEmpty(History); // Final setelah direverse

    // Masukkan banyak songs riwayat
    int banyakHistorySongs = WordToInt(takekata(currentWord));

    // Masukkan songs ke Stack History
    for (int j = 0; j < banyakHistorySongs; j++) {
        ADVWORD();

        // Ambil penyanyi, album, song dalam satu baris tsb
        valuetype namaP = WordToString(takewordsemicolon(currentWord, 1));
        valuetype namaA = WordToString(takewordsemicolon(currentWord, 2));
        valuetype namaS = WordToString(takewordsemicolon(currentWord, 3));

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



    // ========== ArrayDinPLaylist for Playlist ==========
    ADVWORD();
    DinPlaylist = MakeArrayDin();

    // Banyak Playlist
    int banyakDinPlaylist = WordToInt(takekata(currentWord));
    
    // Masukkan Playlist ke arraydinplaylist
    for (int k = 0; k < banyakDinPlaylist; k++) {
        ADVWORD();
        
        int banyakLaguPlaylist = WordToInt(takeword(currentWord, 1));
        valuetype namaPlaylist = WordToString(takeword)
        CreatePlaylist (DinPlaylist, namaPlaylist)
    }

}
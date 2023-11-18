#include "load.h"

boolean Checkload(char *file) {
    FILE *check = fopen(file, "r");
    if (check == NULL) return false;
    else return true;
}

void Load(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *SetSong, char *file, queue *QueueSong, Stack *History, ArrayDinPlaylist *DinPlaylist, CurrentSong *LaguSekarang) {

    // ===== ***Dijalankan pertama sebelum queue & playlist*** =====
    // ===== Baca default terlebih dahulu =====
    STARTCOM(Penyanyi, Album, SetSong, file);



    // ***Lanjut baca Current Song, Queue, History, Playlist***
    // ===== Current Song =====
    ADVWORD();
    if (IsEqual(currentWord,"-")) {
        LaguSekarang->NamaP = "-";
        LaguSekarang->NamaA = "-";
        LaguSekarang->NamaS = "-";
    } else {
        LaguSekarang->NamaP = WordToString(takewordsemicolon(currentWord, 1));
        LaguSekarang->NamaA = WordToString(takewordsemicolon(currentWord, 2));
        LaguSekarang->NamaS = WordToString(takewordsemicolon(currentWord, 3));
    }



    // ========== Queue for Queue ==========
    
    ADVWORD();
    printf("\nINI YG BENER%d\n", currentWord.Length);
    // Masukkan banyak songs ke Queue queue
    int banyakQueueSongs = WordToInt(currentWord);

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
    printf("\nINI YG BENER%d\n", currentWord.Length);
    Stack HistoryRAW;
    CreateEmptyS(&HistoryRAW); // Sebelum direverse // Final setelah direverse

    // Masukkan banyak songs riwayat
    int banyakHistorySongs = WordToInt(currentWord);

    // Masukkan songs ke Stack History
    for (int j = 0; j < banyakHistorySongs; j++) {
        ADVWORD();

        // Ambil penyanyi, album, song dalam satu baris tsb
        valuetype namaP = WordToString(takewordsemicolon(currentWord, 1));
        valuetype namaA = WordToString(takewordsemicolon(currentWord, 2));
        valuetype namaS = WordToString(takewordsemicolon(currentWord, 3));

        // Masukkan ke History
        Song readyToHistory;
        readyToHistory.namaP = namaP;
        readyToHistory.namaA = namaA;
        readyToHistory.namaS = namaS;

        Push(&HistoryRAW, readyToHistory);
    }

    for (int j = 0; j < banyakHistorySongs; j++) {
        Song readyToReverse;
        Pop(&HistoryRAW, &readyToReverse);
        Push(History, readyToReverse);
    }



    // ========== ArrayDinPLaylist for Playlist ==========
    ADVWORD();
    printf("\nINI YG BENER%d\n", currentWord.Length);

    // Banyak Playlist
    int banyakDinPlaylist = WordToInt(currentWord);
    
    // Masukkan Playlist ke arraydinplaylist
    for (int k = 0; k < banyakDinPlaylist; k++) {
        ADVWORD();
        
        // Banyak lagu dalam suatu playlist & nama playlist
        int banyakLaguPlaylist = WordToInt(takeword(currentWord, 1));
        valuetype namaPlaylist = WordToString(takekata(currentWord));
        CreatePlaylist (DinPlaylist, namaPlaylist);

        // Masukkan Lagu ke Playlist
        for (int l = 0; l < banyakLaguPlaylist; l++) {
            ADVWORD();

            // Ambil penyanyi, album, song dalam satu baris tsb
            valuetype namaP = WordToString(takewordsemicolon(currentWord, 1));
            valuetype namaA = WordToString(takewordsemicolon(currentWord, 2));
            valuetype namaS = WordToString(takewordsemicolon(currentWord, 3));
            
            // Masukkan ke playlist
            Song readyToPlaylist;
            readyToPlaylist.namaP = namaP;
            readyToPlaylist.namaA = namaA;
            readyToPlaylist.namaS = namaS;
            
            PlaylistAddSong(DinPlaylist, k, readyToPlaylist);
        }
    }
}
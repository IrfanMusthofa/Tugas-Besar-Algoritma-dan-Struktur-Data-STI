#include "load.h"

boolean Checkload(char *file) {
    FILE *check = fopen(file, "r");
    if (check == NULL) return false;
    else return true;
}

void Load(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *SetSong, char *file, queue *QueueSong, Stack *History, ArrayDinPlaylist *DinPlaylist, CurrentSong *LaguSekarang) {

    // ===== ***Dijalankan pertama sebelum queue & playlist*** =====
    // ===== Baca default terlebih dahulu =====
    printf("init");
    STARTWORD(file);
    printf("ialize\n");
    int jlhPenyanyi=0;
    char *tes = currentWord.TabWord;
    while ((*tes)!='\0'){
        if (((*tes=='0') || (*tes=='1') || (*tes=='2') || (*tes=='3') || (*tes=='4') || (*tes=='5') || (*tes=='6') || (*tes=='7') || (*tes=='8') ||(*tes=='9'))){
            jlhPenyanyi *= 10;
            jlhPenyanyi += (*tes) - '0'; // String to int
        }
        tes++;
    }
    Penyanyi->neff = jlhPenyanyi; // Banyak Penyanyi
    Album->count = 0;
    SetSong->count = 0;


    int count1 = 0, count2 = 0, keymaker = 0;

    // Masukkan penyanyi (Loop semua penyanyi)
    for (int i = 0; i < Penyanyi->neff; i++){
        

        // Banyak Album -> {2} BLACKPINK
        ADVWORD();
        int jlhalbum = WordToInt(takeword(currentWord,1));
        Album->count += jlhalbum;


        // Masukkan nama penyanyi ke ListPenyanyi -> 2 {BLACKPINK}
        valuetype namaP = WordToString(takekata(currentWord));
        Penyanyi->A[i] = namaP;


        // Masukkan Album (Loop semua album per setiap artist)
        for (int j = count1; j < Album->count; j++){


            // Masukkan banyak lagu dalam suatu album ke MapAlbum
            // {4} BORN PINK
            ADVWORD();
            int jlhlagu = WordToInt(takeword(currentWord,1));
            SetSong->count+=jlhlagu;


            // Ambil nama album 4 {BORN PINK}
            valuetype namaA = WordToString(takekata(currentWord));

            // Masukkan data ke Album
            Album->Elements[count1].keyAlbum = keymaker;
            keymaker++;
            Album->Elements[count1].IdPenyanyi = i+1;
            Album->Elements[count1].valueAlbum = namaA;
            count1++;

            // Masukkan lagu (loop lagu per setiap album)
            for (int k = count2; k < SetSong->count; k++){
                ADVWORD();

                // Ambil nama lagu
                valuetype namaL = WordToString(currentWord);

                // Masukkan ke Song
                SetSong->Elements[count2].Idalbum = count1;
                SetSong->Elements[count2].namalagu = namaL;
                count2++;
            }
        }
    }

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
    // Masukkan banyak songs ke Queue queue
    int banyakQueueSongs = wordtointmustvalid(currentWord);
    printf("Banyaksongnya: %d\n", banyakQueueSongs);
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
    CreateEmptyS(&HistoryRAW); // Sebelum direverse // Final setelah direverse

    // Masukkan banyak songs riwayat
    int banyakHistorySongs = wordtointmustvalid(currentWord);

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

    // Banyak Playlist
    int banyakDinPlaylist = wordtointmustvalid(currentWord);
    
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
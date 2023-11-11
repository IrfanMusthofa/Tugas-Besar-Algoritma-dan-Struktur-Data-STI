#include "../ADT/MesinKalimat/mesinkarakter.h"
#include "../ADT/MesinKalimat/mesinkata.h"
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

// Mengubah .txt menjadi ADT

void MakeEmpty(ListPenyanyi *Penyanyi,MapAlbum *Album,SetSong *Song){
    Penyanyi->neff = 0;
    Album->count = 0;
    Song->count = 0;

    // for(int i = 0;i<NMAX;i++){
    //     Penyanyi->A[i] = EMPTY;
    // }

    // for(int i = 0;i<NMAX;i++){
    //     Album->Elements[i].valueAlbum = EMPTY;
    // }

    // for(int i = 0;i<NMAX;i++){
    //     Song->Elements[i].valueSong = EMPTY;
    // }
}

void STARTCOM(ListPenyanyi *Penyanyi, MapAlbum *Album, SetSong *Song, char *file){
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
    Song->count = 0;


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
            Song->count+=jlhlagu;


            // Ambil nama album 4 {BORN PINK}
            valuetype namaA = WordToString(takekata(currentWord));

            // Masukkan data ke Album
            Album->Elements[count1].keyAlbum = keymaker;
            keymaker++;
            Album->Elements[count1].IdPenyanyi = i+1;
            Album->Elements[count1].valueAlbum = namaA;
            count1++;

            // Masukkan lagu (loop lagu per setiap album)
            for (int k = count2; k < Song->count; k++){
                ADVWORD();

                // Ambil nama lagu
                valuetype namaL = WordToString(currentWord);

                // Masukkan ke 
                Song->Elements[count2].IdAlbum = count1;
                Song->Elements[count2].namaP = namaP;
                Song->Elements[count2].namaA = namaA;
                Song->Elements[count2].namaS = namaL;
                count2++;
            }
        }
    }
}
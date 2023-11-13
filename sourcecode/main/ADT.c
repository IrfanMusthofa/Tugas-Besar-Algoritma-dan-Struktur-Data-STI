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

                // Masukkan ke Song
                Song->Elements[count2].Idalbum = count1;
                Song->Elements[count2].namalagu = namaL;
                count2++;
            }
        }
    }
}

IDs GetPenyanyiID(ListPenyanyi List, char *input){
    IDs id;
    for (int i = 0;i<List.neff;i++){
        char *compare = List.A[i];
        if (IsEqualString(input,compare)){
            id = i+1;
            break;
        }
    }
    return id;
}

IDs GetAlbumID (MapAlbum album, char *input){
    IDs id;
    for (int i = 0;i<album.count;i++){
        char *compare = album.Elements[i].valueAlbum;
        if (IsEqualString(input,compare)){
            id = i+1;
            break; 
        }
    }
    return id;

}

int JumlahAlbum (MapAlbum album, IDs idpenyanyi){
    int count;
    for (int i = 0;i<album.count;i++){
        if (idpenyanyi == album.Elements[i].IdPenyanyi){
            count++;
        }
    }
    return count;
}

int JumlahLagu (SetSong song, IDs idalbum){
    int count;
    for (int i = 0;i<song.count;i++){
        if (idalbum == song.Elements[i].Idalbum){
            count++;
        }
    }
    return count;
}

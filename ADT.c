#include "./src/mesinkarakter.h"
#include "./src/mesinkata.h"
#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

void MakeEmpty(List *Penyanyi,MapAlbum *Album,MapSong *Song){
    Penyanyi->neff = Nil;
    Album->count = Nil;
    Song->count = Nil;

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

void STARTCOM(List *Penyanyi,MapAlbum *Album,MapSong *Song){
    printf("init");
    char *file = "config.txt";
    STARTWORD(file);
    printf("ialize\n");
    int jlhPenyanyi=0;
    char *tes = currentWord.TabWord;
    while ((*tes)!='\0'){
        if (((*tes=='0') || (*tes=='1') || (*tes=='2') || (*tes=='3') || (*tes=='4') || (*tes=='5') || (*tes=='6') || (*tes=='7') || (*tes=='8') ||(*tes=='9'))){
            jlhPenyanyi *=10;
            jlhPenyanyi+=(*tes)-'0';
        }
        tes++;
    }
    Penyanyi->neff = jlhPenyanyi;
    Album->count = 0;
    Song->count = 0;

    int count1=0,count2=0;
    for (int i = 0;i<Penyanyi->neff;i++){
        ADVWORD();
        int jlhalbum = WordToInt(takeword(currentWord,1));
        Album->count+=jlhalbum;

        valuetype namaP = WordToString(takekata(currentWord));
        Penyanyi->A[i] = namaP;
        // printf("%d. %s\n",i+1,Penyanyi->A[i]);
        for (int j = count1;j<Album->count;j++){
            ADVWORD();
            int jlhlagu = WordToInt(takeword(currentWord,1));
            Song->count+=jlhlagu;

            valuetype namaA = WordToString(takekata(currentWord));
            Album->Elements[count1].keyAlbum = i;
            Album->Elements[count1].valueAlbum = namaA;
            count1++;

            for (int k=count2;k<Song->count;k++){
                ADVWORD();
                valuetype namaL = WordToString(currentWord);
                Song->Elements[count2].keySong = count1;
                Song->Elements[count2].valueSong = namaL;
                count2++;
                // printf("    %d. %s\n",Song->Elements[k].keySong+1,Song->Elements[k].valueSong);
            }
        }

    }
}
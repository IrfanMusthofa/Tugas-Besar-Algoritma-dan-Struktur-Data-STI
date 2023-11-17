#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ADT.h"
#include "mesinkata.h"
#include "playlist.h"
#include "pick.h"

void playlistcreate(ArrayDinPlaylist *array){
    boolean hasil = false;
    valuetype namaPlaylist;
    while (! hasil)
    {
        printf("Masukkan nama playlist yang ingin dibuat : ");
        STARTINPUTKATA();
        hapustikom(&currentWord);
        printf("\n");
        Word cek = takenonspace(currentWord);
        if (cek.Length == 0){
            printf("Minimal terdapat 3 karakter selain white space dalam nama playlist. Silakan coba lagi.\n");
        } 
        else if (cek.Length < 3){
            printf("Minimal terdapat 3 karakter. Silakan coba lagi.");
        }
        else{
            namaPlaylist = WordToString(currentWord);
            hasil = true;
        }

    }
    CreatePlaylist(array, namaPlaylist);
    printf("Playlist %s berhasil dibuat!\n", namaPlaylist);
    printf("Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
}

void tambahlaguplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array){
    listp(Penyanyi);
    valuetype namaP = pickpenyanyi(Penyanyi);
    int idP;
    listalbum(Penyanyi, Album, namaP, &idP);
    valuetype namaA = pickalbum(Album, idP);
    ListStatic L= MakeListStatis();
    listlagu(Album, lagu, namaA, &L);
    valuetype namaL = picklagu(L);
    Song tSong;
    tSong = CreateSong(namaP, namaA, namaL);
    listplaylist(*array);
    int indexP = pickplaylist(*array);
    valuetype namaPl = array->playlist[indexP].namaPlaylist;
    PlaylistAddSong(array, indexP, tSong);
    printf("Lagu dengan judul '%s' pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.", namaL, namaA, namaP, namaPl);

}

void tambahalbumplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array){
    listp(Penyanyi);
    valuetype namaP = pickpenyanyi(Penyanyi);
    int idP;
    listalbum(Penyanyi, Album, namaP, &idP);
    valuetype namaA = pickalbum(Album, idP);
    listplaylist(*array);
    int indexP = pickplaylist(*array);
    Song listS[20];
    int n = 0; //index penanda

    IDs id = GetAlbumID(Album, namaA);
    for (int i = 0; i < lagu.count; i++){
        if (lagu.Elements[i].Idalbum == id){
            listS[n] = CreateSong(namaP, namaA, lagu.Elements[i].namalagu);
            n++;
        }
    }

    for(int j = 0; j < n; j++){
        PlaylistAddSong(array, indexP, listS[j]);
    }

}

void swapplaylist(ArrayDinPlaylist *array, int idP, int x, int y){
    if (idP > array->Neff || idP <= 0){
        printf("Tidak ada playlist dengan playlist ID %d\n", idP);
    } else{
        int n = NbElmt(array->playlist[idP - 1]);
        if (x <= 0 || x > n){
            printf("Tidak ada lagu dengan urutan %d di playlist'%s'\n", x, array->playlist[idP - 1].namaPlaylist);
        }
        if (y <= 0 || y > n){
            printf("Tidak ada lagu dengan urutan %d di playlist'%s'\n", y, array->playlist[idP - 1].namaPlaylist);
        }
        else{
            tukarplaylist(array, idP, x, y);
        }
    }
}

void removeplaylist(ArrayDinPlaylist *array, int idP, int x){
    if (idP > array->Neff || idP <= 0){
        printf("Tidak ada playlist dengan playlist ID %d\n", idP);
    } else{
        int n = NbElmt(array->playlist[idP - 1]);
        if (x <= 0 || x > n){
            printf("Tidak ada lagu dengan urutan %d di playlist'%s'\n", x, array->playlist[idP - 1].namaPlaylist);
        }
        else{
            ;
        }
    }
}

void deleteplaylist();
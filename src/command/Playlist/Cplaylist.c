#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../../main/ADT.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../ADT/Playlist/playlist.h"
#include "../Pick/pick.h"

/* Membuat playlist baru */
/* IS : arraydinplaylist terdefinisi */
/* FS : akan terbentuk playlist dengan nama tertentu */
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
            printf("Minimal terdapat 3 karakter. Silakan coba lagi.\n");
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

/* Menambahkan lagu pada playlist tertentu */
/* IS : arraydinplaylist terdefinisi, mapalbum, set song, dan listpenyanyi  */
/* FS : akan terbentuk playlist dengan nama tertentu */
void tambahlaguplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array){
    if (IsEmptyArrayDin(*array)){
        printf("Playlist kosong, tidak ada yang bisa ditambahkan.\n");
    } else {
        listp(Penyanyi);
        valuetype namaP = pickpenyanyi(Penyanyi);
        int idP;
        listalbum(Penyanyi, Album, namaP, &idP);
        valuetype namaA = pickalbum(Album, idP);
        ListStatic L= MakeListStatis();
        listlagu(Album, lagu, namaA, &L, namaP);
        valuetype namaL = picklagu(L);
        Song tSong;
        tSong = CreateSong(namaP, namaA, namaL);
        listplaylist(*array);
        int indexP = pickplaylist(*array);
        valuetype namaPl = array->playlist[indexP].namaPlaylist;
        PlaylistAddSong(array, indexP, tSong);
        printf("Lagu dengan judul '%s' pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", namaL, namaA, namaP, namaPl);
    }
}

/* Menambahkan album pada playlist tertentu, apabila lagu sudah ada, tidak dimasukkan */
/* IS : arraydinplaylist terdefinisi, mapalbum, set song, dan listpenyanyi  */
/* FS : album ditambahkan pada playlist */
void tambahalbumplaylist(ListPenyanyi Penyanyi, MapAlbum Album, SetSong lagu, ArrayDinPlaylist *array){
    if(IsEmptyArrayDin(*array)){
        printf("Playlist kosong, tidak ada album yang bisa ditambahkan.\n");
    } else {
        listp(Penyanyi);
        valuetype namaP = pickpenyanyi(Penyanyi);
        int idP;
        listalbum(Penyanyi, Album, namaP, &idP);
        valuetype namaA = pickalbum(Album, idP);
        listplaylist(*array);
        int indexP = pickplaylist(*array);
        Song listS[50];
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
        printf("Album dengan judul '%s' telah ditambahkan ke dalam playlist pengguna '%s'.\n", namaA, array->playlist[indexP].namaPlaylist);
    }
}

/* Menukar urutan lagu pada playlist tertentu */
/* IS : arraydinplaylist terdefinisi, idP adalah ID playlist yang ingin ditukar, x dan y adalah urutan lagu  */
/* FS : lagu akan ditukar dengan urutan x dan y apabila IDp, x, dan y valid*/
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

/* menghapus lagu di playlist dengan ID idP, dengan urutan lagu x */
/* IS : arraydinplaylist terdefinisi, idP adalah ID playlist yang ingin ditukar, x adalah urutan lagu  */
/* FS : lagu dengan urutan x pada playlist id idP, akan terhapus apabila valid */
void removeplaylist(ArrayDinPlaylist *array, int idP, int x){
    if (idP > array->Neff || idP <= 0){
        printf("Tidak ada playlist dengan playlist ID %d\n", idP);
    } else{
        int n = NbElmt(array->playlist[idP - 1]);
        if (x <= 0 || x > n){
            printf("Tidak ada lagu dengan urutan %d di playlist'%s'\n", x, array->playlist[idP - 1].namaPlaylist);
        }
        else{
            Song S;
            DeleteLaguPlaylist(array, idP, x, &S);
            printf("Lagu '%s' oleh '%s' telah dihapus dari playlist '%s'\n", S.namaS, S.namaP, array->playlist[idP - 1].namaPlaylist);
        }
    }
}

/* menghapus playlist */
/* IS : arraydinplaylist terdefinisi */
/* FS : playlist yang dipilih akan terhapus */
void hapusplaylist(ArrayDinPlaylist *array){
    listplaylist(*array);
    if(IsEmptyArrayDin(*array)){
        printf("Playlist kosong, tidak ada yang bisa dihapus.\n");
    } else {
        int idplaylist = pickplaylist(*array);
        printf("Playlist ID %d dengan judul '%s' berhasil dihapus. \n", (idplaylist + 1), array->playlist[idplaylist].namaPlaylist);
        DeletePlaylist(array, idplaylist);
    }
}

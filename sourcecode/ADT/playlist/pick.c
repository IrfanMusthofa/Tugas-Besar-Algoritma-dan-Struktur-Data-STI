#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "ADT.h"
#include <stdio.h>
#include "list.h"

void listp(ListPenyanyi Penyanyi){
    printf("Daftar Penyanyi :\n");
    for (int i = 0;i < Penyanyi.neff; i++){
        printf("%d. %s\n", i + 1, Penyanyi.A[i]);
    }
}

valuetype pickpenyanyi(ListPenyanyi Penyanyi){
    valuetype singer;
    boolean found = false;
    while(! found){
        printf("Masukkan nama penyanyi yang dipilih : ");
        STARTINPUTKATA();
        printf("\n");
        singer = WordToString(currentWord);
        for (int i = 0; i < Penyanyi.neff; i++){
            if (IsEqual(currentWord, Penyanyi.A[i])){
                found = true;
                break;
            } else{
                found = false;
            }
        }
        if (!found){
            // ubah current word ke string
            printf("Penyanyi %s tidak ada dalam daftar, silakan coba lagi\n", singer);
        }   
    }  
    return singer;
}

void listalbum(ListPenyanyi list, MapAlbum album, valuetype penyanyi, IDs *id){
    *id = GetPenyanyiID(list, penyanyi);
    int j = 1; //ini buat nomor aja sebenarnya;
    printf("Daftar album oleh %s : \n", penyanyi);
    for (int i = 0; i < album.count; i++){
        if (album.Elements[i].IdPenyanyi == *id){
            printf("%d. %s\n", j, album.Elements[i].valueAlbum);
            j ++;
        }
    }

}

valuetype pickalbum(MapAlbum Album, IDs id){
    valuetype album;
    boolean found = false;
    while(! found){
        printf("Masukkan nama album yang dipilih : ");
        STARTINPUTKATA();
        printf("\n");
        album = WordToString(currentWord);
        for (int i = 0; i < Album.count; i++){
            if (IsEqual(currentWord, Album.Elements[i].valueAlbum)){
                if(Album.Elements[i].IdPenyanyi == id){
                    found = true;
                    break;
                }
            } else{
                found = false;
            }
        }
        if (!found){
            printf("Album %s tidak ada dalam daftar, silakan coba lagi\n", album);
        }   
    }  
    return album;
}
void listlagu(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L){
    IDs id = GetAlbumID(album, namaA);
    int j = 1; //ini buat nomor aja sebenarnya;
    printf("Daftar lagu oleh %s : \n", namaA);
    for (int i = 0; i < song.count; i++){
        if (song.Elements[i].Idalbum == id){
            printf("%d. %s\n", j, song.Elements[i].namalagu);
            InsertLast(L, song.Elements[i].namalagu);
            j ++;
        }
    }
}

valuetype picklagu(ListStatic L){
    valuetype lagu;
    boolean found = false;
    while(! found){
        printf("Masukkan ID lagu yang dipilih : ");
        STARTINPUTKATA();
        printf("\n");
        int ID = WordToInt(currentWord);
        if (ID > 0 && ID <= L.Neff){
            found = true;
            lagu = L.A[ID-1];
        }
        if (!found){
            printf("ID %d tidak ada dalam daftar, silakan coba lagi\n", ID);
        }   
    }  
    return lagu;
}
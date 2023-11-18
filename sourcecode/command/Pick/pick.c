#include "boolean.h"
#include "../../ADT/MesinKalimat/mesinkata.h"
#include "../../ADT/MesinKalimat/mesinkarakter.h"
#include "../../main/ADT.h"
#include "../List/list.h"
/* Menampilkan list penyanyi */
/* IS : list penyanyi terdefinisi */
/* FS : akan ditampilkan list penyanyi yang ada */
void listp(ListPenyanyi Penyanyi){
    printf("Daftar Penyanyi :\n");
    for (int i = 0;i < Penyanyi.neff; i++){
        printf("%d. %s\n", i + 1, Penyanyi.A[i]);
    }
}
/* memilih penyanyi, input dari user */
/* IS : list penyanyi terdefinisi */
/* FS : akan mengembalikan penyanyi yang diinputkan dengan benar */
valuetype pickpenyanyi(ListPenyanyi Penyanyi){
    valuetype singer;
    boolean found = false;
    while(! found){
        printf("Masukkan nama penyanyi yang dipilih : ");
        STARTINPUTKATA();
        hapustikom(&currentWord);
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
/* Menampilkan list album */
/* IS : list penyanyi, mapalbum terdefinisi, penyanyi yang ingin ditampilkan albumnya */
/* FS : akan ditampilkan list album yang ada, dan idS akan menjadi id dari id penyanyi */
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

/* memilih album, input dari user */
/* IS : map album terdefinisi, id album terdefinisi */
/* FS : akan mengembalikan album yang diinputkan dengan benar */
valuetype pickalbum(MapAlbum Album, IDs id){
    valuetype album;
    boolean found = false;
    while(! found){
        printf("Masukkan nama album yang dipilih : ");
        STARTINPUTKATA();
        hapustikom(&currentWord);
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
/* Menampilkan list lagu */
/* IS : MapAlbum, SetSong, namaalbum, dan liststatic terdefinisi */
/* FS : akan ditampilkan list lagu yang ada, dan list static L akan berisi lagu-lagu dari album tersebut  */
void listlagu(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L){
    IDs id = GetAlbumID(album, namaA);
    int j = 1; //ini buat nomor aja sebenarnya;
    printf("Daftar lagu oleh %s : \n", namaA);
    for (int i = 0; i < song.count; i++){
        if (song.Elements[i].Idalbum == id){
            printf("%d. %s\n", j, song.Elements[i].namalagu);
            InsertLastListStatis(L, song.Elements[i].namalagu);
            j ++;
        }
    }
}

/* memilih lagu, input dari user */
/* IS : list static terdefinisi */
/* FS : akan mengembalikan lagu yang diinputkan dengan benar */
valuetype picklagu(ListStatic L){
    valuetype lagu;
    boolean found = false;
    while(! found){
        printf("Masukkan ID lagu yang dipilih : ");
        STARTINPUTKATA();
        hapustikom(&currentWord);
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

/* Menampilkan listplaylist */
/* IS : Arraydinplaylist terdefinisi */
/* FS : akan ditampilkan  list playlist yang ada*/
void listplaylist(ArrayDinPlaylist P){
    printf("Daftar Playlist :\n");
    for (int i = 0;i < P.Neff; i++){
        printf("%d. %s\n", i + 1, P.playlist[i].namaPlaylist);
    }
}

/* memilih playlist */
/* IS : Arraydinplaylist terdefinisi */
/* FS : memilih playlist, akan mengambalikan id*/
IDs pickplaylist(ArrayDinPlaylist P){
    boolean found = false;
    IDs indexPlaylist;
    while(! found){
        printf("Masukkan ID Playlist yang dipilih : ");
        STARTINPUTKATA();
        printf("\n");
        hapustikom(&currentWord);
        int ID = WordToInt(currentWord);
        if (ID > 0 && ID <= P.Neff){
            found = true;
            indexPlaylist = ID - 1;
        }
        if (!found){
            printf("ID %d tidak ada dalam daftar, silakan coba lagi\n", ID);
        }   
    }  
    return indexPlaylist;
}
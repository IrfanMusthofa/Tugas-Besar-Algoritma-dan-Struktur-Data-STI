#include <stdio.h>
#include "Clist.h"


/* Memilih penyanyi di list default */
/* IS: List penyanyi terdefinisi */
/* FS: Mengembalikan penyanyi yang dipilih */
valuetype pickpenyanyilist(ListPenyanyi Penyanyi)
{
    valuetype singer;
    boolean found = false;
    while(! found){
        boolean cek = false;
        while (!cek)
        {
            printf("Pilih penyanyi untuk melihat album mereka: ");
            STARTINPUTKATA();
            printf("\n");
            if(currentWord.TabWord[currentWord.Length-1] == ';'){
                cek = true;
            } else{
                printf("Jangan lupa pakai titik koma. Silakan coba lagi.\n");
            }
        }
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
            printf("Penyanyi %s tidak ada dalam daftar, silakan coba lagi\n", singer);
        }   
    }  
    return singer;
}

/* Memilih album di list default */
/* IS: Album terdefinisi, dan id penyanyi terdefinisi */
/* FS: Mengembalikan penyanyi yang dipilih */
valuetype pickalbumlist(MapAlbum Album, IDs id)
{
    valuetype album;
    boolean found = false;
    while(! found){
        boolean cek = false;
        while (!cek)
        {
            printf("Pilih album untuk melihat lagu yang ada di album : ");
            STARTINPUTKATA();
            printf("\n");
            if(currentWord.TabWord[currentWord.Length-1] == ';'){
                cek = true;
            } else{
                printf("Jangan lupa pakai titik koma. Silakan coba lagi.\n");
            }
        }
        
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
void listlagudefault(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L, valuetype namaP){
    IDs id = GetAlbumID(album, namaA);
    boolean found = false;

    int j = 1; //ini buat nomor aja sebenarnya;
    printf("Daftar Lagu di %s: \n", namaA);
    for (int i = 0; i < song.count; i++){
        if (song.Elements[i].Idalbum == id){
            printf("%d. %s\n", j, song.Elements[i].namalagu);
            InsertLastListStatis(L, song.Elements[i].namalagu);
            j ++;
        }
    }
}

/* Menampilkan list dari penyanyi, album, dan lagunya */
/* IS: Penyanyi terdefinisi, map album, dan setsong */
/* FS: Menampilkan list default */
void listdefault(ListPenyanyi Penyanyi, MapAlbum album, SetSong song)
{
    listp(Penyanyi);
    boolean cek = false;
    while (!cek)
    {
        printf("\nIngin melihat album yang ada? (Y/N) : ");
        STARTINPUTKATA(); //diinput dengan 'Y' atau 'N'
        printf("\n");
        if(currentWord.TabWord[currentWord.Length-1] == ';'){
            cek = true;
        } else{
            printf("Jangan lupa pakai titik koma. Silakan coba lagi.\n");
        }
    }
    hapustikom(&currentWord);
    valuetype salah = "N";
    valuetype benar = "Y";

    if (IsEqual(currentWord, benar))
    {
        valuetype namap = pickpenyanyilist(Penyanyi);
        IDs idpenyanyi;
        //menampilkan list album
        listalbum(Penyanyi, album, namap, &idpenyanyi);
            boolean cek = false;
        while (!cek)
        {
            printf("\nIngin melihat lagu yang ada? (Y/N): ");
            STARTINPUTKATA();
            printf("\n");
            if(currentWord.TabWord[currentWord.Length-1] == ';'){
                cek = true;
            } else{
                printf("Jangan lupa pakai titik koma. Silakan coba lagi.\n");
            }
        }

        hapustikom(&currentWord);
        if (IsEqual(currentWord, benar))
        {
            valuetype namaA = pickalbumlist(album,idpenyanyi);
            ListStatic list = MakeListStatis();
            listlagudefault(album, song, namaA, &list, namap);
        } 
        else if (IsEqual(currentWord, salah)){

        } else{
            valuetype input = WordToString(currentWord);
            printf("Input %s tidak terdefinisi\n", input);
        }
    }
    else if (IsEqual(currentWord, salah)){
        
    } else{
        valuetype input = WordToString(currentWord);
        printf("Input %s tidak terdefinisi\n", input);
    }

}

/* Menampilkan listplaylist */
/* IS : Arraydinplaylist terdefinisi */
/* FS : akan ditampilkan  list playlist yang ada*/
void Dlistplaylist(ArrayDinPlaylist B)
{
    if (IsEmptyArrayDin(B))
    {
        printf("Kamu tidak memiliki playlist.\n");
    }
    else
    {
        printf("\nDaftar playlist yang kamu miliki:\n");
        for (int i = 0;i < B.Neff; i++){
            printf("    %d. %s\n", i + 1, B.playlist[i].namaPlaylist);
        }

    }
}

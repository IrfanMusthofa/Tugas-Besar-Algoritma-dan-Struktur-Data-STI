#include <stdio.h>
#include "listdefault.h"


valuetype pickpenyanyilist(ListPenyanyi Penyanyi)
{
    valuetype singer;
    boolean found = false;
    while(! found){
        printf("Pilih penyanyi untuk melihat album mereka: ");
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

valuetype pickalbumlist(MapAlbum Album, IDs id)
{
    valuetype album;
    boolean found = false;
    while(! found){
        printf("Pilih album untuk melihat lagu yang ada di album : ");
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


/*void listlagu(MapAlbum album, SetSong song, valuetype namaA, ListStatic *L)
{
    IDs id = GetAlbumID(album, namaA);
    int j = 1; //ini buat nomor aja sebenarnya;
    printf("Daftar lagu di %s : \n", namaA);
    for (int i = 0; i < song.count; i++){
        if (song.Elements[i].Idalbum == id){
            printf("%d. %s\n", j, song.Elements[i].namalagu);
            InsertLastListStatis(L, song.Elements[i].namalagu);
            j ++;
        }
    }
}
*/
/*valuetype picklagulist(ListStatic L);
{
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
*/
void listdefault(ListPenyanyi Penyanyi, MapAlbum album, SetSong song)
{
    printf("\n");
    listp(Penyanyi);

    printf("Ingin melihat album yang ada? (Y/N) : ");
   
    STARTINPUTKATA(); //diinput dengan 'Y' atau 'N'
    printf("\n");

    if (IsEqual(currentWord, 'Y'))
    {
        //printf("Pilih penyanyi untuk melihat album mereka: ");
        pickpenyanyilist(Penyanyi);
        valuetype namap=pickpenyanyilist(Penyanyi);
        IDs idpenyanyi;
        listalbum(Penyanyi, album, namap, &idpenyanyi);

        printf("\n");
        printf("Ingin melihat lagu yang ada? (Y/N): ");
        STARTINPUTKATA();
        printf("\n");
        if (IsEqual(currentWord, 'Y'))
        {
            //printf("Pilih album untuk melihat lagu yang ada di album :");
            //IDs id;
            pickalbumlist(album,idpenyanyi);
        
            valuetype namaalbum;
            ListStatic *list;
            listlagu(album, song, namaalbum, &list);
        }
    }
    else if (IsEqual(currentWord, 'N')){
        printf("");
    }
}



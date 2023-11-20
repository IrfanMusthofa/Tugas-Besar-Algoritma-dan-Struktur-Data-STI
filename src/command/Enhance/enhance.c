#include <stdio.h>
#include "enhance.h"
#include <time.h>
#include <stdlib.h>



void enhanceplaylist(ArrayDinPlaylist *array, ListPenyanyi Penyanyi, MapAlbum Album, SetSong song){
    if(IsEmptyArrayDin(*array)){
        printf("Playlist kosong, tidak ada yang bisa dienhance\n");
    } else{
        // ini buat list buat nampung seluruh lagu di config
        Song listlaguconfig[100];
        int n = 0;
        for (int i = 0; i < Penyanyi.neff; i++){
            for (int j = 0; j < Album.count; j++){
                for (int k = 0; k < song.count; k++){
                    int id = GetPenyanyiID(Penyanyi, Penyanyi.A[i]);
                    if(Album.Elements[j].IdPenyanyi == id){
                        int idAlbum = GetAlbumID(Album, Album.Elements[j].valueAlbum);
                        if(song.Elements[k].Idalbum == idAlbum){
                            listlaguconfig[n] = CreateSong(Penyanyi.A[i], Album.Elements[j].valueAlbum, song.Elements[k].namalagu);
                            n++;
                        }
                    }
                }
            }
        }
        // milih playlist yang dienhance
        printf("Silakan pilih playlist yang akan dienhance.\n");
        listplaylist(*array);
        int idxP = pickplaylist(*array);
        // merandom banyak lagu yang akan dimasukkan
        int banyaklaguplaylist = NbElmt(array->playlist[idxP]);
        int nlagurandom = rand() % (banyaklaguplaylist - 1 + 1) + 1;
        int d = 1; // buat numbering aja
        boolean found = false; // penanda kalau ada yang dienhance
        for (int a = 0; a < nlagurandom; a++){
            // ngerandomin index yang bakal dimasukkin ke playlist
            int nilaiAcak = rand() % ((n-1) - 0 + 0) + 0;
            // dimasukkin ke playlist kalau gak ada lagunya
            if (!SearchLaguPlaylist(array->playlist[idxP], listlaguconfig[nilaiAcak].namaS)){
                if(d == 1){
                    printf("Lagu yang ditambahkan ke playlist '%s' adalah \n", array->playlist[idxP].namaPlaylist);
                    found = true;
                }
                InsVLast(&(array->playlist[idxP]), listlaguconfig[nilaiAcak]);
                printf("%d. %s - %s - %s\n", d, listlaguconfig[nilaiAcak].namaP, listlaguconfig[nilaiAcak].namaA, listlaguconfig[nilaiAcak].namaS);
                d++;
            }
        }
        if(!found){
            printf("Tidak ada lagu yang direkomendasikan.\n");
        }



    }
}
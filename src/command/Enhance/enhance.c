#include <stdio.h>
#include "enhance.h"
#include <time.h>
#include <stdlib.h>

int generateRandomNumber(int minValue, int maxValue) {
    // Inisialisasi seed generator acak berdasarkan waktu saat ini
    srand(time(NULL));

    // Menghasilkan bilangan acak dalam rentang [minValue, maxValue]
    int randomNumber = rand() % (maxValue - minValue + 1) + minValue;

    return randomNumber;
}

void enhanceplaylist(ArrayDinPlaylist *array, ListPenyanyi Penyanyi, MapAlbum Album, SetSong song){
    if(IsEmptyArrayDin(*array)){
        printf("Playlist kosong, tidak ada yang bisa dienhance\n");
    } else{
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
        printf("Silakan pilih playlist yang akan dienhance.\n");
        listplaylist(*array);
        int idxP = pickplaylist(*array);
        int banyaklaguplaylist = NbElmt(array->playlist[idxP]);
        // banyaknya lagu yang akan dimasukkan random
        int nlagurandom = generateRandomNumber(1, banyaklaguplaylist /2);
        
        // buat list untuk menampung angka random
        printf("Lagu yang ditambahkan ke playlist '%s' adalah \n", array->playlist[idxP].namaPlaylist);
        int d = 1;
        for (int a = 0; a < nlagurandom; a++){
            int indexlagurandom = generateRandomNumber(0, n-1);
            if (!SearchLaguPlaylist(array->playlist[idxP], listlaguconfig[indexlagurandom].namaS)){
                InsVLast(&(array->playlist[indexlagurandom]), listlaguconfig[indexlagurandom]);
                printf("%d. %s - %s - %s\n", d, listlaguconfig[indexlagurandom].namaP, listlaguconfig[indexlagurandom].namaA, listlaguconfig[indexlagurandom].namaS);
                d++;
            }
        }



    }
}
#include <stdio.h>
#include "enhance.h"
#include <time.h>
#include <stdlib.h>

void enhanceplaylist(ArrayDinPlaylist *array){
    if(IsEmptyArrayDin(*array)){
        printf("Playlist kosong, tidak ada yang bisa dienhance\n");
    } else{
        ListPenyanyi Penyanyi;
        MapAlbum Album;
        SetSong song;
        Song listlaguconfig[100];
        int n = 0;
        char *file = "../../config/config.txt";
        STARTCOM(&Penyanyi,&Album,&song, file);
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
    }
}
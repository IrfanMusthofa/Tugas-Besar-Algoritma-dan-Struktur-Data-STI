/*
========= *** Command Save *** =========

"Menyimpan hasil default config.txt dan 
perubahan dari user yang telah menguna-
kan WayangWave."

*/



/* ========= *** Include *** =========*/

#include <stdio.h>
#include <stdlib.h>
#include "save.h"



/* ========= *** Prosedur save *** =========

I.S : Sembarang
F.S : config.txt dimasukkan paling awal seb-
agai default, lalu ditambahkan CurrentSong 
yang berisi lagu terakhir yang dimainkan, 
Queue dari lagu, Stack dari riwayat lagu,
dan ArrayDinPlaylist dari Playlist lagu.

*/
void save(char *filename, ListPenyanyi Penyanyi, MapAlbum Album, SetSong Song, queue antrian, Stack history, ArrayDinPlaylist playlist, CurrentSong LaguSekarang) {

    // KAMUS LOKAL
    FILE *fsave;
    
    // ALGORITMA

    // Create file
    char *savefile = ConcateChar("./src/config/", filename);
    fsave = fopen(savefile, "w+");


    // PRINT OUT Penyanyi, Album, Song
    fprintf(fsave, "%d\n", Penyanyi.neff); // Print Out Banyak Penyanyi

    int p = 0; // untuk access album to setsong
    int q = 0; // untuk access song

    for (int i = 0; i < Penyanyi.neff; i++) { // Loop sebanyak penyanyi

        // Print Out banyak Album & Penyanyi ke-i
        int banyakAlbum = JumlahAlbum(Album, i + 1);
        fprintf(fsave, "%d %s\n", banyakAlbum, Penyanyi.A[i]); 
    


        // Loop sebanyak Album 
        for (int j = 0; j < banyakAlbum; j++) { 

            // Print Out banyak lagu dan nama album ke - j
            int banyakLagu = JumlahLagu(Song, p + 1);
            fprintf(fsave, "%d %s\n", banyakLagu, Album.Elements[p].valueAlbum);



            // Loop sebanyak lagu
            for (int k = 0; k < banyakLagu; k++) {
                fprintf(fsave, "%s\n", Song.Elements[q].namalagu); // Print out lagu
                
                q++; // Parsing SetSong.Elements
            }

            p++; // Parsing MapAlbum.Elements[p]
        }
    }

    // PRINT OUT Current Song
    valuetype CekKosong = "-";
    if (IsEqualString(LaguSekarang.namaP, CekKosong)) fprintf(fsave, "-\n");
    else fprintf(fsave, "%s;%s;%s\n", LaguSekarang.namaP, LaguSekarang.namaA, LaguSekarang.namaS);



    // PRINT OUT Queue

    // PRINT OUT banyak Queue
    fprintf(fsave, "%d\n", length(antrian));
    if (!isEmpty(antrian)) {
    
        // PRINT OUT lagu Queue 
        for (int i = 0; i < length(antrian); i++) fprintf(fsave, "%s;%s;%s\n", antrian.buffer[i].namaP, antrian.buffer[i].namaA, antrian.buffer[i].namaS);
    }



    // PRINT OUT History

    // PRINT OUT banyak History
    fprintf(fsave, "%d\n", Top(history) + 1);
    if (!IsEmptyS(history)) {
 
        // PRINT OUT lagu History
        for (int i = Top(history); i >= 0 ; i--) fprintf(fsave, "%s;%s;%s\n", history.T[i].namaP, history.T[i].namaA, history.T[i].namaS);
    }

    // PRINT OUT Playlist;

    // PRINT OUT banyak Playlist
    fprintf(fsave, "%d\n", playlist.Neff);
    if (playlist.Neff != 0) {
        
        // Loop sebanyak playlist yang ada
        for (int i = 0; i < playlist.Neff; i++) {

            // PRINT OUT banyak lagu dan nama sebuah Playlist
            int nbLagu = NbElmt(playlist.playlist[i]);
            fprintf(fsave, "%d %s\n", nbLagu, playlist.playlist[i].namaPlaylist);
            
            
            address Lagu = First(playlist.playlist[i]); // Playlist ke-i
            // PRINT OUT lagu dalam playlist
            for (int j = 0; j < nbLagu; j++) {
                fprintf(fsave, "%s;%s;%s\n", Info(Lagu).namaP, Info(Lagu).namaA, Info(Lagu).namaS);
                Lagu = Next(Lagu);
            }
        }
    }

    // CLOSE FILE
    fclose(fsave);
    printf("Save file: %s berhasil disimpan!\n", filename);
    
}
/* ========= *** END of save *** ========= */
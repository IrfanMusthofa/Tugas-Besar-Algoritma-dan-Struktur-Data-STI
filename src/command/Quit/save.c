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
void save(char *filename, ListPenyanyi Penyanyi, MapAlbum Album, SetSong Song, queue *antrian, Stack history, ArrayDinPlaylist playlist, CurrentSong LaguSekarang) {

    // KAMUS LOKAL
    FILE *fsave;
    
    // ALGORITMA

    // Create file
    char *savefile = ConcateChar("../../src/config/", filename);
    fsave = fopen(savefile, "w+");

    fprintf(fsave, "%d\n", Penyanyi.neff); // Print Out Banyak Penyanyi

    for (int i = 0; i < Penyanyi.neff - 1; i++) { // Loop sebanyak penyanyi

        // Print Out Banyak Album & Penyanyi
        int banyakAlbum = 0;
        for (int j = 0; i < Album.count; j++) {
            if (Album.Elements[j].IdPenyanyi == i + 1) banyakAlbum++; // Cek untuk IdPenyanyi yang sama
        } // IdPenyanyi dihitung dari 1

        fprintf(fsave, "%d ", banyakAlbum); // Banyak Album
        fprintf(fsave, "%s\n", Penyanyi.A[i]); // Nama Penyanyi



        // Print Out Banyak Lagu dalam Suatu Album & Nama Album
        for (int j = 0; i < Album.count; j++) {
            if (Album.Elements[j].IdPenyanyi == i + 1) {
                
            } // Cek untuk IdPenyanyi yang sama
        } // IdPenyanyi dihitung dari 1
    }
}

/* ========= *** END of save *** ========= */
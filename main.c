#include "mesinkarakter.h"
#include "mesinkata.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	/*KAMUS*/
    List penyanyi;
    Album album;
    // SetSongs setsong;
    char *file = "config.txt";
    valuetype namaP, namaA, namaL;
    int jumlahpenyanyi, jumlahalbum, jumlahlagu;

    /*ALGORITMA*/
    STARTWORD(file);
    jumlahpenyanyi = WordToInt(currentWord);
	penyanyi.nEff = jumlahpenyanyi;

	/*TES PROGRAM*/
    // printf("%d\n", penyanyi.nEff);
	// printf("%s", );
	// printf("tes\n")

	printf("%d\n", penyanyi.nEff);
	
	for (int i = 0; i < jumlahpenyanyi; i++){
		ADVWORD();
		//ambil jumlah album dan simpan pada count album
		Word takealbum = takeword(currentWord, 1);
		jumlahalbum = WordToInt(takealbum);
		penyanyi.contents[i].CountAlbum = jumlahalbum;
		
		//ambil nama penyanyi dan simpan pada ADT
		Word takepenyanyi = takekata(currentWord);
		namaP = WordToString(takepenyanyi);
		penyanyi.contents[i].namapenyanyi = namaP;
		printf("%s\n", penyanyi.contents[i].namapenyanyi);
		//lakukan perulangan untuk album
		for (int j = 0; j < jumlahalbum; j++){
			ADVWORD();
			//ambil jumlah lagu
			Word takelagu = takeword(currentWord, 1);
			jumlahlagu = WordToInt(takelagu);
			album.CountSong = jumlahlagu;
			// setsong.Count = jumlahlagu;
			//ambil nama album 
			Word takealbum = takekata(currentWord);
			namaA = WordToString(takealbum);
			penyanyi.contents[i].ElementsPenyanyi[j].namaalbum = namaA;
			penyanyi.contents[i].ElementsPenyanyi[j].KeyAlbum = j + 1;
			album.KeyAlbum =  j + 1;
			printf("%d\n", jumlahlagu);
			printf("%s\n", penyanyi.contents[i].ElementsPenyanyi[j].namaalbum);
			//lakukan perulangan untuk lagu
			
			for (int k = 0; k < jumlahlagu; k++){
				ADVWORD();
				//ambil nama lagu
				namaL = WordToString(currentWord);
				// printf("%s\n", namaL);
				album.ElementsAlbum[k].KeySong = k + 1;
				album.ElementsAlbum[k].lagu = namaL;
				// album.ElementsAlbum[k].lagu.nalbum = namaA;
				// album.ElementsAlbum[k].lagu.npenyanyi = namaP;
				printf("%s\n", album.ElementsAlbum[k].lagu);

			}

		}
	}
	
	// printf("%s", penyanyi.contents[0].namapenyanyi);
	// printf("halo");

}
	// ADVWORD();
	// 	Word takealbum = takeword(currentWord, 1);
	// 	jumlahalbum = WordToInt(takealbum);
	// 	Word takepenyanyi = takekata(currentWord);
	// 	namaP = WordToString(takepenyanyi);
	// 	penyanyi.contents[0].namapenyanyi = namaP;
	// 	printf("%s", penyanyi.contents[0].namapenyanyi);

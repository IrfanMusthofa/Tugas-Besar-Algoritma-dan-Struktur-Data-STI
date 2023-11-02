#include "mesinkarakter.h"
#include "mesinkata.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    List penyanyi;
	Album album;
	char *file = "config.txt";
    STARTWORD(file);
	char *namaP;
	char *namaA;
	char *namaL;
    int jumlahpenyanyi, jumlahalbum, jumlahlagu;
	jumlahpenyanyi = WordToInt(currentWord);
	penyanyi.nEff = jumlahpenyanyi;
	SetLagu setsong;
	
	for (int i = 0; i < jumlahpenyanyi; i++){
		ADVWORD();
		Word takealbum = takeword(currentWord, 1);
		jumlahalbum = WordToInt(takealbum);
		penyanyi.contents[i].CountAlbum = jumlahalbum;
		Word takepenyanyi = takekata(currentWord);
		namaP = WordToString(takepenyanyi);
		penyanyi.contents[i].namapenyanyi = namaP;
		for (int j = 0; j < jumlahalbum; j++){
			ADVWORD();
			Word takelagu = takeword(currentWord, 1);
			jumlahlagu = WordToInt(takelagu); 
			Word takealbum = takekata(currentWord);
			namaA = WordToString(takealbum);
			penyanyi.contents[i].ElementsPenyanyi[j].namaalbum = namaA;
			penyanyi.contents[i].ElementsPenyanyi[j].KeyAlbum = j + 1;
			album.namaalbum = namaA;
			album.CountSong = jumlahlagu;
			setsong.Count = jumlahlagu;
			printf("%d\n", jumlahlagu);
			for (int k = 0; k < jumlahlagu; k++){
				ADVWORD();
				namaL = WordToString(currentWord);
				album.ElementsAlbum[k].namalagu = namaL;
				album.ElementsAlbum[k].KeySong = k + 1;
				setsong.namaalbumlagu = namaA;
				setsong.namapenyanyilagu = namaP;
				setsong.lagu[k] = namaL;
			}
		}
	}
	
	printf("%d", penyanyi.nEff);

}
	// ADVWORD();
	// 	Word takealbum = takeword(currentWord, 1);
	// 	jumlahalbum = WordToInt(takealbum);
	// 	Word takepenyanyi = takekata(currentWord);
	// 	namaP = WordToString(takepenyanyi);
	// 	penyanyi.contents[0].namapenyanyi = namaP;
	// 	printf("%s", penyanyi.contents[0].namapenyanyi);

#include "mesinkarakter.h"
#include "mesinkata.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	printf("halo");
	List penyanyi;
	
    char *file = "config.txt";
    STARTWORD(file);
	char *namaP;
    int jumlahpenyanyi, jumlahalbum, jumlahlagu;
	jumlahpenyanyi = WordToInt(currentWord);
	printf("halo");
	// ADVWORD();
	// 	Word takealbum = takeword(currentWord, 1);
	// 	jumlahalbum = WordToInt(takealbum);
	// 	Word takepenyanyi = takekata(currentWord);
	// 	namaP = WordToString(takepenyanyi);
	// 	printf("halo");
		// penyanyi.contents[0].namapenyanyi = namaP;
		// printf("%s", penyanyi.contents[0].namapenyanyi);

	// for (int i = i; i < jumlahpenyanyi; i++){
	// 	ADVWORD();
	// 	Word takealbum = takeword(currentWord, 1);
	// 	jumlahalbum = WordToInt(takealbum);
	// 	Word takepenyanyi = takekata(currentWord);
	// 	namaP = WordToString(takepenyanyi);
	// 	penyanyi.contents[i].namapenyanyi = namaP;

	// }
	
	return 0;
}
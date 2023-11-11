#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main()
{
	Song X;
    X.IdAlbum = 1;
    X.namaA = "1989";
    X.namaP = "Taylor Swift";
    X.namaS = "Shake it Off";

    Song A;
    A.IdAlbum = 2;
    A.namaA = "Divide";
    A.namaP = "Ed Sheeran";
    A.namaS = "Formation";

    Song Y;
    Y.IdAlbum = 3;
    Y.namaA = "Random Access Memories";
    Y.namaP = "Daft Punk";
    Y.namaS = "Get Lucky";

    // Deklarasi dan inisialisasi objek Song B
    Song B;
    B.IdAlbum = 4;
    B.namaA = "25";
    B.namaP = "Adele";
    B.namaS = "Hello";

    // Inisialisasi objek Song 1
    Song song1 = {5, "In the Lonely Hour", "Sam Smith", "Stay With Me"};

    // Inisialisasi objek Song 2
    Song song2 = {6, "Reputation", "Taylor Swift", "Delicate"};

    // Inisialisasi objek Song 3
    Song song3 = {7, "Happier Than Ever", "Billie Eilish", "Therefore I Am"};

    // Inisialisasi objek Song 4
    Song song4 = {8, "Future Nostalgia", "Dua Lipa", "Don't Start Now"};

    // Inisialisasi objek Song 5
    Song song5 = {9, "Beauty Behind the Madness", "The Weeknd", "Can't Feel My Face"};
    
    List L;
    CreateEmpty(&L);
    InsVFirst(&L, X);
    InsVLast(&L,A);
    InsVLast(&L,Y);

	ArrayDinPlaylist arr = MakeArrayDin();;
	address P = First(L);
    int x = 1;
	InsertAt(&arr, P, x);
    address Q = arr.playlist[1].First;
    while(Q != NULL){
        printf("%s\n",Penyanyi(Q));      
        Q = Next(Q);
    }


}
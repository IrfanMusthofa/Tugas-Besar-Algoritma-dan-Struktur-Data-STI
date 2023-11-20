#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main()
{
	Song X;
    X.namaA = "1989";
    X.namaP = "Taylor Swift";
    X.namaS = "Shake it Off";

    Song A;
    A.namaA = "Divide";
    A.namaP = "Ed Sheeran";
    A.namaS = "Formation";

    Song Y;
    Y.namaA = "Random Access Memories";
    Y.namaP = "Daft Punk";
    Y.namaS = "Get Lucky";

    // Deklarasi dan inisialisasi objek Song B
    Song B;
    B.namaA = "25";
    B.namaP = "Adele";
    B.namaS = "Hello";

    // Inisialisasi objek Song 1
    Song song1 = {"In the Lonely Hour", "Sam Smith", "Stay With Me"};

    // Inisialisasi objek Song 2
    Song song2 = {"Reputation", "Taylor Swift", "Delicate"};

    // Inisialisasi objek Song 3
    Song song3 = {"Happier Than Ever", "Billie Eilish", "Therefore I Am"};

    // Inisialisasi objek Song 4
    Song song4 = {"Future Nostalgia", "Dua Lipa", "Don't Start Now"};

    // Inisialisasi objek Song 5
    Song song5 = {"Beauty Behind the Madness", "The Weeknd", "Can't Feel My Face"};
    printf("tes create list dan insert di linked list\n");
    List L;
    CreateEmpty(&L);
    InsVFirst(&L, X);
    InsVLast(&L,A);
    InsVLast(&L,Y);
    printf("tes make array din untuk menampung first dari linked list\n");
	ArrayDinPlaylist arr = MakeArrayDin();
	address P = First(L);
    int x = 0;
	InsertAt(&arr, P, x);
    printf("banyak playlist di array din setelah ditambah\n");
    printf("%d\n", arr.Neff);
    address Q = arr.playlist[0].First;
    printf("isi penyayi playlist yang telah ditambah\n");
    while(Q != NULL){
        printf("%s\n",Penyanyi(Q));      
        Q = Next(Q);
    }
    printf("tes buat playlist\n");
    CreatePlaylist(&arr, "kiminogatari");
    printf("%s\n", arr.playlist[1].namaPlaylist);
    printf("tes playlist add song\n");
    PlaylistAddSong(&arr, 1, song2);
    PlaylistAddSong(&arr, 1, song3);
    PlaylistAddSong(&arr, 1, song2);
    printf("tes search\n");
    address R = arr.playlist[1].First;
    printf("%d\n", SearchLaguPlaylist(arr.playlist[1], song2.namaS));
    printf("isi playlist kedua\n");
    while(R != NULL){
        printf("%s\n",Penyanyi(R));      
        R = Next(R);
    }
    printf("tes delete playlist\n");
    DeletePlaylist(&arr, 1);
    arr.playlist[0].namaPlaylist = "Playlist 1";
    for (int j = 0; j < arr.Neff; j++){
        printf("%s\n", arr.playlist[j].namaPlaylist);
    }
    printf("Tes length\n");
    printf("%d\n", Length(arr));
    CreatePlaylist(&arr, "Playlist 2");
    PlaylistAddSong(&arr, 1, song1);
    PlaylistAddSong(&arr, 1, song2);
    PlaylistAddSong(&arr, 1, song3);
    
}

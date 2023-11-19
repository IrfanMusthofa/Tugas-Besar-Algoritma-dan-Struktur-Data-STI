#include "ADT.h"
#include "song.h"

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong song;
    char *file = "config.txt";
    STARTCOM(&Penyanyi,&Album,&song, file);
    CurrentSong CS;
    CS.namaP = "Farah Aulia";
    CS.namaA = "ahay";
    CS.namaS = "hehe";
    Song song1 = {"In the Lonely Hour", "Sam Smith", "Stay With Me"};

    // Inisialisasi objek Song 2
    Song song2 = {"Reputation", "Taylor Swift", "Delicate"};

    // Inisialisasi objek Song 3
    Song song3 = {"Happier Than Ever", "Billie Eilish", "Therefore I Am"};

    // Inisialisasi objek Song 4
    Song song4 = {"Future Nostalgia", "Dua Lipa", "Don't Start Now"};

    // Inisialisasi objek Song 5
    Song song5 = {"Beauty Behind the Madness", "The Weeknd", "Can't Feel My Face"};
    queue Q;
    CreateQueue(&Q);
    enqueue(&Q, song1);
    enqueue(&Q, song2);
    enqueue(&Q, song3);
    printf("\n");
    printf("ini isi queue\n");
    displayQueue(Q);
    Stack S;
    CreateEmptyS(&S);
    Push(&S, song4);
    Push(&S, song5);
    printf("\n");
    printf("ini isi stack\n");
    // while(!IsEmptyS(S)){
    //     Song lagu;
    //     Pop(&S,&lagu);
    //     printf("%s - %s - %s\n", lagu.namaP, lagu.namaA, lagu.namaS);
    // }
    printf("\n");
    printf("ini current song\n");
    printf("%s - %s - %s\n", CS.namaP, CS.namaA, CS.namaS);

    songnext(&CS, &Q, &S);
    printf("\n");
    printf("ini current song\n");
    printf("%s - %s - %s\n", CS.namaP, CS.namaA, CS.namaS);
    printf("\n");
    printf("ini isi stack\n");
    printf("\n");
    printf("ini isi queue\n");
    displayQueue(Q);
    printf("\n");
    songprevious(&CS, &Q, &S);
    while(!IsEmptyS(S)){
        Song lagu;
        Pop(&S,&lagu);
        printf("%s - %s - %s\n", lagu.namaP, lagu.namaA, lagu.namaS);
    }
    printf("ini isi queue\n");
    displayQueue(Q);
}
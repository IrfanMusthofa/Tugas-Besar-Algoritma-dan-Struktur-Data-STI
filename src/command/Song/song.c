#include "song.h"

void songnext(CurrentSong *play, queue *currentqueue, Stack *previous){
    Song currentlagu; Song nextlagu;
    play->NamaA = currentlagu.namaA;
    play->NamaP = currentlagu.namaP;
    play->NamaS = currentlagu.namaS;
    dequeue(currentqueue, &nextlagu);
    play->NamaA = nextlagu.namaA;
    play->NamaP = nextlagu.namaP;
    play->NamaS = nextlagu.namaS;
    Push(previous, currentlagu);
    printf("Memutar lagu selanjutnya\n");
    printf("“%s” oleh “%s”\n", currentlagu.namaS, currentlagu.namaP);
}

void songprevious(CurrentSong *play, queue *currentqueue, Stack *previous){
    if (IsEmpty(*previous)){
        printf("Riwayat lagu kosong, memutar kembali lagu\n");
        printf("“%s” oleh “%s”\n", play->NamaS, play->NamaP);
    }
    else {
        Song previoussong;
        Pop(previous, &previoussong);
        play->NamaA = previoussong.namaA;
        play->NamaP = previoussong.namaP;
        play->NamaS = previoussong.namaS;
        printf("Memutar lagu sebelumnya\n");
        printf("“%s” oleh “%s”\n", play->NamaS, play->NamaP);
    }
}

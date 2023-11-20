#include "song.h"


/* Lanjut ke lagu berikutnya */
/* IS : Currentsong, queue, stack terdefinisi */
/* FS : Lagu yang paling depan di queue akan berada di current song, current song awal masuk ke stack */
void songnext(CurrentSong *play, queue *currentqueue, Stack *previous){
    if(isEmpty(*currentqueue)){
        printf("Queue kosong, memutar kembali lagu\n");
        printf("'%s' oleh '%s'\n", play->namaS, play->namaP);
    } else{
        valuetype tes = "-";
        if(! IsEqualString(play->namaP, tes)){
            Song currentlagu; 
            currentlagu.namaA = play->namaA;
            currentlagu.namaP = play->namaP;
            currentlagu.namaS = play->namaS;

            Push(previous, currentlagu);
        }

        Song nextlagu;
        dequeue(currentqueue, &nextlagu);
        play->namaA = nextlagu.namaA;
        play->namaP = nextlagu.namaP;
        play->namaS = nextlagu.namaS;


        printf("Memutar lagu selanjutnya\n");
        printf("'%s' oleh '%s'\n", play->namaS, play->namaP);
    }
}

/* Lanjut ke lagu sebelumnya */
/* IS : Currentsong, queue, stack terdefinisi */
/* FS : Lagu yang paling atas di stack, di pop, kemudian menjadi current song, current song masuk ke queue */
void songprevious(CurrentSong *play, queue *currentqueue, Stack *previous){
    if (IsEmptyS(*previous)){
        printf("Riwayat lagu kosong, memutar kembali lagu\n");
        printf("“%s” oleh “%s”\n", play->namaS, play->namaP);
    }
    else {
        Song previoussong; 
        Song songcurrent; // lagu yang dimainin sekarang, mau dibalikin lagi ke queue
        songcurrent.namaA = play->namaA;
        songcurrent.namaP = play->namaP;
        songcurrent.namaS = play->namaS;
        for (int i = currentqueue->idxTail; i >= 0; i--){
            currentqueue->buffer[i+1] = currentqueue->buffer[i];
        }
        currentqueue->idxTail ++;
        currentqueue->buffer[0] = songcurrent;

        Pop(previous, &previoussong);
        play->namaA = previoussong.namaA;
        play->namaP = previoussong.namaP;
        play->namaS = previoussong.namaS;
        printf("Memutar lagu sebelumnya\n");
        printf("'%s' oleh '%s'\n", play->namaS, play->namaP);
    }
}

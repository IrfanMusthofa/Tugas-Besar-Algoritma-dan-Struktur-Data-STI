#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "ADT.h"
#include "mesinkata.h"
#include "mesinkarakter.h"


int main(){
    printf("Tes queue nih bos....\n");
    queue Q;
    printf("Create queue\n");
    CreateQueue(&Q);
    printf("%d\n", Q.idxTail); // INDEX UNDEF
    printf("isEmpty?\n");
    if(isEmpty(Q)){
        printf("kosong\n");
    }
    printf("isFull?\n");
    if(!isFull(Q)){
        printf("gak penuh\n");
    }
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
    printf("tes enqueue\n");
    enqueue(&Q, song1);
    enqueue(&Q, song2);
    enqueue(&Q, song3);
    enqueue(&Q, song4);
    enqueue(&Q, song5);
    displayQueue(Q);
    printf("tes dequeue\n");
    Song temp;
    dequeue(&Q, &temp);
    printf("%s\n", temp.namaS);
    displayQueue(Q);
    printf("tes swap\n");
    swapQueueElements(&Q, 0, 1);
    displayQueue(Q);
    return 0;
}
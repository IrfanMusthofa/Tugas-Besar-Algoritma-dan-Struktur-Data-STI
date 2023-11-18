#include "ADT.h"
#include "queueu.h"
#include "queue.h"
#include <stdio.h>


void queuelagu(Queue currentqueue, ListPenyanyi penyanyi, MapAlbum map, Song lagu){
    // Print list dari penyanyi yang ada
    for (int i = 0; i < penyanyi.neff; i++){
        printf("%d. ", (i + 1));
        printf("%s\n", penyanyi.A[i]);
    }

    // Input nama penyanyi
    printf("Masukkan Nama Penyanyi: ");
    char* inputpenyanyi; scanf("%s", inputpenyanyi);
    int count = 0;

    // Print list dari album penyanyi sesuai input sebelumnya
    for (int i = 0; i < map.count; i++){
        if (map.Elements[i].IdPenyanyi == idpenyanyi(inputpenyanyi, penyanyi)){
            count++;
            printf("%d. ", count); printf("%s\n", map.Elements[i].valueAlbum);
        }
    }

    // Input judul album
    printf("Masukkan Nama Album yang dipilih: ");
    char* inputalbum; scanf("%s", inputalbum);
    count = 0;


    // Print list dari lagu dalam album sesuai input sebelumnya
    for (int i = 0; i < 100; i++){
        if (lagu.IdAlbum == idalbum(inputalbum, map)){
            count++;
            printf("%d. ", count); printf("%s\n", lagu.namaS);
        }
    }

    // Input judul lagu
    printf("Masukkan ID Lagu yang dipilih: ");
    valuetype pilihanlagu;
    int inputid; scanf("%d", &inputid);
    int indeks = 0;
    for (int i = 0; i < 100; i++){
        if (lagu.IdAlbum == idalbum(inputalbum, map)){
            indeks++;
            if (indeks == inputid){
                enqueue(&currentqueue, lagu);
                pilihanlagu = lagu.namaS;
                break;
            }
        }
    }
    printf("Berhasil menambahkan lagu “%s” oleh “%s” ke queue", pilihanlagu, inputpenyanyi);
}

void queueplaylist(){

}

void swapqueue(int indeks1, int indeks2, Queue *currentqueue){
    swapQueueElements(currentqueue, currentqueue->buffer[indeks1 + 1], currentqueue->buffer[indeks2 + 1]);
    // print (Lagu “Kokoro wo Komete” berhasil ditukar dengan “Mirror”)
    // print (Lagu dengan urutan ke 80 tidak terdapat dalam queue!)
}

void removequeue(Queue *currentqueue){
    CreateQueue(currentqueue);
}


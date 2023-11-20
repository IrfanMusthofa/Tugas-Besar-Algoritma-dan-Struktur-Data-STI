#include "../../ADT/MesinKalimat/mesinkata.h"
#include "Cqueue.h"
#include "../../main/ADT.h"
#include "../Pick/pick.h"
#include "../../ADT/Queue/queue.h"
#include "../Playlist/Cplaylist.h"

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong song;
    char *file = "config.txt";
    STARTCOM(&Penyanyi,&Album,&song, file);
    listp(Penyanyi);
    valuetype Singer = pickpenyanyi(Penyanyi);
    int idP;
    listalbum(Penyanyi, Album, Singer, &idP);   
    valuetype a = pickalbum(Album, idP);
    ListStatic L = MakeListStatis();
    listlagu(Album, song, a, &L, Singer);
    valuetype l = picklagu(L);

    // queue lagu;
    // CreateQueue(&lagu);
    // // queuelagu(&lagu, Penyanyi, Album, song);
    // // displayQueue(lagu);
    // ArrayDinPlaylist arr = MakeArrayDin();
    // printf("Buat playlist\n");
    // playlistcreate(&arr);
    // printf("Tambah album ke playlist\n");
    // tambahalbumplaylist(Penyanyi, Album, song, &arr);
    // printf("Isi lagu di playlist\n");
    // PrintInfo(arr.playlist[0]);
    // printf("nambah isi playlist ke queue\n");
    // queueplaylist(arr, &lagu);
    // printf("\n");
    // displayQueue(lagu);
    // printf("ini mau ngeswap1\n");
    // swapqueue(1, 3, &lagu);
    // displayQueue(lagu);
    // printf("ini mau ngeswap2\n");
    // swapqueue(100, 2, &lagu);
    // displayQueue(lagu);
    // printf("ini mau ngeswap3\n");
    // swapqueue(400, 200, &lagu);
    // displayQueue(lagu);
    // printf("ini mau ngeswap4\n");
    // swapqueue(2, 100, &lagu);
    // displayQueue(lagu);
    // printf("ini mau ngeswap5\n");
    // swapqueue(5, 1, &lagu);
    // displayQueue(lagu);
    // removequeue(&lagu);
    // displayQueue(lagu);
    

}
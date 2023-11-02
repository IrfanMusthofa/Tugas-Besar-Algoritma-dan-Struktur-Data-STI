#include <stdio.h>
#include "map.h"

int main(){
    Map Tesmap;
    CreateEmpty(&Tesmap);
    if (IsEmpty(Tesmap)){
        printf("map kosong\n");
    }
    printf("melakukan pengisian map...\n");
    for (int i = 0;i<MaxEl;i++){
        keytype key = i;
        valuetype value = i*i;
        Insert(&Tesmap,key,value);
    }
    if (IsFull(Tesmap)){
        printf("Map penuh.");
    }
    keytype key = 69;
    printf("Key : %d, Value : %d\n",key, Value(Tesmap,key));
    Delete(&Tesmap,key);
    printf("Key : %d, Value : %d\n",key, Value(Tesmap,key));
    if(!IsMember(Tesmap,key)){
        printf("key %d tidak ditemukan\n", key);
    }
}
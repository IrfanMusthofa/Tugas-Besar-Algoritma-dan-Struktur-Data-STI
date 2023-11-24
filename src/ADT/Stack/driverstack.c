#include "stack.h"
#include <stdio.h>

int main(){
    Stack testing;
    CreateEmptyS(&testing);
    if (IsEmptyS(testing)){
        printf("stack testing kosong\n");
    }
    Song input;
    printf("Memasukkan : BLACKPINK-BORN PINK-DUDUDUDU\n");
    PenyanyiS(input) = "BLACKPINK";
    AlbumS(input) = "BORN PINK";
    LaguS(input) = "DUDUDUDU";
    input.namaS = "hubka";
    Push(&testing,input);
    printf("berhasil masuk\n");
    printf("print valuetop untuk memastikan\n");
    printf("%s\n", PenyanyiS(InfoTop(testing)));
    printf("%s\n", AlbumS(InfoTop(testing)));
    printf("%s\n", LaguS(InfoTop(testing)));

    Song input2;
    printf("Memasukkan : HITAM MERAH MUDA-LAHIR MERAH-UDUDUDUD\n");
    PenyanyiS(input2) = "HITAM MERAH MUDA";
    AlbumS(input2) = "LAHIR MERAH";
    LaguS(input2) = "UDUDUDUD";
    
    Push(&testing,input2);

    Song tespop;
    printf("Pop : nilai top\n");
    Pop(&testing,&tespop);
    printf("isi stack saat ini : %d\n",testing.TOP+1);
    printf("mencoba print nilai value yang di pop\n");
    printf("%s\n", PenyanyiS(tespop));
    printf("%s\n", AlbumS(tespop));
    printf("%s\n", LaguS(tespop));
}
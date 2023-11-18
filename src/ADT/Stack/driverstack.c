#include "stack.h"
#include <stdio.h>

int main(){
    Stack testing;
    CreateEmpty(&testing);
    if (IsEmpty(testing)){
        printf("stack testing kosong\n");
    }
    Song input;
    printf("Memasukkan : BLACKPINK-BORN PINK-DUDUDUDU\n");
    Penyanyi(input) = "BLACKPINK";
    Album(input) = "BORN PINK";
    Lagu(input) = "DUDUDUDU";

    Push(&testing,input);
    printf("berhasil masuk\n");
    printf("print valuetop untuk memastikan\n");
    printf("%s\n", Penyanyi(InfoTop(testing)));
    printf("%s\n", Album(InfoTop(testing)));
    printf("%s\n", Lagu(InfoTop(testing)));

    Song input2;
    printf("Memasukkan : HITAM MERAH MUDA-LAHIR MERAH-UDUDUDUD\n");
    Penyanyi(input2) = "HITAM MERAH MUDA";
    Album(input2) = "LAHIR MERAH";
    Lagu(input2) = "UDUDUDUD";
    
    Push(&testing,input2);

    Song tespop;
    printf("Pop : nilai top\n");
    Pop(&testing,&tespop);
    printf("isi stack saat ini : %d\n",testing.TOP+1);
    printf("mencoba print nilai value yang di pop\n");
    printf("%s\n", Penyanyi(tespop));
    printf("%s\n", Album(tespop));
    printf("%s\n", Lagu(tespop));
}
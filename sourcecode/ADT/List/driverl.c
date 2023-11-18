#include <stdio.h>
#include "list.h"

int main(){
    ListStatic L = MakeList();

    printf("tes is empty?\n");
    int x = IsEmpty(L);
    printf("%d\n", x);
    char * y = "makanenak";
    InsertLast(&L, y);
    printf("%s", L.A[0]);
}
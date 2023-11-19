#include <stdio.h>
#include "list.h"

int main(){
    printf("test makelisttatis\n");
    ListStatic L = MakeListStatis();
    printf("%d\n", L.Neff);
    printf("tes is empty?\n");
    int x = IsEmptyListStatis(L);
    printf("%d\n", x);
    printf("insert last\n");
    char * y = "makanenak";
    InsertLastListStatis(&L, y);
    printf("%s\n", L.A[0]);
    printf("lengthnya?\n");
    int z = LengthListStatis(L);
    printf("%d\n",z);
    printf("tes get\n");
    char* yolo = GetListStatis(L, 0);
    printf("%s\n", yolo);
    printf("Udah di tes semua, aman\n");
}
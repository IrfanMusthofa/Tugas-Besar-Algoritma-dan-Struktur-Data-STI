#include "map.h"
#include <stdio.h>
#include "boolean.h"

int main()
{
    Map M;
    CreateEmpty(&M);
    printf("apakah kosong? %d\n", IsEmpty(M));
    printf("apakah penuh? %d\n", IsFull(M));
    Insert(&M, 1, 10);
    Insert(&M, 2, 20);
    Insert(&M, 3, 30);
    printf("apakah kosong? %d\n", IsEmpty(M));
    printf("apakah penuh? %d\n", IsFull(M));
    printf("Value 1 adalah %d\n", Value(M, 1) != Undefined ? Value(M, 1) : 0);
    printf("Value 2 adalah %d\n", Value(M, 2) != Undefined ? Value(M, 2) : 0);
    printf("Value 3 adalah %d\n", Value(M,3) != Undefined ? Value(M,3) : 0);
    Delete(&M, 3);
    printf("Value 3 adalah %d\n", Value(M,3) != Undefined ? Value(M,3) : 0);
}
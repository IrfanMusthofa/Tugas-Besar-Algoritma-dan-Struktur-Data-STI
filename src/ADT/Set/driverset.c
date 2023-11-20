#include "set.h"
#include <stdio.h>

int main()
{
    Set S1;
    Set S2;
    Set S3;
    Set S4;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    Insert(&S1, "A");
    Insert(&S2, "B");
    Delete(&S1, "A");
    Insert(&S1, "B");;
    Insert(&S2, "C");
    Insert(&S1, "C");
    Insert(&S2, "D");
    Delete(&S2, "C");
    Insert(&S2, "E");
    Union(&S1, &S2, &S3);
    PrintSet(S1);
    PrintSet(S2);
    PrintSet(S3);


}
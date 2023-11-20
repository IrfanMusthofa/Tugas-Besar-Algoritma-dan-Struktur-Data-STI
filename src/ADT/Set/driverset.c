#include "set.h"

int main()
{
    Set S1;
    Set S2;
    Set S3;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    Insert(&S1, "A");
    Insert(&S2, "B");
    Insert(&S3, "C");
    Delete(&S1, "A");
    PrintSet(S1);
    PrintSet(S2);


}
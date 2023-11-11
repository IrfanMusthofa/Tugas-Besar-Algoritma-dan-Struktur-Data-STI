
#include "set.h"

void main()
{
    Set S1;
    Set S2;
    Set S3;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    Insert(&S1, 'a');
    Insert(&S1, 'b');
    Insert(&S1, 'c');
    Insert(&S1, 'd');
    Insert(&S1, 'e');
   
   
    Insert(&S2, 'a');
    Insert(&S2, 'b');
    Insert(&S2, 'c');
    Insert(&S2, 'd');
    Insert(&S2, 'e');
    Insert(&S2, 'f');
    Insert(&S2, 'g');
    Insert(&S2, 'h');
    Insert(&S2, 'i');
    PrintSet(S1);
    PrintSet(S2);
    SetUnion(&S1, &S2, &S3);
    PrintSet(S3);
    SetIntersection(&S1, &S2);
    Delete(&S3, 'c');
    Delete(&S3, 'd');
    Insert(&S3, 'z');
  
    PrintSet(S3);
    length(S3);
    IsSubset(S3, S2);
    CopySet(S1, &S3);
}

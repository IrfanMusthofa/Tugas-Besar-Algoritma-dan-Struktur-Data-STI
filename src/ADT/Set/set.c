#include "set.h"

void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    //KAMUS LOKAL

    //ALGORITMA
    (*S).Count = 0;
}

boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    //KAMUS LOKAL

    //ALGORITMA
    return (S.Count == 0);
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    //KAMUS LOKAL

    //ALGORITMA
    return (S.Count == NMAX);
}

void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    //KAMUS LOKAL

    //ALGORITMA
    if (!IsMember(*S, Elmt)){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    //KAMUS LOKAL
    boolean found; 
    int i; 

    //ALGORITMA
    found = false;
    i = 0;
    while (i < (*S).Count && !found){
        if ((*S).Elements[i] == Elmt)
        {
            found = true;
        }
        else{
            i++;
        }
        
    }
    if (found) 
    {
        while (i < (*S).Count-1)
        {
            (*S).Elements[i] = (*S).Elements[i+1];
            i++;
        }
        (*S).Count--;
    }
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    //KAMUS LOKAL
    boolean found;
    int i;

    //ALGORITMA
    found = false;
    i = 0;
    while (i < S.Count && !found)
    {
        if (S.Elements[i] == Elmt)
        {
            found = true;
        }
        i++; 
    }
    return found;
}

void PrintSet(Set S)
/* Mencetak set S ke layar */
{
    //KAMUS LOKAL
    int i;

    //ALGORITMA
    printf("{");
    for (i = 0; i < S.Count; i++)
    {
        printf("%s", S.Elements[i]);
        if (i < S.Count - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

void Union(Set *S1, Set *S2, Set *S3)
/* Menghasilkan S3 yang merupakan hasil gabungan S1 dan S2 */
{
    CreateEmpty(S3);
    int i = 0;
    while (i < S1->Count)
    {
        Insert(S3, S1->Elements[i]);
        i++;
    }
    i = 0;
    while (i < S2->Count)
    {
        Insert(S3, S2->Elements[i]);
        i++;
    }
}

void Intersection(Set *S1, Set *S2, Set *S3)
/* Menghasilkan S3 yang merupakan hasil irisan S1 dan S2 */
{
    CreateEmpty(S3);
    int i = 0;
    while (i < S1->Count)
    {
        if (IsMember(*S2, S1->Elements[i]))
        {
            Insert(S3, S1->Elements[i]);
        }
        i++;
    }
}

void CopySet(Set Sin, Set *Sout)
/* Menyalin Sin ke Sout */
{
    CreateEmpty(Sout);
    int i = 0;
    while (i < Sin.Count)
    {
        Insert(Sout, Sin.Elements[i]);
        i++;
    }
}

void Difference(Set *S1, Set *S2, Set *S3)
/* Menghasilkan S3 yang merupakan hasil selisih S1 dan S2 */
{
    CreateEmpty(S3);
    int i = 0;
    while (i < S1->Count)
    {
        if (!IsMember(*S2, S1->Elements[i]))
        {
            Insert(S3, S1->Elements[i]);
        }
        i++;
    }
}

boolean IsSubset(Set S1, Set S2)
/* Menghasilkan true jika S1 merupakan subset dari S2 */
{
    int i = 0;
    while (i < S1.Count && IsMember(S2, S1.Elements[i]))
    {
        i++;
    }
    return i == S1.Count;
}

boolean IsEqual(Set S1, Set S2)
/* Menghasilkan true jika S1 sama dengan S2 */
{
    return IsSubset(S1, S2) && IsSubset(S2, S1);
}
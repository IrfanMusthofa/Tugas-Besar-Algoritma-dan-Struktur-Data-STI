#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define NMax 100

typedef char *infotype;
typedef int address;

typedef struct
{
    infotype Elements[NMax];
    address Count;
} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void PrintSet(Set S);
/* Mencetak set S ke layar */

void SetUnion(Set *S1, Set *S2, Set *S3);
// Menghasilkan S3 yang merupakan hasil gabungan S1 dan S2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

void SetIntersection(Set *S1, Set *S2, Set *S3);
// Menghasilkan S3 yang merupakan hasil irisan S1 dan S2 
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set S1, Set S2);
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

void SetSubtract(Set *S1, Set *S2, Set *S3);
// Menghasilkan S3 yang merupakan hasil selisih S1 dan S2 
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]

void CopySet(Set Sin, Set *Sout);
/* Menyalin Sin ke Sout */

boolean IsSubset(Set S1, Set S2);
/* Menghasilkan true jika S1 merupakan subset dari S2 */

boolean IsEqual(Set S1, Set S2);
/* Menghasilkan true jika S1 sama dengan S2 */

int length(Set S);
/* Mengirimkan banyaknya elemen Set S, mungkin 0 */

#endif
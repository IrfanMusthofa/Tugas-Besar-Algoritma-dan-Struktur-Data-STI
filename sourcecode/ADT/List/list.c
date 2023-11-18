#include <stdio.h>
#include "list.h"

// Konstruktor
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
ListStatic MakeListStatis() {
	ListStatic L;
	L.Neff = 0;
	return L;
}
/* *** Test list kosong *** */
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
boolean IsEmptyListStatis(ListStatic L) {
	return (L.Neff == 0);
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
int LengthListStatis(ListStatic L) {
	return L.Neff;
}
/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
ElType GetListStatis(ListStatic L, IdxType i) {
	return L.A[i];
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
void InsertLastListStatis(ListStatic *L, ElType X) {
    IdxType i = LengthListStatis(*L);
	L->A[i] = X;
	L->Neff ++;
}

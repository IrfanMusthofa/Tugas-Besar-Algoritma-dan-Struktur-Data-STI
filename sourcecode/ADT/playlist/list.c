#include <stdio.h>
#include "list.h"

// Konstruktor

ListStatic MakeList() {
	ListStatic L;
	L.Neff = 0;
	return L;
}

boolean IsEmpty(ListStatic L) {
	return (L.Neff == 0);
}

int Length(ListStatic L) {
	return L.Neff;
}

ElType Get(ListStatic L, IdxType i) {
	return L.A[i];
}

void InsertLast(ListStatic *L, ElType X) {
    IdxType i = Length(*L);
	L->A[i] = X;
	L->Neff ++;
}

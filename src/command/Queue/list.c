#include <stdio.h>
#include "list.h"

// Konstruktor

ListStatic MakeListStatis() {
	ListStatic L;
	L.Neff = 0;
	return L;
}

boolean IsEmptyListStatis(ListStatic L) {
	return (L.Neff == 0);
}

int LengthListStatis(ListStatic L) {
	return L.Neff;
}

ElType GetListStatis(ListStatic L, IdxType i) {
	return L.A[i];
}

void InsertLastListStatis(ListStatic *L, ElType X) {
    IdxType i = LengthListStatis(*L);
	L->A[i] = X;
	L->Neff ++;
}

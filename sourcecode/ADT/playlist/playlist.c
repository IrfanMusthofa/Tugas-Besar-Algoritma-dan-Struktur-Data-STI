#include "playlist.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/***********Playlist************/

void CreatePlaylist (ArrayDinPlaylist *array, valuetype namaplaylist){
    int i = array->Neff;
    address P = NULL;
    InsertLast(array, P);
    array->playlist[i].namaPlaylist = namaplaylist;
}
/** konstruktor
 * I.S. array terdefinisi, namaplaylist terdefinisi
 * F.S. Terbentuk playlist di elemen setelah Neff, dengan nama playlist yang terdefinisi dan first kosong
 */

void PlaylistAddSong (ArrayDinPlaylist *array, int i, Song lagu){
    if (!SearchLaguPlaylist(array->playlist[i], lagu.namaS)){
        InsVLast(&(array->playlist[i]), lagu);
    }
}
/** fungsi untuk menambahkan lagu baru pada playlist tertentu
 * I.S. array terdefinisi, i adalah index playlist, lagu tersefinsi
 * F.S. lagu berhasil ditambahkan di playlist
 * */

Song CreateSong(valuetype namapenyanyi, valuetype namaalbum, valuetype namalagu){
    Song lagu;
    lagu.namaA = namaalbum;
    lagu.namaP = namapenyanyi;
    lagu.namaS = namalagu;
    return lagu;
}


void tukarplaylist(ArrayDinPlaylist *array, int idP, int x, int y){
    address P = First(array->playlist[idP - 1]);
    int h1 = 0;
    while (P != NULL)
    {
        h1++;
        if(h1 == x){
            break;
        } 
        P = Next(P);
    }

    address Q = First(array->playlist[idP - 1]);
    int h2 = 0;
    while (Q != NULL)
    {
        h2++;
        if(h2 == y){
            break;
        } 
        Q = Next(P);
    }

    Song temp = Info(P);
    Info(P) = Info(Q);
    Info(Q) = temp;
    
}

/***********Arraydin************/
/** konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDinPlaylist MakeArrayDin(){
    ArrayDinPlaylist array;
    (array).playlist = (List*) malloc (100*sizeof(List));
    (array).Capacity = 100;
    (array).Neff = 0;
    return array;
}


/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->playlist terdealokasi
 */
void DeallocateArrayDin(ArrayDinPlaylist *array){
    free((*array).playlist);
    (*array).Capacity = 0;
    (*array).Neff=0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayDin(ArrayDinPlaylist array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDinPlaylist array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
address Get(ArrayDinPlaylist array, int i){
    return (array.playlist[i]).First;
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDinPlaylist array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDinPlaylist *array, address P, int i){
    int j;

    for (j = array->Neff - 1; j >= i; j--){
        array->playlist[j+1] = array->playlist[j];
    }
    
    array->playlist[i].First = P;
    array->Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDinPlaylist *array, address el){
    InsertAt(array, el, Length(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDinPlaylist *array, address el){
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDinPlaylist *array, int i){
    
    int j;
    for (j=i;j<array->Neff; j++){
        array->playlist[j] = array->playlist[j+1];
    }
    array->Neff -= 1;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDinPlaylist *array){
    DeleteAt(array, Length(*array)-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDinPlaylist *array){
    DeleteAt(array, 0);
}


/***********LinkedList************/

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListLinier (List L){
    return (First(L) == NULL);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (Song X){
    ElmtList *P=(ElmtList*)malloc(sizeof(ElmtList));
    if (P != NULL){
        Lagu(P) = X.namaS;
        Album(P) = X.namaA;
        Penyanyi(P) = X.namaP;
        Next(P)= NULL;
        return P;
    }
    else{
        return NULL;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free (*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, Song X){
    boolean found = false;
    address P = First(L);
    while (P != NULL && found == false){
        if (Lagu(P) == X.namaS){
            found = true;
        } else {
            P = Next(P);
        }
    }
    if( found ){
        return P;
    } else {
        return NULL;
    }
}
/* Mencari apakah ada elemen list dengan Lagu(P)= X.namaS */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Null */

boolean SearchLaguPlaylist(List L, char* namalagu){
    boolean found = false;
    address P = First(L);
    while (P != NULL && found == false){
        if (IsEqualString(Lagu(P), namalagu)){
            found = true;
        } else {
            P = Next(P);
        }
    }
    return found;
}
/* Mencari apakah ada elemen list dengan Lagu(P)= X.namaS */
/* Jika ada, mengirimkan true */
/* Jika tidak ada, mengirimkan false */

/* Membandingkan apakah kedua string sama*/
/* Jika sama, mengirimkan true */
/* Jika tidak, mengirimkan false */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, Song X){
    address P = Alokasi(X);
    if (P != NULL){
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, Song X){
    address P = Alokasi(X);
    if (P != NULL){
        if(IsEmptyListLinier(*L)){
            Next(P) = NULL;
            First(*L)=P;
        } else{
            address x = First(*L);
            while (Next(x) != NULL){
                x = Next(x);
            }
            Next(x) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, Song *X){
    address P;
    P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, Song *X){
    address P = First(*L);
    address prev = NULL;
    while (Next(P) != NULL)
    {
        prev = P;
        P = Next(P);
    }
    if (prev == NULL){
        CreateEmpty(L);
    } else{
        Next(prev) = NULL;
    }
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    if (IsEmptyListLinier(L)) {
        printf("[]\n");
    } else {
        printf("[");
        address P = First(L);
        while (P != NULL) {
            printf("%s", Lagu(P));
            P = Next(P);
            if (P != NULL) {
                printf(",");
            }
        }
        printf("]\n");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (List L){
    int n = 0;
    address P = First(L);
    while(P != NULL){
        n += 1;
        P = Next(P);
    }
    return n;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#ifndef __playlist_h__
#define __playlist_h__

/*PLAYLIST*/

/*INCLUDE*/
#include "boolean.h"
#include "../../main/ADT.h"
#include "../MesinKalimat/mesinkata.h"

#define Lagu(P) (P)->info.namaS
#define Album(P) (P)->info.namaA
#define Penyanyi(P) (P)->info.namaP
#define IdxAlbum(P) (P)->info.IdAlbum
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/*PLAYLIST*/
void CreatePlaylist (ArrayDinPlaylist *array, valuetype namaplaylist);
/** konstruktor
 * I.S. array terdefinisi, namaplaylist terdefinisi
 * F.S. Terbentuk playlist di elemen setelah Neff, dengan nama playlist yang terdefinisi dan first kosong
 */

void PlaylistAddSong (ArrayDinPlaylist *array, int i, Song lagu);
/** fungsi untuk menambahkan lagu baru pada playlist tertentu
 * I.S. array terdefinisi, i adalah index playlist, lagu terdefinisi
 * F.S. lagu berhasil ditambahkan di playlist
 * */


void tukarplaylist(ArrayDinPlaylist *array, int idP, int x, int y);
/* menukar urutan lagu di playlist */
/* IS: arraydin playlist terdefinisi, indeks playlist idP dimulai dari 1 (urutan playlist), x dan y adalah urutan lagu dimulai dari 1 */
/* FS: lagu urutan x dan y di playlist idP-1 akan ditukar */

void DeleteLaguPlaylist (ArrayDinPlaylist *array, int idP, int x, Song *lagu);
/* menghapus lagu di playlist */
/* IS: arraydin playlist terdefinisi, indeks playlist idP dimulai dari 1 (urutan playlist) */
/* FS: lagu berisi info dari playlist yang terhapus */

void DeletePlaylist (ArrayDinPlaylist *array, int idP);
/* menghapus playlist */
/* IS: arraydin playlist terdefinisi, indeks playlist idP dimulai dari 0 */
/* FS: playlist dengan indeks idP terhapus */

Song CreateSong(valuetype namapenyanyi, valuetype namaalbum, valuetype namalagu);
/** fungsi untuk membentuk lagu
 * I.S. terdefinisi index album, nama penyanyi, album, dan lagunya
 * F.S. lagu berhasil terbentuk
 * */


/*ARRAYDIN*/
/** konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */

ArrayDinPlaylist MakeArrayDin();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDinPlaylist *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayDin(ArrayDinPlaylist array);


/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDinPlaylist array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
address Get(ArrayDinPlaylist array, int i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDinPlaylist array);


/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDinPlaylist *array, address P, int i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDinPlaylist *array, address el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDinPlaylist *array, address el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDinPlaylist *array, int i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDinPlaylist *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDinPlaylist *array);



/*LINKED LIST*/
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListLinier (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (Song X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, Song X);
/* Mencari apakah ada elemen list dengan Lagu(P)= X.n */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

boolean SearchLaguPlaylist(List L, char* namalagu);
/* Mencari apakah ada elemen list dengan Lagu(P)= X.namaS */
/* Jika ada, mengirimkan true */
/* Jika tidak ada, mengirimkan false */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, Song X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, Song X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, Song *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, Song *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#endif

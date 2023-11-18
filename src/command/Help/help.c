#include "help.h"
#include <stdio.h>

void help_before() //ketika perintah dipanggil sebelum memasuki sesi
{
    printf("=======================[ Menu Help WayangWave ]=======================\n");
    printf("1. START; -> Untuk masuk sesi baru\n");
    printf("2. LOAD <namafile.txt>; -> Untuk memulai sesi berdasarkan file konfigurasi\n");
}

void help_after() //ketika perintah dipanggil setelah memasuki sesi
{
    printf("=========================================[ Menu Help WayangWave ]=========================================\n");
    printf("1. LIST\n");
    printf("        DEFAULT; -> Untuk menampilkan daftar penyanyi, album, dan daftar lagu yang ada di album.\n");
    printf("        PLAYLIST; -> Untuk menampilkan daftar playlist.\n");
    printf("2. PLAY\n");
    printf("        SONG; -> Untuk memutar lagu yang dipilih.\n");
    printf("        PLAYLIST; -> Untuk memutar playlist yang dipilih.\n");
    printf("3. QUEUE\n");
    printf("        SONG; -> Untuk memasukkan lagu yang dipilih ke antrian.\n");
    printf("        PLAYLIST; -> Untuk memasukkan playlist yang dipilih ke antrian.\n");
    printf("        SWAP <id1> <id2>; -> Untuk mengganti urutan lagu dalam antrian.\n");
    printf("        CLEAR; -> Untuk mengganti urutan lagu dalam antrian.\n");
    printf("4. SONG\n");
    printf("        PREVIOUS; -> memutar lagu sebelumnya.\n");
    printf("        NEXT; -> memutar lagu selanjutnya.\n");
    printf("5. PLAYLIST -> Untuk melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE, dan DELETE.\n");
    printf("            CREATE; -> membuat playlist baru.\n");
    printf("            ADD\n");
    printf("                SONG; -> menambahkan lagu ke playlist yang ada.\n");
    printf("                ALBUM; -> menambahkan semua lagu di album ke playlist yang ada.\n");
    printf("            SWAP <idplaylist> <idlagu1> <idlagu2>; -> menukar urutan lagu di playlist yang dipilih.\n");
    printf("            REMOVE <idplaylist> <n>; -> mengahapus lagu urutan n pada playlist <idplaylist>.\n");
    printf("            DELETE; -> menghapus playlist.\n");
    printf("6. STATUS; -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.\n");
    printf("7. SAVE <namafile.txt>; -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n");
    printf("8. QUIT; -> Untuk keluar dari sesi aplikasi WayangWave.\n");
    printf("9. HELP; -> Untuk menampilkan daftar command yang ingin dieksekusi beserta deskripsinya.\n");

}
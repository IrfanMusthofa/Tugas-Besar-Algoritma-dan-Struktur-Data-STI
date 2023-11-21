#include "help.h"
#include <stdio.h>

void help_before() //ketika perintah dipanggil sebelum memasuki sesi
{
    printf("=======================[ Menu Help WayangWave ]=======================\n");
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD <namafile.txt> -> Untuk memulai sesi berdasarkan file konfigurasi\n");
}

void help_after() //ketika perintah dipanggil setelah memasuki sesi
{
    printf("=========================================[ Menu *Help* WayangWave ]=========================================\n");
    printf("1. LIST\n");
    printf("        DEFAULT            -> Untuk menampilkan daftar penyanyi, album, dan daftar lagu yang ada di album.\n");
    printf("        PLAYLIST           -> Untuk menampilkan daftar playlist.\n");
    printf("\n");
    printf("2. PLAY\n");
    printf("        SONG               -> Untuk memutar lagu yang dipilih.\n");
    printf("        PLAYLIST           -> Untuk memutar playlist yang dipilih.\n");
    printf("\n");
    printf("3. QUEUE\n");
    printf("        SONG               -> Untuk menambahkan lagu yang dipilih ke dalam queue.\n");
    printf("        PLAYLIST           -> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue.\n");
    printf("        SWAP <id1> <id2>   -> Untuk mengganti urutan lagu dalam antrian.\n");
    printf("        REMOVE <id>        -> Untuk menghapus lagu dari queue.\n");
    printf("        CLEAR              -> Untuk mengosongkan queue.\n");
    printf("\n");
    printf("4. SONG\n");
    printf("        NEXT               -> Untuk memutar lagu yang berada di dalam queue.\n");
    printf("        PREVIOUS           -> Untuk memutar lagu yang terakhir kali diputar.\n");
    printf("\n");
    printf("5. PLAYLIST                -> Untuk melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE, dan DELETE.\n");
    printf("            CREATE         -> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna.\n");
    printf("            ADD\n");
    printf("                SONG       -> Untuk menambahkan lagu ke playlist yang ada.\n");
    printf("                ALBUM      -> Untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna.\n");
    printf("            SWAP <idplaylist> <idlagu1> <idlagu2>\n");
    printf("                           -> Untuk menukar urutan lagu di playlist yang dipilih.\n");
    printf("            REMOVE <idplaylist> <n>\n");
    printf("                           -> Untuk menghapus lagu urutan n pada playlist <idplaylist>.\n");
    printf("            DELETE         -> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna.\n");
    printf("\n");
    printf("6. STATUS                  -> Untuk menampilkan lagu yang sedang dimainkan, queue song saat ini dan dari playlist mana lagu itu diputar.\n");
    printf("\n");
    printf("7. SAVE <namafile.txt>     -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n");
    printf("\n");
    printf("8. QUIT                    -> Untuk keluar dari aplikasi WayangWave.\n");
    printf("\n");
    printf("9. ENHANCE                 -> Untuk menampilkan daftar playlist dengan tambahan lagu rekomendasi random dari penyanyi random dan album random.\n");
    printf("/n");
    printf("10. HELP                    -> Untuk menampilkan daftar command yang ingin dieksekusi beserta deskripsinya.\n");
}
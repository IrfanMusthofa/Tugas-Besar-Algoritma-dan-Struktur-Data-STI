void help_awal() //ketika perintah dipanggil sebelum memasuki sesi
{
    printf("=====[ Menu Help WayangWave ]=====");
    printf("1. START -> Untuk masuk sesi baru");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi");
}

void help_akhir() //ketika perintah dipanggil setelah memasuki sesi
{
    printf("=====[ Menu Help WayangWave ]=====");
    printf("1. LIST -> Untuk menampilkan playlist, daftar penyanyi, album, dan daftar lagu yang ada di album.");
    printf("2. PLAY -> Untuk memutar lagu atau playlist yang dipilih.");
    printf("3. QUEUE -> Untuk memanipulasi queue lagu.");
    printf("4. SONG -> Untuk navigasi lagu yang ada pada queue lagu saat ini.");
    printf("5. PLAYLIST -> Untuk melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE, dan DELETE.");
    printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.");
    printf("7. SAVE -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.");
    printf("8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave.");
    printf("9. HELP -> Untuk menampilkan daftar command yang ingin dieksekusi beserta deskripsinya.");

}
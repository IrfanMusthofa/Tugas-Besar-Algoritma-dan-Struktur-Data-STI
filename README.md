# ==============WayangWave==============
### IF2111 Algoritma dan Struktur Data
                   
## Deskripsi Singkat Program WayangWave
WayangWave merupakan sebuah program aplikasi yang berbasis _command-line interface_ yang dibuat dengan menggunakan bahasa pemrograman C, yang memungkinkan penggunanya untuk merasakan pengalaman layanan pemutaran musik. Program ini memiliki lima fungsi atau fitur utama, seperti memutar lagu, menampilkan daftar lagu, membuat dan menghapus playlist, mengatur penyusunan urutan pemutaran lagu, dan menayangkan status dari aplikasi. Selain itu, terdapat pula tambahan fitur berupa memilih playlist yang ingin ditambahkan dengan lagu-lagu _random_.
<br/>
Program ini menggunakan aplikasi ADT dalam bahasa pemrograman C.

## Nama Anggota Kelompok 10 K-02 "A Magic Tea Pot":
**1. Muhammad Rifa Ansyari     (18222004) <br/>
2. Irfan Musthofa              (18222056) <br/>
3. Taufiq Ramadhan Ahmad       (18222060) <br/>
4. Kerlyn Deslia Andeskar      (18222090) <br/>
5. Farah Aulia                 (18222096)**

## Cara Kompilasi Program
### Untuk Windows
#### - Menggunakan chocolatey
- Program dapat dijalankan di command prompt Anda dengan memiliki package make <br/>
  --> Package make dapat diperoleh dengan menginstall chocolatey terlebih dahulu <br/>
  --> Untuk langkah-langkah menginstall chocolatey dapat mengikuti dari link berikut ini:
      https://chocolatey.org/install
  
- Jika chocolatey telah terinstall pada PATH dalam Environmental Variables Device Anda, dapat dilakukan prosedur berikut:
  <br/>
  1.) Buka Windows Powershell dalam device Anda dan run as administrator
  <br/>
  2.) Untuk menginstall package make:
      <br/>
        "choco install make"
      <br/>
  3.) Tunggu hingga package make selesai diinstall
  <br/>
  4.) Setelah package make terinstall, Anda dapat mengompilasi program dengan menjalankan prosedur berikut:
  <br/>
     - Masuk ke folder Tugas-Besar_Algoritma-dan-Struktur-Data_STI yang telah Anda download atau clone dari github repository.
     
     - Buka windows terminal dalam folder tersebut
       
     - Untuk dapat mengompilasi program ini, ketik:
       <br/>
         "make compile"

     - Setelah program selesai di-compile, ketik:
       <br/>
         "./main"
     
- Program WayangWave pun telah dapat dijalankan pada perangkat terminal Anda
  
#### - Menggunakan WSL
- Program dapat dijalankan di command prompt atau terminal Anda dengan memiliki package make <br/>
  --> Package make dapat diperoleh dengan menginstall Windows Subsystem for Linux (WSL) terlebih dahulu <br/>
  --> Untuk langkah-langkah menginstall WSL dapat mengikuti dari link berikut ini: <br/>
      https://learn.microsoft.com/id-id/windows/wsl/install-manual atau https://learn.microsoft.com/id-id/windows/wsl/install

- Jika telah terinstall, masuk ke folder Tugas-Besar_Algoritma-dan-Struktur-Data_STI yang telah Anda download atau clone dari github repository
  
- Buka windows terminal dalam folder tersebut atau buka terminal baru di aplikasi VS Code
  
- Untuk dapat mengompilasi program ini, ketik:
       <br/>
         "make"

- Tunggu program selesai di-compile

- Program WayangWave pun telah dapat dijalankan pada perangkat terminal Anda
  
### Untuk MAC & Linux
- Masuk ke folder Tugas-Besar_Algoritma-dan-Struktur-Data_STI yang telah Anda download atau clone dari github repository
- Buka terminal dalam folder tersebut atau buka terminal baru di aplikasi VS Code
- Program WayangWave pun telah dapat langsung dijalankan dengan mengetik "./WayangWave" pada perangkat terminal Anda


## File Konfigurasi yang Tersedia
> src/config/config.txt

## Save File yang Tersedia
> src/config/1.txt

> src/config/123.txt

> src/config/savefile.txt

> src/config/tesload.txt

## Struktur Program
Tugas-Besar_Algoritma-dan-Struktur-Data_STI
 ┣ docs
 ┃ ┣ IF2111_TB_02_10.pdf
 ┃ ┗ Kelompok10_K02_A Magic Teapot.pdf
 ┣ src
 ┃ ┣ ADT
 ┃ ┃ ┣ List
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ driverl.c
 ┃ ┃ ┃ ┣ list.c
 ┃ ┃ ┃ ┗ list.h
 ┃ ┃ ┣ MesinKalimat
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ driverkata.c
 ┃ ┃ ┃ ┣ file.txt
 ┃ ┃ ┃ ┣ mesinkarakter.c
 ┃ ┃ ┃ ┣ mesinkarakter.h
 ┃ ┃ ┃ ┣ mesinkata.c
 ┃ ┃ ┃ ┗ mesinkata.h
 ┃ ┃ ┣ Playlist
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ driver.c
 ┃ ┃ ┃ ┣ playlist.c
 ┃ ┃ ┃ ┗ playlist.h
 ┃ ┃ ┣ Queue
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ driver.c
 ┃ ┃ ┃ ┣ queue.c
 ┃ ┃ ┃ ┗ queue.h
 ┃ ┃ ┣ Set
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ driverset.c
 ┃ ┃ ┃ ┣ set.c
 ┃ ┃ ┃ ┗ set.h
 ┃ ┃ ┣ Stack
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ driverstack.c
 ┃ ┃ ┃ ┣ stack.c
 ┃ ┃ ┃ ┗ stack.h
 ┃ ┃ ┣ map
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ drivermap.c
 ┃ ┃ ┃ ┣ map.c
 ┃ ┃ ┃ ┗ map.h
 ┃ ┃ ┗ .DS_Store
 ┃ ┣ command
 ┃ ┃ ┣ Enhance
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ enhance.c
 ┃ ┃ ┃ ┗ enhance.h
 ┃ ┃ ┣ Help
 ┃ ┃ ┃ ┣ help.c
 ┃ ┃ ┃ ┗ help.h
 ┃ ┃ ┣ ListC
 ┃ ┃ ┃ ┣ Clist.c
 ┃ ┃ ┃ ┣ Clist.h
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┗ driverlistC.c
 ┃ ┃ ┣ Load
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ load.c
 ┃ ┃ ┃ ┗ load.h
 ┃ ┃ ┣ Pick
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ pick.c
 ┃ ┃ ┃ ┗ pick.h
 ┃ ┃ ┣ Play
 ┃ ┃ ┃ ┣ driverPlay.c
 ┃ ┃ ┃ ┣ play.c
 ┃ ┃ ┃ ┗ play.h
 ┃ ┃ ┣ Playlist
 ┃ ┃ ┃ ┣ Cplaylist.c
 ┃ ┃ ┃ ┣ Cplaylist.h
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┗ main2.c
 ┃ ┃ ┣ Queue
 ┃ ┃ ┃ ┣ Cqueue.c
 ┃ ┃ ┃ ┣ Cqueue.h
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┗ driverQ.c
 ┃ ┃ ┣ Save
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ save.c
 ┃ ┃ ┃ ┗ save.h
 ┃ ┃ ┣ Song
 ┃ ┃ ┃ ┣ boolean.h
 ┃ ┃ ┃ ┣ driverS.c
 ┃ ┃ ┃ ┣ song.c
 ┃ ┃ ┃ ┗ song.h
 ┃ ┃ ┣ Status
 ┃ ┃ ┃ ┣ status.c
 ┃ ┃ ┃ ┗ status.h
 ┃ ┃ ┣ invalidcommand
 ┃ ┃ ┃ ┣ invalidcommand.c
 ┃ ┃ ┃ ┗ invalidcommand.h
 ┃ ┃ ┗ .DS_Store
 ┃ ┣ config
 ┃ ┃ ┣ .DS_Store
 ┃ ┃ ┣ 1.txt
 ┃ ┃ ┣ 123.txt
 ┃ ┃ ┣ config.txt
 ┃ ┃ ┣ savefile.txt
 ┃ ┃ ┗ tesload.txt
 ┃ ┣ main
 ┃ ┃ ┣ ADT.c
 ┃ ┃ ┣ ADT.h
 ┃ ┃ ┣ boolean.h
 ┃ ┃ ┗ main.c
 ┃ ┗ .DS_Store
 ┣ .DS_Store
 ┣ README.md
 ┣ WayangWave
 ┗ makefile

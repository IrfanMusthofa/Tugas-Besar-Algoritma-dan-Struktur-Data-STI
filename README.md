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

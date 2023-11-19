#include "mesinkata.h"
#include "ADT.h"
#include "play.h"
#include "playlist.h"
#include "Cplaylist.h"

int main(){
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetSong song;
    char *file = "config.txt";
    STARTCOM(&Penyanyi, &Album, &song, file);
    CurrentSong play;
        // Inisialisasi objek Song 1
    Song song1 = {"In the Lonely Hour", "Sam Smith", "Stay With Me"};

    // Inisialisasi objek Song 2
    Song song2 = {"Reputation", "Taylor Swift", "Delicate"};

    // Inisialisasi objek Song 3
    Song song3 = {"Happier Than Ever", "Billie Eilish", "Therefore I Am"};

    // Inisialisasi objek Song 4
    Song song4 = {"Future Nostalgia", "Dua Lipa", "Don't Start Now"};

    // Inisialisasi objek Song 5
    Song song5 = {"Beauty Behind the Madness", "The Weeknd", "Can't Feel My Face"};
    queue Q;
    CreateQueue(&Q);

    Stack S;
    CreateEmptyS(&S);
    playsong(&play, Penyanyi, Album, song, &Q, &S);
    printf("%s", play.NamaS);
    ArrayDinPlaylist arr = MakeArrayDin();
    playlistcreate(&arr);
    tambahalbumplaylist(Penyanyi, Album, song, &arr);
    PrintInfo(arr.playlist[0]);
    playplaylist(&play, arr, &Q, &S);
    printf("%s\n", play.NamaS);
    displayQueue(Q);
}
all: run clean

test: src/main/ADT.h src/main/ADT.c src/ADT/List/list.c src/ADT/MesinKalimat/mesinkarakter.c src/ADT/MesinKalimat/mesinkata.c src/ADT/Playlist/playlist.c src/ADT/Queue/queue.c src/ADT/Stack/stack.c src/command/Help/help.c src/command/Load/load.c src/command/Pick/pick.c src/command/Playlist/Cplaylist.c src/command/invalidcommand/invalidcommand.c src/command/Song/song.c src/command/ListC/Clist.c src/command/Play/play.c src/command/Queue/Cqueue.c src/main/main.c
	gcc -o main src/main/ADT.h src/main/ADT.c src/ADT/List/list.c src/ADT/MesinKalimat/mesinkarakter.c src/ADT/MesinKalimat/mesinkata.c src/ADT/Playlist/playlist.c src/ADT/Queue/queue.c src/ADT/Stack/stack.c src/command/Help/help.c src/command/Load/load.c src/command/Pick/pick.c src/command/Playlist/Cplaylist.c src/command/invalidcommand/invalidcommand.c src/command/Song/song.c src/command/ListC/Clist.c src/command/Play/play.c src/command/Queue/Cqueue.c src/main/main.c
run: test
	./main

clean:
	-rm -f *.o main
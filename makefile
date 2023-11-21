all: run clean

test: src/main/ADT.c src/ADT/List/list.c src/ADT/MesinKalimat/mesinkarakter.c \
	src/ADT/MesinKalimat/mesinkata.c src/ADT/Playlist/playlist.c src/ADT/Queue/queue.c \
	src/ADT/Stack/stack.c src/command/Help/help.c src/command/Load/load.c \
	src/command/Pick/pick.c src/command/Playlist/Cplaylist.c src/command/invalidcommand/invalidcommand.c \
	src/command/Song/song.c src/command/ListC/Clist.c src/command/Play/play.c \
	src/command/Queue/Cqueue.c src/main/main.c src/command/Status/status.c src/command/Save/save.c src/command/Enhance/enhance.c
	gcc -o WayangWave src/main/ADT.c src/ADT/List/list.c src/ADT/MesinKalimat/mesinkarakter.c \
	src/ADT/MesinKalimat/mesinkata.c src/ADT/Playlist/playlist.c src/ADT/Queue/queue.c \
	src/ADT/Stack/stack.c src/command/Help/help.c src/command/Load/load.c \
	src/command/Pick/pick.c src/command/Playlist/Cplaylist.c src/command/invalidcommand/invalidcommand.c \
	src/command/Song/song.c src/command/ListC/Clist.c src/command/Play/play.c \
	src/command/Queue/Cqueue.c src/main/main.c src/command/Status/status.c \
	src/command/Enhance/enhance.c src/command/Save/save.c
run: test
	./WayangWave

clean:
	-rm -f *.o WayangWave
#ifndef __song__
#define __song__

#include "boolean.h"
#include <stdio.h>
#include "../../main/ADT.h"
#include "../../ADT/Queue/queue.h"
#include "../Pick/pick.h"
#include "../../ADT/Stack/stack.h"

/* Lanjut ke lagu berikutnya */
/* IS : Currentsong, queue, stack terdefinisi */
/* FS : Lagu yang paling depan di queue akan berada di current song, current song awal masuk ke stack */
void songnext(CurrentSong *play, queue *currentqueue, Stack *previous);

/* Lanjut ke lagu sebelumnya */
/* IS : Currentsong, queue, stack terdefinisi */
/* FS : Lagu yang paling atas di stack, di pop, kemudian menjadi current song, current song masuk ke queue */
void songprevious(CurrentSong *play, queue *currentqueue, Stack *previous);


#endif
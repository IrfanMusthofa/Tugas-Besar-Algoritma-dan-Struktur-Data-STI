#ifndef __song__
#define __song__

#include "boolean.h"
#include <stdio.h>
#include "../../main/ADT.h"
#include "../../ADT/Queue/queue.h"
#include "../Pick/pick.h"
#include "../../ADT/Stack/stack.h"

void songnext(CurrentSong *play, queue *currentqueue, Stack *previous);

void songprevious(CurrentSong *play, queue *currentqueue, Stack *previous);


#endif
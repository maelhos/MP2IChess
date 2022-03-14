#include <stdio.h>
#include "defs.h"
#include "init.h"
#include "move.h"

struct _mvStack {
  struct _mvStack* previous;
  S_Move* move;
};
typedef struct _mvStack* S_MoveStack;

S_MoveStack createEmptyMoveStack();
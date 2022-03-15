#pragma once
#include <stdio.h>
#include "defs.h"
#include "move.h"

struct _smv{
  S_Move move;
  int castlePerm;
  int enPas;
  int fiftyMove;
  U64 posKey;
};
typedef struct _smv S_PlayedMove;

struct _mvStack {
  struct _mvStack* previous;
  S_PlayedMove* move;
};
typedef struct _mvStack* S_MoveStack;

S_MoveStack createEmptyMoveStack();
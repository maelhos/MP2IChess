#include <stdio.h>
#include "defs.h"
#include "init.h"

struct _mv{
  int move;
  int castlePerm;
  int enPas;
  int fiftyMove;
  U64 posKey;
};
typedef struct _mv S_Move;
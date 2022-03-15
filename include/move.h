#pragma once
#include <stdio.h>
#include "defs.h"
#include "init.h"

enum { m_MOVE, m_CAPTURE, m_CASTLE, m_PROMOTE};

struct _mv{
  int tag;
  int start;
  int stop;
};
typedef _mv* S_Move;

void printMove(int move);
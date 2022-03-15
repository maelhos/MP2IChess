#pragma once

#include "defs.h"
#include "board.h"

void AllInit();
void InitSq120To64();

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64To120[64];
#define SQ64(sq120) Sq120ToSq64[sq120]
#define SQ120(sq64) Sq64To120[sq64]
#ifndef INIT_H
#define INIT_H

#include "defs.h"

void AllInit();
void InitSq120To64();

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64To120[64];
#define SQ64(sq120) Sq120ToSq64[sq120]

#endif
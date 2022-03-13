#include "init.h"
#include "defs.h"

void Allinit(){
  InitSq120To64();
}

void InitSq120To64(){
  int sq = A1;
  int sq64 = 0;
  for (int i = 0; i < BRD_SQ_NUM; i++)
  {
    Sq120ToSq64[i] = 65;
  }
  
  for (int i = 0; i < 64; i++)
  {
    Sq64To120[i] = 120;
  }
  
  for (int rank = RANK_1; rank <= RANK_8; rank++)
  {
    for (int file = FILE_A; file <= FILE_H; file++)
    {
      sq = FR2SQ(file, rank);
      Sq64To120[sq64] = sq;
      Sq120ToSq64[sq] = sq64;
      sq64++;
    }
  }
}
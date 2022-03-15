#include "move.h"

void printMove(int move){
  char letters[] = "ABCDEFGH";
  char numbers[] = "12345678";
  printf("%c%c\n",letters[SQ64(move) % 8],numbers[SQ64(move)/8]);
} 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "defs.h"
#include "init.h"
#include "board.h"
#include "bitboard.h"
#include "move.h"
#include "printboard.h"

int main(int argc, char** argv){

	AllInit();
  
	S_Board mainBoard;
  initBoardToDefault(&mainBoard);
  printBoard(&mainBoard);
  printf("%lld\n",mainBoard.posKey);
	return 0;
}
#include "printboard.h"

void printBoard(S_Board* board){
	int p = 0;
	
	printf("\n");
	for(int rank = RANK_8; rank >= RANK_1; --rank) {
		for(int file = FILE_A; file <= FILE_H; ++file) {
			p = board->pieces[FR2SQ(file,rank)];	// 120 based		
			
			switch (p){
      case wP:
        printf("P ");
        break;
      case bP:
        printf("p ");
        break;
      case wK:
        printf("K ");
        break;
      case bK:
        printf("k ");
        break;
      case wQ:
        printf("Q ");
        break;
      case bQ:
        printf("q ");
        break;
      case wR:
        printf("R ");
        break;
      case bR:
        printf("r ");
        break;
      case wB:
        printf("B ");
        break;
      case bB:
        printf("b ");
        break;
      case wN:
        printf("N ");
        break;
      case bN:
        printf("n ");
        break;  
      case EMPTY:
        if ((file+rank) & 1){
          printf("- ");
        }
        else{
          printf("X ");
        }
        break;
      }
		}
		printf("\n");
	}  
    printf("\n\n");
}
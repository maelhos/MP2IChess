
#include "board.h"


void initBoardToDefault(S_Board* board){
  int pieces[BRD_SQ_NUM];
  U64 pawns[3]; // 3 because 3 colors, make things faster and easier

  int KingSq[2]; // position of the kings
  int side; // side to move

  int enPas; // enPassant (if possible)
  int fiftyMove; // draw by 50 move repetition

  int ply;
  int hisPlay; // total number of plys

  int castlePerm; // castle rights for both

  U64 posKey; // Zobrist hash of the position

  int pceNum[13]; // number of each pieces
  int bigPce[3]; // store pieces that are not pawns
  int majPce[3]; // rooks and queens
  int minPce[3]; // knights and bishops
  
  S_MoveStack history;

  int pList[13][10];
  // pList[wN][4] = E1 (exemple)
}
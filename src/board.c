
#include "board.h"


void initBoardToDefault(S_Board* board){
  board->pieces[A1] = wR;
  board->pieces[B1] = wN;
  board->pieces[C1] = wB;
  board->pieces[D1] = wQ;
  board->pieces[E1] = wK;
  board->pieces[F1] = wB;
  board->pieces[G1] = wN;
  board->pieces[H1] = wR;

  board->pieces[A8] = bR;
  board->pieces[B8] = bN;
  board->pieces[C8] = bB;
  board->pieces[D8] = bQ;
  board->pieces[E8] = bK;
  board->pieces[F8] = bB;
  board->pieces[G8] = bN;
  board->pieces[H8] = bR;

  for (int rank = RANK_6; rank >= RANK_3; rank--){
    for (int file = FILE_A; file <= FILE_H; file++)
    {
        board->pieces[FR2SQ(file,rank)] = EMPTY;
    }
  }
  
  //////

  for (int i = A2; i <= H2; i++)
  {
    board->pieces[i] = wP;
    board->pieces[i+50] = bP;
    board->pawns[WHITE] |= (1ULL << SQ64(i));
    board->pawns[BLACK] |= (1ULL << SQ64(i+50));
  }
  setpListAndPce(board);

  setKingPos(board);

  board->side = WHITE;

  board->enPas = 0; // enPassant (if possible)
  board->fiftyMove = 0; // draw by 50 move repetition

  board->ply = 0;
  board->hisPlay = 0; // total number of plys

  board->castlePerm = WKCA | WQCA | BQCA | BKCA; // castle rights for both

  board->posKey = zobrist(board);
  
  board->history = createEmptyMoveStack();
}

void setpListAndPce(S_Board* board){
  int counter[13] = {0};
  for (int i = 0; i < 64; i++)
  {
    int tmp = board->pieces[SQ120(i)];
    if (tmp != EMPTY){
      board->pceNum[tmp]++;
      board->pList[tmp][counter[tmp]] = SQ120(i);
      counter[tmp]++;
    }
  }
}

void setKingPos(S_Board* board){
  for (int i = 0; i < 64; i++)
  {
    if (board->pieces[SQ120(i)] == wK)
      board->KingSq[WHITE] = SQ120(i);
    else if (board->pieces[SQ120(i)] == bK)
      board->KingSq[BLACK] = SQ120(i);
  }
}
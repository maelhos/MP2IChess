#pragma once
#include <stdio.h>
#include "defs.h"
#include "init.h"
#include "moveStack.h"

// the enumerations are indexed so : EMPTY = 0, wP = 1, wN = 2, ...
enum {
  EMPTY, 
  wP, wN, wB, wR, wQ, wK, 
  bP, bN, bB, bR, bQ, bK
};

enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

enum {
  A1 = 21, B1, C1, D1, E1, F1, G1, H1,
  A2 = 31, B2, C2, D2, E2, F2, G2, H2,
  A3 = 41, B3, C3, D3, E3, F3, G3, H3,
  A4 = 51, B4, C4, D4, E4, F4, G4, H4,
  A5 = 61, B5, C5, D5, E5, F5, G5, H5,
  A6 = 71, B6, C6, D6, E6, F6, G6, H6,
  A7 = 81, B7, C7, D7, E7, F7, G7, H7,
  A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    NO_SQ
};
enum {WHITE, BLACK};
enum {WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8}; // WHite/Black - Queen/King Casteling

struct _S_Board{
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
  
  S_MoveStack history;

  int pList[13][10];
  // pList[wN][4] = E1 (exemple)

};
typedef struct _S_Board S_Board;

#define HASH_LEN 64

static U64 get64rand();

U64 hashtab[HASH_LEN][13];

void init_zobrist();
U64 zobrist(S_Board* pieces);

U64 zobristMv(int move, U64 old);

void initBoardToDefault(S_Board* board);
void setpListAndPce(S_Board* board);
void setKingPos(S_Board* board);
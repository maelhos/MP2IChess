#include "board.h"

static U64 get64rand() {
    return
    (((U64) rand() <<  0) & 0x000000000000FFFFull) |
    (((U64) rand() << 16) & 0x00000000FFFF0000ull) |
    (((U64) rand() << 32) & 0x0000FFFF00000000ull) |
    (((U64) rand() << 48) & 0xFFFF000000000000ull);
}

void init_zobrist() {
	for (int i = 0 ; i < HASH_LEN ; i++ ) {
		for (int j = 0 ; j < 13 ; j++ ) {
			hashtab[i][j]  = get64rand();
		}
  }
}

U64 zobrist(S_Board* board){
  U64 hash = 0ULL;
  for (int i = 0; i < HASH_LEN; i++)
  {
    hash ^= hashtab[i][board->pieces[SQ120(i)]];
  }
  return hash;
}
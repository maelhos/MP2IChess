#pragma once

#include <stdlib.h>

typedef unsigned long long U64;

#define NAME "MP2IChess 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048 // seem good enough....

// MACROS
#define FR2SQ(f, r) ( (21 + (f) ) + ( (r) * 10) )

#define DEBUG // this seem complicated but we just use
#ifndef DEBUG // gcc extention to C to track errors
#define ASSERT(n)
#else
#define ASSERT(n) \
if (!(n)) { \
  printf("%s - Failed, ", #n); \
  printf("On %s, ",__DATE__); \
  printf("At %s, ",__TIME__); \
  printf("In File %s, ",__FILE__); \
  printf("At Line %d\n",__LINE__); \
  exit(1);}
#endif
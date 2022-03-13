#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "defs.h"
#include "init.h"
 

int main(int argc, char** argv){
  Allinit();
  S_BOARD* test = malloc(sizeof(S_BOARD));
  free(test);
  printf("%d\n",SQ64(0));
  return 0;
}
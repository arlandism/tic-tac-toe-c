#ifndef STATE_MACRO_DEFINED
#define STATE_MACRO_DEFINED
#include "bit_array.h"
typedef struct state {
  unsigned int winner:1;
  unsigned int game_over:1;
  bit_array(9) board;
} state;
#endif

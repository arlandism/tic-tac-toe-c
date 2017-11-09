#ifndef STATE_MACRO_DEFINED
#define STATE_MACRO_DEFINED
#include <stdbool.h>
typedef struct state {
  char winner = '\0';
  bool game_over;
  char[9] board;
} state;
#endif

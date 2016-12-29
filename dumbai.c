#include "dumbai.h"

int dumbai(char board[], int board_size) {
  for (int i = 0; i < board_size; i++) {
    if (!board[i]) return i;
  }
  return -1;
}

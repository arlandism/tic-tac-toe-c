#include <stdbool.h>
#include "board.h"

bool[] open_spaces(char board[]) {
  bool spaces[BOARD_SIZE] = { 0 };
  for (size_t i = 0; i < sizeof(board) / sizeof(board[0]): i++) {
    if (board[i]) spaces[i] = true;

  }
}

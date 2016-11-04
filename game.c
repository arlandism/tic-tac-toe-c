#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "game.h"
#include "board.h"
#include "tokens.h"
#include "minimax.h"

void Game(char user_token) {
  char ai_token = select_ai_token(user_token);
  char board[BOARD_SIZE] = { 0 };
  bool game_over = false;
  char winner;
  while (!game_over) {
      puts("Select a space");
      board[select_move(board)] = user_token;
      board[minimax(board)] = ai_token;
      winner = game_winner(board);
      if (winner) game_over = true;
    }
  
   if (winner == user_token) {
    puts("Congratulations! You won.");
  } else {
    puts("Sorry, you lost.");
  }
}

int select_move(char board[]) {
  size_t i;
  for (i = 0; i < BOARD_SIZE; i++) {

  }
  return 0;
}

int ai_move(char board[]) {
  return 0;
}

char ai_token(char user_token) {
  return '\0';
}

bool is_game_over(char *board) {
  return false;
}

char game_winner(char *board) {
  return '\0';
}

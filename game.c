#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
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
      print_available_spaces(board);
      print_board(board);
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
  int space;
  bool valid = false;
  while (!valid) {
    space = (int) scanf("%d", &space);
    if (board[space]) {
      valid = true;
    }
  }
  printf("space is %d", space);
  return space;
}

int ai_move(char board[]) {
  return 0;
}

char ai_token(char user_token) {
  return '\0';
}

char game_winner(char board[]) {
  size_t i, j;
  int dimension_len = sqrt(BOARD_SIZE);
  return '\0';
}

void print_available_spaces(char board[]) {
  printf("\n");
  for (size_t i = 0; i < BOARD_SIZE; i++) {
    if (!board[i]) printf("%zd ", i);
  }
  printf("\n");
}

void print_board(char board[]) {
  int dimension_len = sqrt(BOARD_SIZE);
  printf("\n");
  for (size_t i = 0; i < BOARD_SIZE; i++) {
    printf(" %3c |", board[i]);
    if ((i + 1) % dimension_len == 0)
       printf("\n");
  }
  printf("\n");
}

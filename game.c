#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "game.h"
#include "tokens.h"
#include "dumbai.h"

void Game(char user_token) {
  char ai_token = select_ai_token(user_token);
  char board[BOARD_SIZE] = { '\0' };
  bool game_over = false;
  char winner;
  while (!game_over) {
    user_move(board, user_token);
    game_over = game_winner(board) || board_full(board);
    if (!game_over) {
      ai_move(board, ai_token);
      game_over = game_winner(board) || board_full(board);
    }
  }

  print_board(board);
  if (game_winner(board) == user_token) {
   puts("Congratulations! You won.");
  } else {
    puts("Sorry, you lost.");
  }
}

void user_move(char board[], char user_token) {
  puts("Select a space.");
  print_available_spaces(board);
  print_board(board);
  int user_move = select_move(board);
  board[user_move] = user_token;
}

void ai_move(char board[], char ai_token) {
  int move = dumbai(board, BOARD_SIZE);
  board[move] = ai_token;
  printf("AI chose %d\n", move);
}

int select_move(char board[]) {
  int space;
  bool valid = false;
  while (!valid) {
    scanf("%d", &space);
    if (space < BOARD_SIZE && space >= 0 && !board[space]) {
      valid = true;
    } else {
      printf("Space must be between 0 and %d, and can't currently be occupied\n", BOARD_SIZE);
    }
  }
  printf("You chose %d\n", space);
  return space;
}

char game_winner(char board[]) {
  char row_win = row_winner(board);
  char col_win = column_winner(board);
  char diag_win = diagonal_winner(board);
  if (row_win) {
    printf("Row winner is %c\n", row_win);
    return row_win;
  } else if (col_win) {
    return col_win;
  } else {
    return diag_win;
  }
}

char row_winner(char board[]) {
  for (int i = 0; i < BOARD_SIZE; i = i + DIMENSION_SIZE) {
    bool winner = true;
    for (int j = i + 1; j < i + DIMENSION_SIZE; j++) {
      winner = winner && board[i] && board[i] == board[j];
    }
    if (winner) return board[i]; // first space in row
  }
  return '\0';
}

char column_winner(char board[]) {
  for (int i = 0; i < DIMENSION_SIZE; i++) {
    bool winner = true;
    for (int j = i + DIMENSION_SIZE; j < BOARD_SIZE; j = j + DIMENSION_SIZE) {
      winner = winner && board[i] && board[i] == board[j];
    }
    if (winner == true) {
      return board[i];
    }
  }
  return '\0';
}

char diagonal_winner(char board[]) {
  bool winner;
  for (int i = DIMENSION_SIZE + 1; i < BOARD_SIZE; i = i + DIMENSION_SIZE + 1) {
    winner = true;
    winner = winner && board[i] && board[i] == board[0];
  }

  if (winner) return board[0];

  for (int i = (DIMENSION_SIZE - 1) + (DIMENSION_SIZE - 1); i < BOARD_SIZE - (DIMENSION_SIZE - 1); i = i + DIMENSION_SIZE - 1) {
    winner = true;
    winner = winner && board[i] && board[i] == board[DIMENSION_SIZE - 1];
  }

  if (winner) return board[DIMENSION_SIZE - 1];

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

bool board_full(char board[]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (!board[i]) return false;
  }
  return true;
}

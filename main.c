#include <stdio.h>
#include <stdbool.h>
#include "game.h"

char select_token();

int main() {
  char token;
  puts("Welcome to Tac Toe Toe!");

  token = select_token();
  printf("Great! You chose %c\n", token);
  Game(token);

  return 0;
}

char select_token() {
  bool valid = false;
  char token;
  while (!valid) {
    puts("Would you like to play as X or O?");
    scanf(" %c", &token); /* skip leading whitespace in char selection */
    if (token == 'X' || token == 'O') {
      valid = true;
    } else {
      puts("You have selected an invalid choice");
    }
  }
  return token;
}



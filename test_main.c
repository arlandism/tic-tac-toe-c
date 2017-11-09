#include <stdio.h>
#include <stdbool.h>

typedef struct state {
  bool game_over;
  char winner;
  char current_player_token;
  int board_size;
  int dimension;
  char board[];
} state;

state initState() {
  state s = {
    .game_over = false,
    .current_player_token = 'X',
    .board_size = 9,
    .dimension = 3
  };
  return s;
}

char current_player_token(char token) {
  if (token == 'X') return 'O';
  return 'X';
}

void place_move(int move, char token, state s) {
  s.board[move] = token;
}

void set_winner(state *s) {
  s->winner = 'O';
  s->game_over = true;
}

// assume humans are X
int get_move(state s) {
  if (s.current_player_token == 'X') {
    int m;
    scanf("%d", &m);
    return m;
  } else {
    return 7;
  }
}

void print_board(state s) {
  for(size_t i = 0; i < s.board_size; i++) {
    if (s.board[i]) {
      printf("%3c", s.board[i]);
    } else {
      printf("   ");
    }

    if(i % s.dimension == 0) {
      printf("\n");
    } else {
      printf("|");
    }
  }
  printf("\n");
}

int main(int argc, char** argv) {
  state s = initState();
  int i = 0;
  while(!s.game_over || i < 2) {
    int m = get_move(s);
    char token = current_player_token(s.current_player_token);
    place_move(m, token, s);
    set_winner(&s);
    print_board(s);
    i++;
  }
  printf("Hello world!\n");
  return 0;
}

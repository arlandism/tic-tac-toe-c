
# Layout

## Data Structures
- need to represent whether the game has a winner and who that is
- 1 winner bit set to 1 if X won and 0 if 0 won
- 1 game over bit set to 1 if game is over and 0 otherwise
- representation of board layout could be array of N bits,
  where N is number of total spaces,
  set to 1 if X moves and 0 if 0 moves (empty needs to be distinct from 0)

## Minimax
- take current board state
- for each empty bit in board, copy the board,
```c
int minimax(state *s) {
  int []open_moves = available_moves(s);
  len = sizeof(open_moves) / sizeof(int) # length of open moves
  if (s->winner || s->game_over) return terminal_state(s);
  bit best_move;
  for (size_t i = 0; i < len; i++) {
    bit_array *b_copy
    bit_array b = copy_board(&b_copy, s->board);
    if (score > best_move) best_move = i;
    make_move(b_copy, s->current_player, best_move(b_copy));
    s->current_player = toggle_player(s->current_player);
    score = minimax(s);
  }
}

int best_move(bit_array *b) {

}
```

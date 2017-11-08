
# Layout

## Data Structures
- need to represent whether the game has a winner and who that is
- 1 winner bit set to 1 if X won and 0 if 0 won
- 1 game over bit set to 1 if game is over and 0 otherwise
- representation of board layout could be array of N bits,
  where N is number of total spaces,
  set to 1 if X moves and 0 if 0 moves (empty needs to be distinct from 0)


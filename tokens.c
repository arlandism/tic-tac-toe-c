#include "tokens.h"

char select_ai_token(char user_token) {
  if (user_token == 'X') return 'O';
  return 'X';
}

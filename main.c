#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "setting.c"
#include "card.c"
#include "command.c"
#include "interface.c"

int main() {
  resetDeck();
  shuffleDeck();
  emptyPlayerDeck(&player1);
  dealFromDeck(&player1);
  do {
    update();
  } while (TRUE);
}

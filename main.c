#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "setting.c"
#include "card.c"

int main() {
  resetDeck();
  shuffleDeck();
  int i;
  emptyPlayerDeck(&player1);
  dealFromDeck(&player1);
  printf("Player 1 Cards : \n");
  for (i=0;i<player1.cardLength;i++) {
      printf("%d%c ",getCardValue(player1.card[i]), getCardSymbol(player1.card[i]));
  }

  printf("\nDeck cards now : %d\n", deckLengthNow);
  emptyPlayerDeck(&player2);
  dealFromDeck(&player2);
  printf("Player 2 Cards : \n");
  for (i=0;i<player2.cardLength;i++) {
      printf("%d%c ",getCardValue(player2.card[i]), getCardSymbol(player2.card[i]));
  }
  printf("\nDeck cards now : %d\n", deckLengthNow);

}

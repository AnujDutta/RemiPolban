#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "setting.c"
#include "card.c"
#include "command.c"

int main() {
  resetDeck();
  shuffleDeck();
  int i;
  char command[100];
  int a, b;
  emptyPlayerDeck(&player1);
  dealFromDeck(&player1);
  do {
    printf("Player 1 Cards : \n");
    for (i=0;i<player1.cardLength;i++) {
        printf("%d%c ",getCardValue(player1.card[i]), getCardSymbol(player1.card[i]));
    }
    printf("\nEnter Command : ");
    scanf("%s %d,%d", &command, &a, &b);
    commands(&player1, command, a, b);
  } while (TRUE);
}

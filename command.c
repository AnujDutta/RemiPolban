void commands(playerControl *player, char command[], int a, int b) {
  if (strcmp(command, "swap")==0) {
    if (a<=player->cardLength && b<=player->cardLength && a>0 && b>0) {
      swapCard(player->card, a-1, b-1);
    }
    else {
      strcpy(errorMessage, "Input Salah");
    }
  }
  else if (strcmp(command, "deal")==0) {
    if (player->cardLength<PLAYER_CARD_LENGTH) {
      getFromDeck(player, player->cardLength);
    }
    else {
      strcpy(errorMessage, "Deck sudah Penuh");
    }
  }
  else if (strcmp(command, "trash")==0) {
    if (a<=player->cardLength  && a>0) {
      trashCard(player, a-1);
    }
    else {
      strcpy(errorMessage, "Input Salah");
    }
  }
  else if (strcmp(command, "sort")==0) {
    sortDeck(player);
  }
}

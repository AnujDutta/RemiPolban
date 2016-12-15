void commands(playerControl *player, char command[], int a, int b) {
  if (strcmp(command, "swap")==0) {
    if (a<=player->cardLength && b<=player->cardLength) {
      swapCard(player->card, a-1, b-1);
    }
    else {
      printf("Input Salah\n");
    }
  }
  else if (strcmp(command, "deal")==0) {
    if (player->cardLength<=8) {
      getFromDeck(player, player->cardLength);
    }
    else {
      printf("Deck sudah Penuh\n");
    }
  }
}

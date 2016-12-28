void gameInit();
void roundInit();
void setPlayerScore(playerControl *player, int x);

void gameInit() {
  setPlayerScore(&player1, 0);
  setPlayerScore(&player2, 0);

  roundInit();
}

void roundInit() {
  resetDeck();
  shuffleDeck();

  emptyPlayerDeck(&player1);
  emptyMeldDeck(&player1);
  dealFromDeck(&player1);
  player1.melded = 0;

  emptyPlayerDeck(&player2);
  emptyMeldDeck(&player2);
  dealFromDeck(&player2);
  player2.melded = 0;
}

void setPlayerScore(playerControl *player, int x) {
  player->score = x;
}

int groupCheck(playerControl *player) {
  int i=0, status;
  status = 1;
  while(i<player->meldLength-1 && status) {
    if (getCardValue(player->meldCard[i]) != getCardValue(player->meldCard[i+1])) {
      status=0;
    }
    i++;
  }
  return status;
}

int sequenceCheck(playerControl *player) {
  int status;
  status = 0;
  sortDeckBySymbol(player->meldCard, player->meldLength);
  if (getCardSymbol(player->meldCard[0])==getCardSymbol(player->meldCard[player->meldLength-1])) { //Sama simbol
    if (getCardValue(player->meldCard[player->meldLength-1])-getCardValue(player->meldCard[0])+1 == player->meldLength) { //Berurutan
      status = 1;
    }
  }
  return status;
}

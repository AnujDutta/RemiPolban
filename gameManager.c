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

  now.turn = 0;
  now.playerNumber=1;
}

void setPlayerScore(playerControl *player, int x) {
  player->score = x;
}

int groupCheck(int card[], int length) {
  int i=0, status;
  status = 1;
  while(i<length-1 && status) {
    if (getCardValue(card[i]) != getCardValue(card[i+1])) {
      status=0;
    }
    i++;
  }
  return status;
}

int sequenceCheck(int card[], int length) {
  int status;
  status = 0;
  if (getCardSymbol(card[0])==getCardSymbol(card[length-1])) { //Sama simbol
    if (getCardValue(card[length-1])-getCardValue(card[0])+1 == length) { //Berurutan
      status = 1;
    }
  }
  return status;
}

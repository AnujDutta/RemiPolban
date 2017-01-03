void copyPlayerCard(playerControl *player, int tempBrain[]) {
  int i;
  for(i=0;i<player->cardLength;i++) {
    tempBrain[i]=player->card[i];
  }
}

void emptyTempBrain(int tempBrain[]) {
  int i;
  for(i=0;i<PLAYER_CARD_LENGTH;i++) {
    tempBrain[i]=0;
  }
}
void printAICard(int tempBrain[], int length) {
  int i;
  for(i=0;i<length;i++) {
    printf("%d%c ",getCardValue(tempBrain[i]), getCardSymbol(tempBrain[i]));
  }
}

int searchSymbol(int tempBrain[], int length) {
  int ketemu, i;
  ketemu = 0;
  i=0;
  sortDeckBySymbol(tempBrain, length);
  while (i<length && !ketemu) {
    // for(i=0;i<3)
  }
}

void startAI(playerControl *player) {
  int tempBrain[PLAYER_CARD_LENGTH];
  int length;
  if (trashLengthNow==0) {
    getFromDeck(player);
  }
  else {
    emptyTempBrain(tempBrain);
    copyPlayerCard(player, tempBrain);
    tempBrain[player->cardLength]=trashDeck[0]; // get from trashDeck
    length = player->cardLength+1;
    printf("\nCard : \n");
    printAICard(tempBrain, length);
    printf("\n");
    printf("\nCard : \n");
  }
}

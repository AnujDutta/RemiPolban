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
  int tempMeld[4];
  int ketemu, i, x, y;
  ketemu = 0;
  i=0;
  sortDeckByNumber(tempBrain, length);
  while (i<length-2 && !ketemu) {
    if (i+4<=length) {
      y=4;
    }
    else {
      y=3;
    }
    while(y>=3) {
      for(x=0;x<4;x++) {
        tempMeld[x]=tempBrain[i+x];
      }
      ketemu = groupCheck(tempMeld, y);
      if (ketemu) {
        ketemu = i*10+y;
        break;
      }
      y--;
    }
    i++;
  }
  return ketemu;
}

void startAI(playerControl *player) {
  int tempBrain[PLAYER_CARD_LENGTH];
  int length;
  int jadi;
  int i;
  if (trashLengthNow==0) {
    getFromDeck(player);
  }
  else {
    emptyTempBrain(tempBrain);
    copyPlayerCard(player, tempBrain);
    tempBrain[player->cardLength]=trashDeck[0]; // get from trashDeck
    length = player->cardLength+1;
    if (searchSymbol(tempBrain, length)) {
      getFromTrash(player);
    }
    else {
      getFromDeck(player);
    }
  }

  jadi = searchSymbol(player->card, player->cardLength);
  if (jadi) {
    for(i=0;i<(jadi%10);i++) {
      insertMeldCard(player, jadi/10);
    }
  }

  trashCard(player, 0);

  if (player->meldLength>=3) {
    if (sequenceCheck(player->meldCard, player->meldLength)) {
      for(i=player->meldLength;i>0;i--) {
        player->score+=getCardScore(getCardValue(player->meldCard[0]));
        deleteMeld(player, 0);
      }
    }
    else if (groupCheck(player->meldCard, player->meldLength)) {
     for(i=player->meldLength;i>0;i--) {
        player->score+=getCardScore(getCardValue(player->meldCard[0]));
        deleteMeld(player, 0);
      }
    }
  }
}

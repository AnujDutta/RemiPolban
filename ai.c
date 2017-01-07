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

int searchSequence(int tempBrain[], int length) {
  int tempMeld[length];
  int ketemu, i, j, k, l;
  ketemu = 0;
  i=0;
  sortDeckBySymbol(tempBrain, length);
  while (i<length-2 && !ketemu) {
    for (j=length-i;j>2;j--) {
      l=0;
      for (k=i;k<j;k++) {
        tempMeld[l]=tempBrain[k];
        l++;
      }
      printAICard(tempMeld, j);
      system("pause");
    }
    i++;
  }
  return ketemu;
}

void trashAI(playerControl *player) {
  int i;
  srand(time(NULL));
  trashCard(player, rand() % (player->cardLength-1));
}
void startAI(playerControl *player) {
  int tempBrain[PLAYER_CARD_LENGTH];
  int length;
  int jadi;
  int i;
  // if (trashLengthNow==0) {
  //   getFromDeck(player);
  // }
  // else {
    emptyTempBrain(tempBrain);
    copyPlayerCard(player, tempBrain);
  //   tempBrain[player->cardLength]=trashDeck[0]; // get from trashDeck
    length = player->cardLength;
    if (searchSequence(tempBrain, length)) {
      printf("Asu\n");
      system("pause");
  //     getFromTrash(player);
    }
  //   else {
  //     getFromDeck(player);
  //   }
  // }
  //
  // jadi = searchSymbol(player->card, player->cardLength);
  // if (jadi) {
  //   for(i=0;i<(jadi%10);i++) {
  //     insertMeldCard(player, jadi/10);
  //   }
  // }
  //
  // trashAI(player);
  //
  // if (player->meldLength>=3) {
  //   if (sequenceCheck(player->meldCard, player->meldLength) || groupCheck(player->meldCard, player->meldLength)) {
  //     pushMeld(player);
  //   }
  // }
}

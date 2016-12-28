void commands(playerControl *player, char command[]) {
  int paramA, paramB;
  char cParamA[100];
  if (strcmp(command, "swap")==0) {
    scanf("%d,%d", &paramA, &paramB);
    if (paramA<=player->cardLength && paramB<=player->cardLength && paramA>0 && paramB>0) {
      swapCard(player->card, paramA-1, paramB-1);
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
    scanf("%d",&paramA);
    if (paramA<=player->cardLength  && paramA>0) {
      trashCard(player, paramA-1);
    }
    else {
      strcpy(errorMessage, "Input Salah");
    }
  }
  else if (strcmp(command, "sort")==0) {
    sortDeck(player);
  }
  else if (strcmp(command, "meld")==0) {
    scanf("%d", &paramA);
    if (paramA<=player->cardLength  && paramA>0) {
      insertMeldCard(player, paramA-1);
    }
    else {
      strcpy(errorMessage, "Input Salah");
    }
  }
  else if (strcmp(command, "god_mode")==0) {
    scanf("%s", &cParamA);
    if (strcmp(cParamA, "on")==0) {
      godMode = 1;
    }
    else if (strcmp(cParamA, "off")==0) {
      godMode = 0;
    }
    else {
      strcpy(errorMessage, "Parameter Salah");
    }
  }
  else if (strcmp(command, "set_score")==0) {
    scanf("%d", &paramA);
    if (godMode==1) {
      setPlayerScore(player, paramA);
    }
    else {
      strcpy(errorMessage, "Akses ditolak");
    }
  }
  else {
    strcpy(errorMessage, "Perintah tidak ditemukan");
  }
}

void help();

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
  else if (strcmp(command, "sort_symbol")==0) {
    sortDeckBySymbol(player->card, player->cardLength);
  }
  else if (strcmp(command, "sort_number")==0) {
    sortDeckByNumber(player->card, player->cardLength);
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
  else if (strcmp(command, "polban")==0) {
    if (player->meldLength>=3) {
      if (sequenceCheck(player) || groupCheck(player)) {
        strcpy(errorMessage, "MENANG!!!!!");
      }
    }
    else {
      strcpy(errorMessage, "Jumlah kartu tidak memennuhi");
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
  else if (strcmp(command, "help")==0)
  {
    help();
  }
  else {
    strcpy(errorMessage, "Perintah tidak ditemukan");
  }
}

void help()
{
  system("cls");
  printf("Command Dalam Game\n\n"

    "Swap\t		Menukar kartu yang di tangan --> swap(*posisi kartu 1,*posisi kartu 2)\n"
    "Deal\t		Untuk mengambil kartu dari deck\n"
    "Trash\t		Untuk membuang kartu --> trash(*posisi kartu)\n"
    "Sort\t		Mengurutkan kartu yang ada di tangan \n"
    "Meld\t\t	Menyatukan kartu yang sudah jadi --> meld(*posisi kartu)\n"
    "God_mode\t	Cari saja sendiri apa fungsinya hehehe\n"
    );
  system("pause");
}

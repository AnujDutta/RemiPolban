void gameInit() {
  setPlayerScore(&player1, 0);
  setPlayerScore(&player2, 0);
  getPlayerName();
  getPlayerStatus();

  FILE *pf;
  pf=fopen("log.dat","w");
  fclose(pf);
  roundInit();
}

void roundInit() {
  resetDeck();
  shuffleDeck();
  emptyTrash();

  emptyPlayerDeck(&player1);
  emptyMeldDeck(&player1);
  dealFromDeck(&player1);
  player1.melded = 0;

  emptyPlayerDeck(&player2);
  emptyMeldDeck(&player2);
  dealFromDeck(&player2);
  player2.melded = 0;

  now.playerNumber=1;
  now.turn=1;
}

void setPlayerScore(playerControl *player, int x) {
  player->score = x;
}

void setPlayerName(playerControl *player, char name[]) {
  strcpy(player->playerName, name);
}

//Difficulty untuk AI (Belum beres)
// void setDifficulty(int n){
//   now.difficulty=n;
// }

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

void changeTurn() {
  if (now.playerNumber==1) {
    now.playerNumber = 2;
    now.turn = 1;
  }
  else if (now.playerNumber==2) {
    now.playerNumber = 1;
    now.turn = 1;
  }
}

void minScore(playerControl *player) {
  int i;
  for(i=player->cardLength;i>0;i--) {
    player->score-=getCardScore(getCardValue(player->card[0]));
    trashCard(player, 0);
  }
}

void cardText(char cardText[], int card) {
  char value[3];
  sprintf(value, "%d", getCardValue(card));
  strcpy(cardText, value);
  switch(getCardSymbol(card)) {
    case HEART : strcat(cardText, " Heart");break;
    case DIAMOND : strcat(cardText, " Diamond");break;
    case CLUB : strcat(cardText, " Club");break;
    case SPADE : strcat(cardText, " Spade");break;
  }
}

void sendLog(playerControl player, char log[])
{
  char log2[100];
  time_t rawtime;
  struct tm * timeinfo;
  // int i;
  FILE *pf;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  strcpy(log2,asctime (timeinfo));
  strtok(log2,"\n");

  if((pf=fopen("log.dat","a"))==NULL)
  {
    printf("File log tidak ada");
    exit(1);
  }
  else
  {
    fprintf(pf,"%s %s %s\n",log2, player.playerName, log);
  }
  fclose(pf);
}

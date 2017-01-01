void update() {
  char command[100];
  int i;
  system("cls");
  printErrorMessage();
  printf("Player 1 Score : %d\n", player1.score);
  printf("Player 2 Score : %d\n", player2.score);
  printf("Jumlah Kartu di Deck : %d\n",deckLengthNow);

  printf("Trash Cards : \n");
  printf("%d%c ",getCardValue(trashDeck[0]), getCardSymbol(trashDeck[0]));

  printf("\nPlayer 1 Meld Card : \n");
  printMeldCard(&player1);

  printf("\nPlayer 1 Card : \n");
  printPlayerCard(&player1);

  printf("\nEnter Command : ");
  scanf("%s", &command);
  commands(&player1, command);
}

void HowToPlay()
{
  printf("Syalalal");
}

void StartGame() // pindahan dari main
{
  gameInit();
  do {
    do {
      update();
    } while (deckLengthNow!=0 && player1.melded<2 && player2.melded<2);
    printf("Round End\n");
    system("pause");
    roundInit();
  } while (player1.score < WIN_SCORE && player2.score < WIN_SCORE);
  printf("Game End\n");
}

void menuDisplay(int i)
{
  int line;
  system("cls");
  FILE *fp;
  char buff[125];
  fp=fopen("menuDisplay.txt","r");
  printf("\n");
  for(line=1;line<=7;line++) {
    fgets(buff,125,(FILE*)fp);
    printf("%s", buff);
  }
  printf("\n\n\n\n\n");
  for(line=8;line<=12;line++) {
    fgets(buff,125,(FILE*)fp);
    if((i+2)%3==0)
      printf(BACK_BLU "%s" RESET, buff);
    else
      printf("%s", buff);
  }
  printf("\n");
  for(line=13;line<=18;line++) {
    fgets(buff,125,(FILE*)fp);
    if((i+1)%3==0)
      printf(BACK_BLU "%s" RESET, buff);
    else
      printf("%s", buff);
  }
  printf("\n");
  for(line=19;line<=23;line++) {
    fgets(buff,125,(FILE*)fp);
    if(i%3==0)
      printf(BACK_BLU "%s" RESET, buff);
    else
      printf("%s", buff);
  }
  printf("\n\n");
  fclose(fp);
}

void WelcomeScreen() {
  int i=1;
  char k;
  system("mode 120,35");
  do{
    menuDisplay(i);
    k=getch();
    if(k==80)
      i++;
    else if(k==72)
      i--;
    if(k==13)
      if((i+2)%3==0) {
        system("cls");
        StartGame();
        break;
      }
      else {
        if((i+1)%3==0) {
          system("cls");
          HowToPlay();
          break;
        }
        else {
          if(i%3==0){
            system("cls");
            break;
          }
        }
      }
  } while(TRUE);
}

void printPlayerCard(playerControl *player) {
  int i;
  for (i=0;i<player->cardLength;i++) {
    printf("%d%c ",getCardValue(player->card[i]), getCardSymbol(player->card[i]));
  }
}

void printErrorMessage() {
  if(strcmp(errorMessage, "")!=0) {
    puts(errorMessage);
    strcpy(errorMessage, "");
  }
}

void printMeldCard(playerControl *player) {
  int i;
  for (i=0;i<player->meldLength;i++) {
    printf("%d%c ",getCardValue(player->meldCard[i]), getCardSymbol(player->meldCard[i]));
  }
}

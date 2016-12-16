void update() {
  char command[100];
  int a, b;
  int i;
  system("cls");
  if(strcmp(errorMessage, "")!=0) {
    puts(errorMessage);
    strcpy(errorMessage, "");
  }
  printf("Jumlah Kartu di Deck : %d\n",deckLengthNow);
  printf("Trash Cards : \n");
  printf("%d%c ",getCardValue(trashDeck[0]), getCardSymbol(trashDeck[0]));
  printf("\nPlayer 1 Cards : \n");
  for (i=0;i<player1.cardLength;i++) {
    printf("%d%c ",getCardValue(player1.card[i]), getCardSymbol(player1.card[i]));
  }
  printf("\nEnter Command : ");
  scanf("%s %d,%d", &command, &a, &b);
  commands(&player1, command, a, b);
}

void HowToPlay()
{
  printf("Syalalal");
}

void StartGame() // pindahan dari main
{
  resetDeck();
  shuffleDeck();
  emptyPlayerDeck(&player1);
  dealFromDeck(&player1);
  do {
    update();
  } while (TRUE);
}

void WelcomeScreen()
{
  int choose;

  printf("WELCOME\n");
  printf("\n1. Start\n");
  printf("2. How To Play\n");
  printf("3. Exit\n" );
  printf("Choose the number of the menu: "); scanf("%d", &choose);

  switch(choose)
  {
    case 1:
    system("cls");
    StartGame();

    case 2:
    system("cls");
    HowToPlay();

    case 3:
    system("exit");
  }
}

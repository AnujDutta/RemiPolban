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
  gameInit();
  do {
    update();
  } while (TRUE);
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


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
  system("cls");
  printf("\n");
  printf("    ########   ########## ##      ##  #### ####    ########     #######   ##       ########      ####     ##     ##    \n");
  printf("   ####   ###  ###    ##  ####  ####     ###       ###    ### ####   #### ###      ###    ###   ### ###  ####    ###   \n");
  printf("   ###     ##  ###        ## #### ##     ###       ###    ### ###     ### ###      ###    ### ###    ### ######  ###   \n");
  printf("   ###   ####  #######    ### ## ###     ###       ###    ### ###     ### ###      #########  ###    ### ###########   \n");
  printf("   ########    ##         ### ## ###     ###       #########  ###     ### ###      ###    ### ########## ###  ######   \n");
  printf("   ###  #####  ###    ##  ###    ###     ###       ###        ####   #### ######## ###    ### ###    ### ###    ####   \n");
  printf("    ##    ###  ########## ##     ###  #### ####    ##           #######   ######## ########    ##     ##  ##     ##    \n");
  printf("\n\n\n\n\n");
  if((i+2)%3==0){
    printf(BACK_BLU "                                           ####                                                                        \n" RESET);
    printf(BACK_BLU "                                          ##   #  ##      ####   ####   ##                                             \n" RESET);
    printf(BACK_BLU "                                            ##   ####   ###  ## ### ## ####                                            \n" RESET);
    printf(BACK_BLU "                                         #   ##   ##  # ##   ## ##   #  ##  #                                          \n" RESET);
    printf(BACK_BLU "                                          ####     ###   #### # ##       ###                                           \n" RESET);
  }
  else {
    printf("                                           ####                                                                        \n");
    printf("                                          ##   #  ##      ####   ####   ##                                             \n");
    printf("                                            ##   ####   ###  ## ### ## ####                                            \n");
    printf("                                         #   ##   ##  # ##   ## ##   #  ##  #                                          \n");
    printf("                                          ####     ###   #### # ##       ###                                           \n");
  }
  printf("\n");
  if((i+1)%3==0) {
    printf(BACK_BLU "                    #    #                                               #####                                         \n" RESET);
    printf(BACK_BLU "                    ##  ##  ####  #     #          ##     ####          ##   ## ##    ####  #   #                      \n" RESET);
    printf(BACK_BLU "                    ###### ##  ## ## # ##         ####   ##  ##         ##   ## ##  ###  ## ##  ##                     \n" RESET);
    printf(BACK_BLU "                    ##  ## ##  ## ### ###          ##  # ##  ##         #####   ### ##   ##  #####                     \n" RESET);
    printf(BACK_BLU "                    #    #  ####   #   #            ###   ####          ##      ###  #### #     ##                     \n" RESET);
    printf(BACK_BLU "                                                                                               ##                      \n" RESET);
  }
  else {
    printf("                    #    #                                               #####                                         \n");
    printf("                    ##  ##  ####  #     #          ##     ####          ##   ## ##    ####  #   #                      \n");
    printf("                    ###### ##  ## ## # ##         ####   ##  ##         ##   ## ##  ###  ## ##  ##                     \n");
    printf("                    ##  ## ##  ## ### ###          ##  # ##  ##         #####   ### ##   ##  #####                     \n");
    printf("                    #    #  ####   #   #            ###   ####          ##      ###  #### #     ##                     \n");
    printf("                                                                                               ##                      \n");
  }
  printf("\n");
  if(i%3==0) {
    printf(BACK_BLU "                                               ######                                                                  \n" RESET);
    printf(BACK_BLU "                                               ##             #   ##                                                   \n" RESET);
    printf(BACK_BLU "                                               ####   ##  ## ### ####                                                  \n" RESET);
    printf(BACK_BLU "                                               ##       ##    #   ##  #                                                \n" RESET);
    printf(BACK_BLU "                                               ###### ##  ## ###   ###                                                 \n" RESET);
  }
  else {
    printf("                                               ######                                                                  \n");
    printf("                                               ##             #   ##                                                   \n");
    printf("                                               ####   ##  ## ### ####                                                  \n");
    printf("                                               ##       ##    #   ##  #                                                \n");
    printf("                                               ###### ##  ## ###   ###                                                 \n");  
  }
  printf("\n\n");
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


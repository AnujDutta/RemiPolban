void update() {
  int i, choose, player;

  do {
    do {
      system("cls");
      if (now.playerNumber == 1)
      {
        gameBoard(&player1,&player2);
        playerCommand(&player1);
      }
      else if (now.playerNumber == 2)
      {
        gameBoard(&player2,&player1);
        playerCommand(&player2);
      }
    } while(player1.melded<2 && player2.melded<2 && (player1.cardLength>2 || player1.meldLength!=0) && (player2.cardLength>2 || player2.meldLength!=0) && deckLengthNow!=0);
    gotoxy(83,13);
    if (player1.score>player2.score) {
      printf("Player 1 Win");
    }
    else if (player1.score==player2.score){
      printf("Player Draw");
    }
    else {
      printf("Player 2 Win");
    }
    gotoxy(73,14);
    system("pause");
    roundInit();
  } while(player1.score<WIN_SCORE && player2.score<WIN_SCORE);
  gotoxy(83,13);
  if (player1.score>=WIN_SCORE) {
    printf("Player 1 Win");
  }
  else {
    printf("Player 2 Win");
  }
  gotoxy(73,14);
  system("pause");
}

void gameBoard(playerControl *player, playerControl *opponent){
  printErrorMessage(71,30);
  printBorder(BACK_CYN,69,37,0,0);
  printBorder(BACK_CYN,42,19,68,0);
  printBorder(BACK_CYN,42,19,68,18);
  printPlayerName(opponent,2,1);
  printClosedDeck(24,13);
  gotoxy(26,12);
  printf("%d", deckLengthNow);
  printTrashCard(32,13);
  printMeldCard(player,7,23);
  printPlayerName(player,2,35);
  printPlayerCard(player,7,29);
  gotoxy(71,2);
  printf("Score :");
  gotoxy(71,3);
  printf(" %s\t: %d", player1.playerName, player1.score);
  gotoxy(71,4);
  printf(" %s\t: %d", player2.playerName, player2.score);

  if (debugMode) {
    printPlayerCard(opponent,7,3);
  }
  else {
    printClosedCard(opponent,7,3);
  }
}

void playerCommand(playerControl *player){
    char command[100];

    // printf("%s's Card : \n", opponent->playerName);
    // printClosedCard(opponent,0,2);

    // printf("%s's Score : %d\n",player->playerName, player->score);
    // printf("Jumlah Kartu di Deck : %d\n",deckLengthNow);

    // printf("Trash Cards : \n");
    // printTrashCard();

    // printf("\n%s's Meld Card : \n", player->playerName);
    // printMeldCard(player);

    // printf("\n%s's Card : \n", player->playerName);
    // printPlayerCard(player, 0,28);

    
    if (debugMode) {
      gotoxy(71,33);
      printf("Type Command : ");
      scanf("%s", &command);
      commands(player, command);
    }
    else if (now.turn == 1)
    {
      option1(player,71,19);
      if (strcmp(errorMessage,"")==0) {
        now.turn++ ;
      }
    }
    else if (now.turn == 2)
    {
      option2(player,71,19);
      if (strcmp(errorMessage,"")==0) {
        now.turn++ ;
      }
    }
    else if (now.turn == 3)
    {
      option3(player,71,19);
    }

    // if (strcmp(errorMessage,"")==0) {
    //   now.turn++ ;
    // }
    //
    // if (now.playerNumber==1 && now.turn==4) {
    //   now.playerNumber = 2;
    //   now.turn = 1;
    // }
    // else if (now.playerNumber==2 && now.turn==4) {
    //   now.playerNumber = 1;
    //   now.turn = 1;
    // }
}

void option1(playerControl *player, int x, int y)
{
  int choose;
  gotoxy(x,y);
  printf("1. Take from deck" );
  gotoxy(x,y+1);
  printf("2. Take from trash");
  gotoxy(x,y+2);
  choose=chooseOption(2,x,y);
  switch(choose)
  {
    case 1:
    if (player->cardLength<PLAYER_CARD_LENGTH) {
      getFromDeck(player);
    }
    else {
      strcpy(errorMessage, "Deck sudah Penuh");
    }
    break;
    case 2:
    if (player->cardLength<PLAYER_CARD_LENGTH && trashLengthNow!=0) {
      getFromTrash(player);
    }
    else {
      strcpy(errorMessage, "Deck sudah Penuh atau Trash kosong");
    }
    break;
    case -1:
    debugMode=1;strcpy(errorMessage,"Debug mode on");
    break;
    default:
    strcpy(errorMessage, "Input Salah");
    break;
  }
}

void option2(playerControl *player, int x, int y)
{
  int paramA;
  gotoxy(x,y);
  printf("Pilih kartu yang akan dibuang: ");
  paramA=chooseCard(player,9,31);
  if (paramA<=player->cardLength  && paramA>0) {
    trashCard(player, paramA-1);
  }
  else {
    strcpy(errorMessage,"Debug mode on");
  }
}

void option3(playerControl *player, int x, int y)
{
  int choose, paramA, paramB;
  gotoxy(x,y);
  printf("1. Meld");
  gotoxy(x,y+1);
  printf("2. Take Meld");
  gotoxy(x,y+2);
  printf("3. Swap");
  gotoxy(x,y+3);
  printf("4. Sort by symbol");
  gotoxy(x,y+4);
  printf("5. Sort by number" );
  gotoxy(x,y+5);
  printf("6. End Turn");
  gotoxy(x,y+6);
  printf("7. POLBAN");
  choose=chooseOption(7,x,y);

  switch (choose)
  {
    case 1:
    gotoxy(x,y+8);
    printf("Pilih kartu yang akan dimeld: ");
    paramA=chooseCard(player,9,31);
    if (paramA<=player->cardLength  && paramA>0) {
      insertMeldCard(player, paramA-1);
    }
    else if(paramA==-1){
      strcpy(errorMessage,"Debug mode on");
    }
    else {
      strcpy(errorMessage, "Deck Penuh atau Meld Kosong");
    }
    break;

    case 2:
    gotoxy(x,y+8);
    printf("Pilih kartu yang tidak jadi di meld: " );
    paramA=chooseMeld(player,9,25);
    if(paramA>0){
      getFromMeld(player, paramA-1);
    }
    else if(paramA==0) {
      strcpy(errorMessage,"Deck penuh atau Meld kosong");
    }
    else{
      strcpy(errorMessage,"Debug mode on");
    }
    break;

    case 3:
    gotoxy(x,y+8);
    printf("Pilih kartu 1 yang akan ditukar: ");
    paramA=chooseCard(player,9,31);
    if(paramA<0){
      strcpy(errorMessage, "Debug mode on");
    }
    else if(paramA>0){
      gotoxy(x,y+9);
      printf("Pilih kartu 2 yang akan ditukar: ");
      paramB=chooseCard(player,9,31);
      if(paramB<0){
        strcpy(errorMessage, "Debug mode on");
      }
      else if (paramA<=player->cardLength && paramB<=player->cardLength) {
        swapCard(player->card, paramA-1, paramB-1);
      }
      else {
        strcpy(errorMessage, "Input Salah");
      }
    }
    break;

    case 4:
    sortDeckBySymbol(player->card, player->cardLength);
    break;

    case 5:
    sortDeckByNumber(player->card, player->cardLength);
    break;

    case 6:
    changeTurn();
    break;

    case 7:
    if (player->meldLength>=3) {
      if (sequenceCheck(player->meldCard, player->meldLength) || groupCheck(player->meldCard, player->meldLength)) {
        pushMeld(player);
      }
    }
    else {
      strcpy(errorMessage, "Jumlah kartu tidak memennuhi");
    }
    break;

    case -1:
    debugMode=1;strcpy(errorMessage,"Debug mode on");
    break;

    default:
    strcpy(errorMessage, "Input Salah");
    break;
  }
}

void StartGame() // pindahan dari main
{
  system("mode 111,37");
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

void printPlayerCard(playerControl *player, int x, int y) {
  int i, j;
  gotoxy(x,y);
  for (i=0;i<player->cardLength;i++) {
    switch(player->card[i]) {
      case 0 ... 25:
        printf(BACK_WHT FORE_RED "%s    " RESET " ",getCardNumber(getCardValue(player->card[i])));
        break;
      case 26 ... 51:
        printf(BACK_WHT FORE_BLC "%s    " RESET " ",getCardNumber(getCardValue(player->card[i])));
        break;
      case 52 ... 53:
        printf(BACK_WHT FORE_YEL "%c     " RESET " ", getCardSymbol(player->card[i]));
        break;
    }
  }
  y++;
  for(j=0;j<3;j++){
    gotoxy(x,y);
    for (i=0;i<player->cardLength;i++) {
      printf(BACK_WHT "      " RESET " ");
    }
    y++;
  }
  gotoxy(x,y);
  for (i=0;i<player->cardLength;i++) {
    switch(player->card[i]) {
      case 0 ... 25:
        printf(BACK_WHT FORE_RED "     %c" RESET " ", getCardSymbol(player->card[i]));
        break;
      case 26 ... 51:
        printf(BACK_WHT FORE_BLC "     %c" RESET " ", getCardSymbol(player->card[i]));
        break;
      case 52 ... 53:
        printf(BACK_WHT FORE_YEL "     %c" RESET " ", getCardSymbol(player->card[i]));
        break;
    }
  }
  printf("\n");
}

void printErrorMessage(int x, int y) {
  if(strcmp(errorMessage, "")!=0) {
    gotoxy(x,y);
    puts(errorMessage);
    strcpy(errorMessage, "");
  }
}

void printMeldCard(playerControl *player, int x, int y) {
  int i, j;
  gotoxy(x,y);
  for (i=0;i<player->meldLength;i++) {
    switch(player->meldCard[i]) {
      case 0 ... 25:
        printf(BACK_WHT FORE_RED "%s    " RESET " ",getCardNumber(getCardValue(player->meldCard[i])));
        break;
      case 26 ... 51:
        printf(BACK_WHT FORE_BLC "%s    " RESET " ",getCardNumber(getCardValue(player->meldCard[i])));
        break;
      case 52 ... 53:
        printf(BACK_WHT FORE_YEL "%c     " RESET " ", getCardSymbol(player->meldCard[i]));
        break;
    }
  }
  y++;
  for(j=0;j<3;j++){
    gotoxy(x,y);
    for (i=0;i<player->meldLength;i++) {
      printf(BACK_WHT "      " RESET " ");
    }
    y++;
  }
  gotoxy(x,y);
  for (i=0;i<player->meldLength;i++) {
    switch(player->meldCard[i]) {
      case 0 ... 25:
        printf(BACK_WHT FORE_RED "     %c" RESET " ", getCardSymbol(player->meldCard[i]));
        break;
      case 26 ... 51:
        printf(BACK_WHT FORE_BLC "     %c" RESET " ", getCardSymbol(player->meldCard[i]));
        break;
      case 52 ... 53:
        printf(BACK_WHT FORE_YEL "     %c" RESET " ", getCardSymbol(player->meldCard[i]));
        break;
    }
  }
  printf("\n");
}

void printTrashCard(int x, int y) {
  int i;
  if (trashLengthNow!=0) {
    gotoxy(x,y);
    switch(trashDeck[0]) {
      case 1 ... 26:
        printf(BACK_WHT FORE_RED "%s    " RESET " ",getCardNumber(getCardValue(trashDeck[0])));
        break;
      case 27 ... 52:
        printf(BACK_WHT FORE_BLC "%s    " RESET " ",getCardNumber(getCardValue(trashDeck[0])));
        break;
      case 53 ... 54:
        printf(BACK_WHT FORE_YEL "%c     " RESET " ", getCardSymbol(trashDeck[0]));
        break;
      default:
        printf("XXXXXX ");
        break;
    }
    y++;
    for(i=0;i<3;i++){
      gotoxy(x,y);
      switch(trashDeck[0]){
        case 1 ... 54:
          printf(BACK_WHT "      " RESET " ");
          break;
        default:
          printf("XXXXXX ");
          break;
      }
      y++;
    }
    gotoxy(x,y);
    switch(trashDeck[0]) {
      case 1 ... 26:
        printf(BACK_WHT FORE_RED "     %c" RESET " ", getCardSymbol(trashDeck[0]));
        break;
      case 27 ... 52:
        printf(BACK_WHT FORE_BLC "     %c" RESET " ", getCardSymbol(trashDeck[0]));
        break;
      case 53 ... 54:
        printf(BACK_WHT FORE_YEL "     %c" RESET " ", getCardSymbol(trashDeck[0]));
        break;
      default:
        printf("XXXXXX ");
        break;
    }
  }
  else {
    for(i=0;i<5;i++){
      gotoxy(x,y);
      printf("XXXXXX");
      y++;
    }
  }
}

void HowToPlay()
{
  char back_main;
  char string [125];
  FILE *f;
  int line;

  system ("cls");
  f = fopen ("HowToPlay.txt", "r");
  for (line=0; line<=8; line++){

	fgets(string,125, (FILE*)f);
	printf("%s",string);
}

    fclose (f);

	printf("\nBack To Main menu? (Y/T) ");
    fflush(stdin);
    back_main = getchar();

    if (back_main == 'y' || back_main == 'Y')
    {
      // WelcomeScreen();
    }
    else
    {
      system("exit");
    }
}

void getPlayerName(){
  char name[100];
  printf("Player 1's name : "); scanf("%s",name);
  setPlayerName(&player1, name);
  printf("Player 2's name : "); scanf("%s",name);
  setPlayerName(&player2, name);
}

void getPlayerStatus(){
  int status;
  printf("Player 1's Status : "); scanf("%d",&status);
  player1.status = status;
  printf("Player 2's Status : "); scanf("%s",&status);
  player2.status = status;
}

void gotoxy(int x, int y){
  COORD coord={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printClosedCard(playerControl *player, int x, int y){
  int i,j;
  for(j=0;j<5;j++){
    gotoxy(x,y);
    for(i=0;i<player->cardLength;i++){
      printf(BACK_WHT FORE_BLU "||||||"RESET" ");
    }
    y++;
  }
  printf("\n");
}

void printClosedDeck(int x, int y) {
  int i;
  for(i=0;i<5;i++){
    gotoxy(x,y);
    printf(BACK_WHT FORE_BLU "||||||"RESET);
    y++;
  }
}

void printBorder(char color[], int width, int height, int x, int y){
  int i;
  gotoxy(x,y);
  for(i=0;i<width;i++){
    printf("%s ",color);
  }
  y++;
  for(i=0;i<height-2;i++){
    gotoxy(x,y);
    printf("%s  ", color);
    gotoxy(x+width-2,y);
    printf("%s  ", color);
    y++;
  }
  gotoxy(x,y);
  for(i=0;i<width;i++){
    printf("%s ",color);
  }
  printf(RESET);
}

void printPlayerName(playerControl *player, int x, int y){
  gotoxy(x,y);
  printf(" %s ", player->playerName);
}

void printPlayerScore(playerControl *player, int x, int y){
  gotoxy(x,y);
  printf("%d", player->score);
}

int chooseCard(playerControl *player, int x, int y){
  int i=0,z=0;
  char k;
  do {
    gotoxy((((z%(7*player->cardLength))+(7*player->cardLength))%(7*player->cardLength))+x,y);
    k=getch();
    if(k==77){
      z+=7;
      i++;
    }
    else if(k==75){
      z-=7;
      i--;
    }
    else if(k==96){ //debug button (`)
      debugMode=1;
      return -1;
    }
  }while(k!=13);
  return ((i%player->cardLength)+player->cardLength)%player->cardLength+1;
}

int chooseMeld(playerControl *player, int x, int y){
  if(player->meldLength>0 && player->cardLength<PLAYER_CARD_LENGTH){
    int i=0,z=0;
    char k;
    do {
      gotoxy((((z%(7*player->meldLength))+(7*player->meldLength))%(7*player->meldLength))+x,y);
      k=getch();
      if(k==77){
        z+=7;
        i++;
      }
      else if(k==75){
        z-=7;
        i--;
      }
      else if(k==96){ //debug button (`)
        debugMode=1;
        return -1;
      }
    }while(k!=13);
    return ((i%player->meldLength)+player->meldLength)%player->meldLength+1;
  }
  else{
    return 0;
  }
}

int chooseOption(int num, int x, int y) {
  int i=0;
  char k;
  do{
    gotoxy(x,((i%num)+num)%num+y);
    k=getch();
    if(k==80){
      i++;
    }
    else if(k==72){
      i--;
    }
    else if(k==96){
      debugMode=1;
      return -1;
    }
  }while(k!=13);
  return ((i%num)+num)%num+1;
}

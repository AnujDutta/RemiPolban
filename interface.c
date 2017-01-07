void update() {
  int i, choose, player;

  do {
    do {
      system("cls");
      if (now.playerNumber == 1)
      {
        playerCommand(&player1);
      }
      else if (now.playerNumber == 2)
      {
        playerCommand(&player2);
      }
    } while(player1.melded<2 && player2.melded<2 && (player1.cardLength>2 || player1.meldLength!=0) && (player2.cardLength>2 || player2.meldLength!=0) && deckLengthNow!=0);

    if (player1.score>player2.score) {
      printf("Player 1 Win\n");
    }
    else if (player1.score>player2.score){
      printf("Player Draw\n");
    }
    else {
      printf("Player 2 Win\n");
    }
    system("pause");
    roundInit();
  } while(player1.score<WIN_SCORE && player2.score<WIN_SCORE);

  if (player1.score>=WIN_SCORE) {
    printf("Player 1 Win\n");
  }
  else {
    printf("Player 2 Win\n");
  }
  system("pause");
}

void playerCommand(playerControl *player){
    char command[100];

    printf("%s's Score : %d\n",player->playerName, player->score);
    printf("Jumlah Kartu di Deck : %d\n",deckLengthNow);

    printf("Trash Cards : \n");
    printTrashCard();

    printf("\n%s's Meld Card : \n", player->playerName);
    printMeldCard(player);

    printf("\n%s's Card : \n", player->playerName);
    printPlayerCard(player);
    printErrorMessage();

    if (debugMode) {
      printf("\nChoose Command : ");
      scanf("%s", &command);
      commands(player, command);
    }
    else if (now.turn == 1)
    {
      option1(player);
    }
    else if (now.turn == 2)
    {
      option2(player);
    }
    else if (now.turn == 3)
    {
      option3(player);
    }

    if (strcmp(errorMessage,"")==0 && now.turn != 3) {
      now.turn++ ;
    }
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

void option1(playerControl *player)
{
  int choose;
  printf("Choose Card : \n");
  printf("1. Take from deck\n" );
  printf("2. Take from trash\n");
  scanf("%d",&choose);
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
    default:
    strcpy(errorMessage, "Input Salah");
    break;
  }
}

void option2(playerControl *player)
{
  int paramA;
  printf("\n\nPilih kartu yang akan dibuang: ");
  scanf("%d",&paramA);
  if (paramA<=player->cardLength  && paramA>0) {
    trashCard(player, paramA-1);
  }
}

void option3(playerControl *player)
{
  int choose, paramA, paramB;

  printf("\n1. Meld\n");
  printf("2. Take Meld\n");
  printf("3. Swap\n" );
  printf("4. Sort by symbol\n");
  printf("5. Sort by number\n" );
  printf("6. End Turn\n");
  printf("Pilih angka: ");
  scanf("%d",&choose);

  switch (choose)
  {
    case 1:
    printf("Pilih kartu yang akan dimeld: ");
    scanf("%d", &paramA);
    if (paramA<=player->cardLength  && paramA>0) {
      insertMeldCard(player, paramA-1);
    }
    else {
      strcpy(errorMessage, "Deck sudah Penuh atau Meld Kosong");
    }
    break;

    case 2:
    printf("Pilih kartu yang tidak jadi di meld: " );
    scanf("%d",&paramA);
    if (player->cardLength<PLAYER_CARD_LENGTH && player->meldLength>(paramA-1)) {
      getFromMeld(player, paramA-1);
    }
    else {
      strcpy(errorMessage, "Deck sudah Penuh atau Meld Kosong");
    }
    break;

    case 3:
    printf("Pilih kartu 1 yang akan ditukar: ");
    scanf("%d", &paramA);
    printf("\nPilih kartu 2 yang akan ditukar: ");
    scanf("%d", &paramB);
    if (paramA<=player->cardLength && paramB<=player->cardLength && paramA>0 && paramB>0) {
      swapCard(player->card, paramA-1, paramB-1);
    }
    else {
      strcpy(errorMessage, "Input Salah");
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

    default:
    strcpy(errorMessage, "Input Salah");
    break;
  }
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
            fflush(stdin);
            system("exit");
            break;
          }
        }
      }
  } while(TRUE);
}

void printPlayerCard(playerControl *player) {
  int i, j;
  for (i=0;i<player->cardLength;i++) {
    switch(player->card[i]) {
      case 1 ... 26:
        printf(BACK_WHT FORE_RED "%s    " RESET " ",getCardNumber(getCardValue(player->card[i])));
        break;
      case 27 ... 52:
        printf(BACK_WHT FORE_BLC "%s    " RESET " ",getCardNumber(getCardValue(player->card[i])));
        break;
      case 53 ... 54:
        printf(BACK_WHT FORE_YEL "%c     " RESET " ", getCardSymbol(player->card[i]));
        break;
    }
  }
  printf("\n");
  for(j=0;j<3;j++){
    for (i=0;i<player->cardLength;i++) {
      printf(BACK_WHT "      " RESET " ");
    }
    printf("\n");
  }
  for (i=0;i<player->cardLength;i++) {
    switch(player->card[i]) {
      case 1 ... 26:
        printf(BACK_WHT FORE_RED "     %c" RESET " ", getCardSymbol(player->card[i]));
        break;
      case 27 ... 52:
        printf(BACK_WHT FORE_BLC "     %c" RESET " ", getCardSymbol(player->card[i]));
        break;
      case 53 ... 54:
        printf(BACK_WHT FORE_YEL "     %c" RESET " ", getCardSymbol(player->card[i]));
        break;
    }
  }
  printf("\n");
}

void printErrorMessage() {
  if(strcmp(errorMessage, "")!=0) {
    printf("\n\n");
    puts(errorMessage);
    printf("\n\n");
    strcpy(errorMessage, "");
  }
}

void printMeldCard(playerControl *player) {
  int i, j;
  for (i=0;i<player->meldLength;i++) {
    switch(player->meldCard[i]) {
      case 1 ... 26:
        printf(BACK_WHT FORE_RED "%s    " RESET " ",getCardNumber(getCardValue(player->meldCard[i])));
        break;
      case 27 ... 52:
        printf(BACK_WHT FORE_BLC "%s    " RESET " ",getCardNumber(getCardValue(player->meldCard[i])));
        break;
      case 53 ... 54:
        printf(BACK_WHT FORE_YEL "%c     " RESET " ", getCardSymbol(player->meldCard[i]));
        break;
    }
  }
  printf("\n");
  for(j=0;j<3;j++){
    for (i=0;i<player->meldLength;i++) {
      printf(BACK_WHT "      " RESET " ");
    }
    printf("\n");
  }
  for (i=0;i<player->meldLength;i++) {
    switch(player->meldCard[i]) {
      case 1 ... 26:
        printf(BACK_WHT FORE_RED "     %c" RESET " ", getCardSymbol(player->meldCard[i]));
        break;
      case 27 ... 52:
        printf(BACK_WHT FORE_BLC "     %c" RESET " ", getCardSymbol(player->meldCard[i]));
        break;
      case 53 ... 54:
        printf(BACK_WHT FORE_YEL "     %c" RESET " ", getCardSymbol(player->meldCard[i]));
        break;
    }
  }
  printf("\n");
}

void printTrashCard() {
  if (trashLengthNow!=0) {
    int i;
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
    }
    printf("\n");
    for(i=0;i<3;i++){
      printf(BACK_WHT "      " RESET " ");
      printf("\n");
    }
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
    }
    printf("\n");
  }
  else {
    printf("\n\n\n\n\n");
  }
}
void HowToPlay()
{
  char back_main;

  printf("How To Play\n"

    "- Setiap pemain akan mendapatkan 7 kartu \n"
    "- Terdapat 1 buah deck kartu yang bisa diambil pemain \n\n"

    "- Pemain pertama mulai mengambil kartu di deck, memilih kartu yang tidak dikehendaki dari tangan untuk dibuang.\n"
    "- Dilanjutkan dengan pemain berikutnya\n"
    "- Ingat selalu! setelah ambil kartu dimana saja, harus buang satu kartu\n"
    "- Kita boleh memilih dalam satu giliran mau ambil kartu di deck atau ambil kartu di tempat buangan.\n"
    "- Syarat untuk ngambil kartu di buangan adalah harus langsung jadi(minimal di tangan punya 2 kartu). Maksimal pengambilan 7 kartu dari ujung awal. Misal : kita punya 3 dan 5 hati, ternyata di pembuangan ada kartu 4, dan masih dalam batas 7 kartu. Kita boleh ambil dan tetap buang satu kartu"
    "- Oh iya. Yang jadi pertama kali tiap pemain harus seri, bukan sama, dan belum boleh pakai joker. Kecuali as, karena tak punya seri.\n");

    printf("\nBack To Main menu? (Y/T) ");
    fflush(stdin);
    back_main = getchar();

    if (back_main == 'y' || back_main == 'Y')
    {
      WelcomeScreen();
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

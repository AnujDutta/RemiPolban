void update() {
  int i, choose, player;

  system("cls");
  if (now.playerNumber == 1)
  {
    playerCommand(&player1);
  }
  else if (now.playerNumber == 2)
  {
    playerCommand(&player2);
    now.playerNumber = 1;
  }
}

void playerCommand(playerControl *player){
    char command[100];

    printf("Player %d Score : %d\n",now.playerNumber, player->score);
    printf("Jumlah Kartu di Deck : %d\n",deckLengthNow);

    printf("Trash Cards : \n");
    printTrashCard();

    printf("\nPlayer %d Meld Card : \n", now.playerNumber);
    printMeldCard(player);

    printf("\nPlayer %d Card : \n", now.playerNumber);
    printPlayerCard(player);
    printErrorMessage();

    if (debugMode) {
      printf("\nChoose Command : ");
      scanf("%s", &command);
      commands(player, command);
    }
    else {
      option1(player);
    }

    if (now.playerNumber==1 && strcmp(errorMessage,"")==0) {
      now.playerNumber = 2;
    }
    else if (now.playerNumber==1 && strcmp(errorMessage,"")==0) {
      now.playerNumber = 1;
    }

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

// void option2(playerControl *player)

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
  int i;
  for (i=0;i<player->cardLength;i++) {
    printf("%d%c ",getCardValue(player->card[i]), getCardSymbol(player->card[i]));
  }
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
  int i;
  for (i=0;i<player->meldLength;i++) {
    printf("%d%c ",getCardValue(player->meldCard[i]), getCardSymbol(player->meldCard[i]));
  }
}

void printTrashCard() {
  if (trashLengthNow!=0) {
    printf("%d%c ",getCardValue(trashDeck[0]), getCardSymbol(trashDeck[0]));
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

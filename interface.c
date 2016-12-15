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

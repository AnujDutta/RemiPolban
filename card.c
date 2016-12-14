void resetDeck(int card[]) { //Reset deck
  int i;
  for (i=0;i<DECK_CARD_LENGTH;i++) {
    card[i]=i+1;
  }
}

int getCardValue(int n) { //Return the card number
  return n % 13;
}

int getCardSymbol(int n) { //Return the card symbol
  switch(n) {
    case 1 ... 13 : return 1; break; //Diamond
    case 14 ... 26 : return 2; break; //Club
    case 27 ... 39 : return 3; break; //Heart
    case 40 ... 52 : return 4; break; //Spade
    case 53 ... 54 : return 5; break; //Joker
  }
}

int getDeckLength(int card[]) { //Return the length of the deck
  int i=0;
  while(card[i]!=0 && i< PLAYER_CARD_LENGTH) {
    i++;
  }
  return i;
}

void emptyPlayerDeck(int card[]) { //Empty the player deck
  int i;
  for (i=0;i<PLAYER_CARD_LENGTH;i++) {
    card[i]=0;
  }
}

void swapCard(int card[], int i, int j) { //Swap Card from element i to element j
  int temp;
  temp = card[i];
  card[i]=card[j];
  card[j]=temp;
}

void shuffleCard(int card[]) {//Shuffle the deck
  int i;
  srand(time(NULL));
  for (i=DECK_CARD_LENGTH-1;i>0;i--) {
    int j = rand() % (i+1);

    swapCard(card, i, j);
  }
}

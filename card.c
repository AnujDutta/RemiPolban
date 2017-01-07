void resetDeck() { //Reset deck
  int i;
  deckLengthNow=DECK_CARD_LENGTH;
  for (i=0;i<DECK_CARD_LENGTH;i++) {
    deck[i]=i+1;
  }
}

int getCardValue(int n) { //Return the card number
  return n%13;
}

char getCardSymbol(int n) { //Return the card symbol
  switch(n) {
    case 1 ... 13 : return HEART; break; //Heart
    case 14 ... 26 : return DIAMOND; break; //Diamond
    case 27 ... 39 : return CLUB; break; //Club
    case 40 ... 52 : return SPADE; break; //Spade
    case 53 ... 54 : return 'R'; break; //Joker
  }
}

char* getCardNumber(int n) {
  switch(n){
    case 0: return "K "; break;
    case 1: return "A "; break;
    case 2: return "2 "; break;
    case 3: return "3 "; break;
    case 4: return "4 "; break;
    case 5: return "5 "; break;
    case 6: return "6 "; break;
    case 7: return "7 "; break;
    case 8: return "8 "; break;
    case 9: return "9 "; break;
    case 10: return "10"; break;
    case 11: return "J "; break;
    case 12: return "Q "; break;
  }
}

void shiftLeft(int card[], int length, int x) {
  int i;
  for (i=x;i<length;i++) {
    card[i-1]=card[i];
  }
}
void emptyPlayerDeck(playerControl *player) { //Empty the player deck
  int i;
  for (i=0;i<PLAYER_CARD_LENGTH;i++) {
    player->card[i]=0;
  }
  player->cardLength = 0;
}

void swapCard(int card[], int i, int j) { //Swap Card from element i to element j
  int temp;
  temp = card[i];
  card[i]=card[j];
  card[j]=temp;
}

void shuffleDeck() {//Shuffle the deck
  int i;
  srand(time(NULL));
  for (i=DECK_CARD_LENGTH-1;i>0;i--) {
    int j = rand() % (i+1);

    swapCard(deck, i, j);
  }
}

void trashCard(playerControl *player, int n) {
  trashDeck[0]=player->card[n];
  player->card[n] = 0;
  shiftLeft(player->card, player->cardLength, n+1);
  player->cardLength--;
  trashLengthNow++;
}

void getFromTrash(playerControl *player) {
  player->card[player->cardLength]=trashDeck[0];
  trashDeck[0]=0;
  player->cardLength+=1;
  trashLengthNow--;
}

void getFromDeck(playerControl *player) {
  player->card[player->cardLength]=deck[deckLengthNow-1];
  deckLengthNow--;
  player->cardLength++;
}

void dealFromDeck(playerControl *player) {
  int i;
  for (i=0;i<PLAYER_CARD_LENGTH-1;i++) {
    getFromDeck(player);
  }
}

void sortDeckBySymbol(int card[], int cardLength) {
  int i, j, min;
  for (i=0;i<cardLength-1;i++) {
    min = i;
    for(j=i+1;j<cardLength;j++) {
      if (card[j]<card[min]) {
        min = j;
      }
    }
    if (min!=i) {
      swapCard(card, i, min);
    }
  }
}

void sortDeckByNumber(int card[], int cardLength) {
  int i, j, min;
  for (i=0;i<cardLength-1;i++) {
    min = i;
    for(j=i+1;j<cardLength;j++) {
      if (getCardValue(card[j])<getCardValue(card[min])) {
        min = j;
      }
    }
    if (min!=i) {
      swapCard(card, i, min);
    }
  }
}

void emptyMeldDeck(playerControl *player) {
  int i;
  for (i=0;i<PLAYER_CARD_LENGTH;i++) {
    player->meldCard[i]=0;
  }
  player->meldLength = 0;
}

void insertMeldCard(playerControl *player, int card) {
  player->meldCard[player->meldLength]=player->card[card];
  shiftLeft(player->card, player->cardLength, card+1);
  player->meldLength++;
  player->cardLength--;
}

void getFromMeld(playerControl *player, int i) {
  player->card[player->cardLength]=player->meldCard[i];
  player->meldCard[i]=0;
  shiftLeft(player->meldCard, player->meldLength, i+1);
  player->meldLength--;
  player->cardLength++;
}

void getCard(playerControl *player, int x) {
  player->card[player->cardLength]=x;
  player->cardLength++;
}

void deleteMeld(playerControl *player, int i) {
  player->meldCard[i]=0;
  shiftLeft(player->meldCard, player->meldLength, i+1);
  player->meldLength--;
}

void pushMeld(playerControl *player) {
  int i;
  for(i=player->meldLength;i>0;i--) {
    player->score+=getCardScore(getCardValue(player->meldCard[0]));
    deleteMeld(player, 0);
  }
}

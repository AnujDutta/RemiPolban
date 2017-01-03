#define DECK_CARD_LENGTH 54
#define PLAYER_CARD_LENGTH 8
#define TRASH_CARD_LENGTH 1
#define WIN_SCORE 1000

int deckLengthNow = 54;
int trashLengthNow = 0;
int deck[DECK_CARD_LENGTH];
int godMode = 0;
int turn=0;

typedef struct {
  char playerName[100];
  int card[PLAYER_CARD_LENGTH];
  int meldCard[PLAYER_CARD_LENGTH];
  int meldLength;
  int melded;
  int cardLength;
  int score;
}playerControl;

typedef struct{
  int turn;
  int playerNumber;
}gameControl;

playerControl player1;
playerControl player2;
int trashDeck[TRASH_CARD_LENGTH];
char errorMessage[100]="";
gameControl now;

#define DECK_CARD_LENGTH 52
#define PLAYER_CARD_LENGTH 8
#define TRASH_CARD_LENGTH 1
#define WIN_SCORE 1000

int deckLengthNow = 54;
int trashLengthNow = 0;
int deck[DECK_CARD_LENGTH];
int godMode = 0;
int debugMode = 0;
int difficulty;

typedef struct {
  char playerName[100];
  int card[PLAYER_CARD_LENGTH];
  int meldCard[PLAYER_CARD_LENGTH];
  int meldLength;
  int melded;
  int cardLength;
  int score;
  int status;
}playerControl;

typedef struct{
  int playerNumber;
  int turn;
  int difficulty;
}gameControl;

playerControl player1;
playerControl player2;
int trashDeck[TRASH_CARD_LENGTH];
char errorMessage[100]="";
char logCard[100];
char logs[100];
gameControl now;

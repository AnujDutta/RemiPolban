#define DECK_CARD_LENGTH 54
#define PLAYER_CARD_LENGTH 8
#define TRASH_CARD_LENGTH 1

int deckLengthNow = 54;
int deck[DECK_CARD_LENGTH];

typedef struct {
  int card[PLAYER_CARD_LENGTH];
  int cardLength;
  int score;
}playerControl;

playerControl player1;
playerControl player2;
int trashDeck[TRASH_CARD_LENGTH];

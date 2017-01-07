#ifndef REMI_H
#define REMI_H

//file card.c

void resetDeck();
//Mengubah jumlah kartu di deck ke asal dan mengisi kartu yang ada secara berurutan

int getCardValue(int n);
//Mengembalikan nilai angka dari sebuah kartu n

char getCardSymbol(int n);
//Mengembalikan simbol dari sebuah kartu n

char* getCardNumber(int n);
//Mengembalikan angka kartu n dalam bentuk huruf

void shiftLeft(int card[], int length, int x);
//Menggeser kartu dari array card mulai dari index x sepanjang length

void emptyPlayerDeck(playerControl *player);
//Mengosongkan kartu dari deck player

void swapCard(int card[], int i, int j);
//Menukarkan kartu dari index i ke index j

void shuffleDeck();
//Mengocok kartu dari deck

void trashCard(playerControl *player, int n);
//Membuang kartu dengan index ke n dari deck player ke dalam trash

void getFromTrash(playerControl *player);
//Mengambil kartu dari trash kedalam deck player

void getFromDeck(playerControl *player);
//Mengambil kartu teratas(index terakhir) dari deck kedalam kartu player

void dealFromDeck(playerControl *player);
//Mengambil kartu ke dalam deck player sebanyak yang telah ditentukan dalam setting PLAYER_CARD_LENGTH

void sortDeckBySymbol(int card[], int cardLength);
//Mengurutkan kartu berdasarkan simbol

void sortDeckByNumber(int card[], int cardLength);
//Mengurutkan kartu berdasarkan angka

void emptyMeldDeck(playerControl *player);
//Mengosongkan kartu yang ada di dalam meld deck player

void insertMeldCard(playerControl *player, int n);
//Memasukan kartu pada indeks ke n dari deck player kedalam meld deck

void getFromMeld(playerControl *player, int i);
//Mengambil kartu dari meld deck player pada index ke i ke dalam deck player

void getCard(playerControl *player, int x);
//Mengambil kartu dengan nilai x secara langsung kedalam deck player (untuk keperluan debug)

void deleteMeld(playerControl *player, int i);
//Menghapus kartu pada indeks ke i di meld deck player

void pushMeld(playerControl *player);
//Mengosongkan yang ada di meld deck player lalu menambah skor player sesuai dengan nilai kartu dalam deck meld player tersebut

//file interface.c
void update();

void HowToPlay();

void StartGame();

void menuDisplay(int i);

void WelcomeScreen();

void printPlayerCard(playerControl *player, int x, int y);

void printErrorMessage();

void printMeldCard(playerControl *player);

void printTrashCard();

void playerCommand(playerControl *player, playerControl *player2);

void getPlayerName();

void option1(playerControl *player);

void option2(playerControl *player);

void option3(playerControl *player);

void printClosedCard(playerControl *player, int x, int y);

void gotoxy(int x, int y);

// file ai.c
void copyPlayerCard(playerControl player, int tempBrain[]);
//Menyalin seluruh isi yang ada di deck player kedalam array tempBrain

void emptyTempBrain(int tempBrain[]);
//Mengosongkan array tempBrain

void printAICard(int tempBrain[], int length);
//Menampilkan Card dari array tempBrain sepanjang length

int searchSymbol(int tempBrain[], int length);
//Mencari kombinasi untuk mendapatkan 'Symbol' lalu mengembalikan posisi dan panjang dari kombinasi tersebut apabila ditemukan

int searchSequence(int tempBrain[], int length);
//Mencari kombinasi untuk mendapatkan 'Sequence' lalu mengembalikan posisi dan panjang dari kombinasi tersebut apabila ditemukan

void trashAI(playerControl *player);
//Memutuskan kartu mana yang akan dibuang ke trash pada AI

void startAI(playerControl *player);
//Prosedur untuk memulai perintah yang ada pada AI

// file score.c
int getCardScore(int n);

int deckScore(int card[], int length);

// file gameManager.c

void sendLog(playerControl player, char log[]);

// file command.c

void help();

void cardText(char cardText[], int card);

#endif

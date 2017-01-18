#ifndef REMI_H
#define REMI_H

//file card.c
//Nama Pembuat : Muhamad Hisyam Anshory

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

void emptyTrash();
//Mengosongkan Trash

//file interface.c
//Nama Pembuat : Fahmi Rosdiansyah dan Rizka Fajar

void update();
//Prosedur untuk mengatur proses setiap giliran saat permainan

void HowToPlay();
//Prosedur untuk menampilkan cara bermain

void StartGame();
//Prosedur untuk mengatur proses saat permainan

void menuDisplay(int i);
//Prosedur untuk menampilkan menu utama

void printPlayerCard(playerControl *player, int x, int y);
//Menampilkan deck kartu pemain di posisi (x,y)

void printErrorMessage(int x, int y);
//Menampilkan pesan error di posisi (x,y)

void printMeldCard(playerControl *player, int x, int y);
//Menampilkan deck kartu meld pemain di posisi (x,y)

void printTrashCard(int x, int y);
//Menampilkan kartu Trash di posisi (x,y)

void gameBoard(playerControl *player, playerControl *opponent);

void playerCommand(playerControl *player);

void getPlayerName();
//Jendela untuk memasukkan nama pemain

void getPlayerStatus();
//Jendela untuk memasukkan status pemain

void option1(playerControl *player, int x, int y);

void option2(playerControl *player, int x, int y);

void option3(playerControl *player, int x, int y);

void gotoxy(int x, int y);
//Memindahkan kursor ke posisi (x,y)

void printClosedCard(playerControl *player, int x, int y);
//Menampilkan kartu pemain dengan posisi tertutup di posisi (x,y)

void printClosedDeck(int x, int y);
//Menampilkan deck dengan posisi tertutup di posisi (x,y)

void printBorder(char color[], int width, int height, int x, int y);
//Menampilkan bingkai dengan warna, lebar, dan tinggi tertentu dengan posisi (x,y) merupakan sudut kiri atas bingkai

void printPlayerName(playerControl *player, int x, int y);
//Menampilkan nama pemain di posisi (x,y)

void printPlayerScore(playerControl *player, int x, int y);
//Menampilkan skor pemain di posisi (x,y)

int chooseCard(playerControl *player, int x, int y);
//Memilih kartu dari deck kartu pemain

int chooseMeld(playerControl *player, int x, int y);
//Memilih kartu dari deck meld pemain

int chooseOption(int num ,int x, int y);
//Memilih menu dengan jumlah pilihan num yang terletak di (x,y)

// file ai.c
//Nama Pembuat : Muhamad Hisyam Anshory

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
//Nama Pembuat : Fahmi Rosdiansyah

int getCardScore(int n);
//Untuk mendapatkan score dari tiap kartu

// file gameManager.c
//Nama Pembuat : Achmad Fadhitia

void gameInit();
//Prosedur yang akan memanggil modul lain saat awal permainan

void roundInit();
//Prosedur yang akan memanggil modul lain saat awal ronde

void setPlayerScore(playerControl *player, int x);
//Prosedur untuk mengisi nilai score pemain sebesear x

void setPlayerName(playerControl *player, char name[]);
//Prosedur untuk mengisi nama pemain

int groupCheck(int card[], int length);
//Fungsi untuk mengecek apakah kartu yang ada di dalam deck memenuhi syarat "Group", akan mengembalikan nilai 0 jika false
//dan akan mengembalikan nilai 1 jika ditemukan

int sequenceCheck(int card[], int length);
//Fungsi untuk mengecek apakah kartu yang ada di dalam deck memenuhi syarat "Sequence", akan mengembalikan nilai 0 jika false
//dan akan mengembalikan nilai 1 jika ditemukan

void changeTurn();
//Prosedur untuk mengubah giliran pemain dalam permainan

void cardText(char cardText[], int card);
//Untuk mendapatkan symbol dari kartu yang akan dikirimkan ke log

void sendLog(playerControl player, char log[]);
//Prosedur untuk mengitimkan catatan permainan kedalam file log.dat

// file command.c
//Nama Pembuat : Achmad Fadhitia

void commands(playerControl *player, char command[]);
//Memanggil modul sesuai dengna perintah yang dipanggil, digunakan saat debug mode

void help();
//Menampilkan cara menggunakan debug mode

void cardText(char cardText[], int card);
//Prosedur untuk

#endif

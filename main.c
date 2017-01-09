#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "config/setting.c"
#include "config/characterSpecial.c"
#include "remi.h"
#include "card.c"
#include "gameManager.c"
#include "command.c"
#include "interface.c"
#include "ai.c"
#include "score.c"


int main() {
  // _setcursortype(_NOCURSOR);
  int i=1;
  char k;
  system("mode 120,35");
  do{
    menuDisplay(i);
    k=getch();
    if(k==80){
      i++;
    }
    else if(k==72){
      i--;
    }
  } while(k!=13);

  if((i+2)%3==0) {
    system("cls");
    StartGame();
  }
  else if((i+1)%3==0) {
    system("cls");
    HowToPlay();
  }
  else {
    if(i%3==0){
      fflush(stdin);
      system("exit");
    }
  }
  return 0;
}

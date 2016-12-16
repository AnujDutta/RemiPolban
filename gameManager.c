void gameInit() {
  resetDeck();
  shuffleDeck();

  emptyPlayerDeck(&player1);
  emptyMeldDeck(&player1);
  dealFromDeck(&player1);

  emptyPlayerDeck(&player2);
  emptyMeldDeck(&player2);
  dealFromDeck(&player2);
}


// int sequenceCheck(playerControl *player) {
//   int i=0;
//   int j=0;
//   player->meldCard[j]=player->card[i];
//   player->meldLength++;
//   while(player->card[i+1]-player->card[i]==0 && getCardSymbol(player->card[i+1]) == getCardSymbol(player->card[i])) {
//     j++;
//     player->meldCard[j]=player->card[i+1];
//     player->meldLength++;
//     i++;
//   }
//   if (meldLength>=3) {
//     printf("Bisa");
//   }
//   else {}
// }

int score (playerControl *player)
{
  int total=0;
  int a;

  for (a = 0; a < player->meldLength; a++)
  {
    switch (getCardValue(player->meldCard[a]))
    {
      case 2 ... 10:
      total=total+5;
      break;

      case 11 ... 12:
      total = total + 10;
      break;

      case 0:
      total = total + 10;
      break;

      case 1:
      total = total + 15;
      break;
    }
  }
  return total;
}

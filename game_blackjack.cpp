
#include "game_blackjack.h"


void Card::Flip() {
  if(position) position = false;
  else position = true;
}
int Card::GetValue() const {
  switch (value) {
  case TWO: return 2;
  case THREE: return 3;
  case FOUR: return 4;
  case FIVE: return 5;
  case SIX: return 6;
  case SEVEN: return 7;
  case EIGHT: return 8;
  case NINE: return 9;
  case TEN:
  case JACK:
  case LADY:
  case KING: return 10;
  case ACE: return 1;
  }
  return 0;
}

int Hand::GetValue() const {
  int sum = 0;
  for(const Card* c: cards)
  {
    if(c->GetValueCard() == ACE)
      sum += 11;
    else
      sum += c->GetValue();
  }
  for(const Card* c: cards)
    if(c->GetValueCard() == ACE)
      sum -= 10;
  return sum;
}

void Hand::Clear()
{
  for(Card* pCard: cards)
  {
    delete pCard;
  }
  cards.clear();
}

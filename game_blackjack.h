#ifndef GAME_BLACKJACK_H
#define GAME_BLACKJACK_H

#include <QCoreApplication>

using namespace std;

enum Suit
{
  HEARTS,
  CLUBS,
  DIAMONDS,
  SPADES,
};

enum ValueCard
{
  TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
  JACK,LADY,KING,ACE,
};

class Card
{
private:
  Suit suit;
  ValueCard value;
  bool position;
public:
  Card(Suit aSuit = HEARTS,ValueCard aValue = SIX, bool aPosition = false)
    :suit(aSuit),value(aValue),position(aPosition){}
  ~Card(){}
  void Flip();
  int GetValue() const;
  ValueCard GetValueCard() const {return value;}
};

class Hand
{
private:
  vector<Card*> cards;
public:
  Hand(){}
  ~Hand(){Clear();}

  void Add(Card *card){cards.push_back(card);}
  void Clear();
  int GetValue() const;
};


#endif // GAME_BLACKJACK_H

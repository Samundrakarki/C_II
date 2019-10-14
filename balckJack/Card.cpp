

#include "Card.h"

//definitions
Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}


  int Card::GetValue() const{
    int value;

    
    if(m_IsFaceUp == false){
      value = 0;
    }else
    {
      
        value = m_Rank;
      
    }

    return value;
  }

  void Card::Flip()
  {
    m_IsFaceUp = !(m_IsFaceUp);
  }

  std::ostream& operator<<(std::ostream& os, const Card& aCard)
  {
    const std::string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
    "10", "J", "Q", "K"};
    const std::string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.m_IsFaceUp)
    {
      os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
      os << "XX";
    }

    return os;
  }

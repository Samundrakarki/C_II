

#include "Hand.h"

Hand::Hand(){
  m_Cards.reserve(7);
}

Hand::~Hand(){
  Clear();
}

void Hand::Add(Card* pCard){
  m_Cards.push_back(pCard);
}

void Hand::Clear(){
  //iterate through vector, freeing all memory on the heap
  std::vector<Card*>::iterator iter = m_Cards.begin();
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
    delete *iter;
    *iter = 0;
  }
  //clear vector of pointers
  m_Cards.clear();
}


int Hand::GetTotal() const{
  int total = 0;
  int ace_found = 0;
  std::vector<Card*>::const_iterator iter = m_Cards.begin();
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
    total+= (*iter)->GetValue();
    if((*iter)->GetValue() == 1)
    {
      ace_found++;
      total+= 10;     //Adding aces as 11 points
    }
  }
  if(total > 21){
    while(ace_found != 0 )
    {
      total -= 10;
      ace_found--;
      if(total < 21)  //To get as close to 21 as possible
      break;
    }
  }
  return total;
}

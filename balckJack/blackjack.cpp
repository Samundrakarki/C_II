/*
CH08-320143
problem_5.6
Ayush Kumar Chaudhary
ay.chaudhary@jjacobs-university.de
*/


#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"
#include "Game.h"

int main(){
  std::cout << "\t\tWelcome to Blackjack!\n\n";

  int numPlayers = 0;
  while (numPlayers < 1 || numPlayers > 7){
    std::cout << "How many players? (1 - 7): ";
    std::cin >> numPlayers;
  }

  std::vector<std::string> names;
  std::string name;
  for (int i = 0; i < numPlayers; ++i){
    std::cout << "Enter player name: ";
    std::cin >> name;
    names.push_back(name);
  }
  std::cout << std::endl;

  //the game loop
  Game aGame(names);
  char again = 'y';
  while (again != 'n' && again != 'N'){
    aGame.Play();
    std::cout << "\nDo you want to play again? (Y/N): ";
    std::cin >> again;
  }

  return 0;
}

#include "CommandDiscard.h"
#include "state/PlayerManager.h"
#include <iostream>

using namespace state;
using namespace engine;

CommandDiscard::CommandDiscard (int entityID, int cardID): entityID(entityID), cardID(cardID){}

CommandDiscard::CommandDiscard (){}

void CommandDiscard::Execute (std::shared_ptr<state::GameState>& gameState){
  int floorNb = gameState->GetMap()->GetCurrentFloor();
  Room* room = gameState->GetMap()->GetFloors()[floorNb]->GetCurrentRoom().get();

  std::vector<DeckParts*> hands = room->GetHands();
  std::vector<DeckParts*> discardPiles = room->GetDiscardPiles();

  std::vector<Card*> handCards = hands[entityID]->GetCards();
  std::vector<Card*> discardPileCards = discardPiles[entityID]->GetCards();

  discardPileCards.push_back(handCards[cardID]);
  handCards.erase(handCards.begin() + cardID);

  hands[entityID]->SetCards(handCards);
  discardPiles[entityID]->SetCards(discardPileCards);

  room->SetHands(hands);
  room->SetDiscardPiles(discardPiles);
}

void CommandDiscard::Undo (std::shared_ptr<state::GameState>& gameState){
  int floorNb = gameState->GetMap()->GetCurrentFloor();
  Room* room = gameState->GetMap()->GetFloors()[floorNb]->GetCurrentRoom().get();

  std::vector<DeckParts*> hands = room->GetHands();
  std::vector<DeckParts*> discardPiles = room->GetDiscardPiles();

  std::vector<Card*> handCards = hands[entityID]->GetCards();
  std::vector<Card*> discardPileCards = discardPiles[entityID]->GetCards();

  handCards.push_back(discardPileCards.back());
  discardPileCards.pop_back();

  hands[entityID]->SetCards(handCards);
  discardPiles[entityID]->SetCards(discardPileCards);

  room->SetHands(hands);
  room->SetDiscardPiles(discardPiles);
}
// Generated by dia2code
#ifndef STATE__DECKPARTS__H
#define STATE__DECKPARTS__H

#include <vector>
#include <memory>

namespace state {
  class Card;
}

#include "Card.h"

namespace state {

  /// class DeckParts - 
  class DeckParts {
    // Associations
    // Attributes
  private:
    std::vector<std::shared_ptr<Card>> cards;
    int playerId;
    bool isHand;
    bool isDiscardPile;
    bool isDrawPile;
    int size;
    // Operations
  public:
    DeckParts ();
    int GetPlayerId ();
    bool GetIsDiscardPile ();
    bool GetIsDrawPile ();
    bool GetIsHand ();
    std::vector<std::shared_ptr<Card>> GetCards ();
    void SetCards (std::vector<std::shared_ptr<Card>> );
    int GetSize ();
    void SetSize (int );
    // Setters and Getters
  };

};

#endif

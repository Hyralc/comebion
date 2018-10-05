// Generated by dia2code
#ifndef STATE__DECK__H
#define STATE__DECK__H

#include <vector>
#include <memory>

namespace state {
  class Card;
}

#include "Card.h"

namespace state {

  /// class Deck - 
  class Deck {
    // Associations
    // Attributes
  private:
    std::vector<std::shared_ptr<Card>> cards;
    int size;
    int sizeMax     = 15;
    // Operations
  public:
    Deck ();
    std::vector<std::shared_ptr<Card>> GetCards ();
    void SetCards (std::vector<std::shared_ptr<Card>> );
    int GetSize ();
    void SetSize (int );
    int GetSizeMax ();
    // Setters and Getters
  };

};

#endif

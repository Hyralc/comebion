// Generated by dia2code
#ifndef STATE__CARD__H
#define STATE__CARD__H

#include <string>
#include <vector>
#include <memory>

namespace state {
  class Buff;
  class Debuff;
}

#include "Buff.h"
#include "Debuff.h"

namespace state {

  /// class Card - 
  class Card {
    // Associations
    // Attributes
  public:
    /// nom de la carte. Les cartes portant le même nom ont le même effet
    std::string name;
    /// Coût de la carte en energie
    int cost;
    /// Type de cible visée (0: joueur, 1: monstre, 2: tous les monstres, 3: tous les joueurs)		
    int target;
    /// Image représentant la carte
    std::string image;
    /// Element de la carte (air, eau, terre, feu, pas d'element)
    std::string element;
    /// Dégats de la carte
    int attack;
    /// Nombre de block créé par la carte (à destination du joueur)
    int block;
    /// Nombre de cartes pichées
    int draw;
    /// Nombre de cartes défaussées
    int discard;
    /// nombre de point de vie du joueur soignés
    int heal;
    /// liste de débuffs appliqués
    std::vector<std::shared_ptr<Debuff>> debuffs;
    /// liste de buffs appliqués
    std::vector<std::shared_ptr<Buff>> buffs;
    // Operations
  public:
    Card ();
    Card (std::string type, std::string element);
    int GetCost ();
    void SetCost (int );
    int GetTarget ();
    std::string GetImage ();
    std::string GetElement ();
    int GetAttack ();
    int GetBlock ();
    int GetDraw ();
    int GetDiscard ();
    int GetHeal ();
    std::vector<std::shared_ptr<Debuff>> GetDebuffs ();
    std::vector<std::shared_ptr<Buff>> GetBuffs ();
    // Setters and Getters
  };

};

#endif

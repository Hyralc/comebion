// Generated by dia2code
#ifndef STATE__ENTITY__H
#define STATE__ENTITY__H

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

  /// class Entity - 
  class Entity {
    // Associations
    // Attributes
  public:
    int block;
    bool isEntityAlive;
  private:
    std::string name;
    int life;
    /// Id pour la mémoire
    int id;
    std::string element;
    std::string image;
    /// la stat d'attaque s'ajoute à la valeur d'attaque d'une carte/skill jouée/réalisé
    int statAttack;
    /// la stat de block s'ajoute à la valeur de block de la carte/skill jouée/réalisé
    int statBlock;
    std::vector<std::shared_ptr<Buff>> buffs;
    std::vector<std::shared_ptr<Debuff>> debuffs;
    bool isPlayer;
    bool isEnnemy;
    // Operations
  public:
    Entity ();
    int GetLife ();
    void SetLife (int );
    int GetId ();
    void SetId (int );
    std::string GetElement ();
    void SetElement (std::string );
    std::string GetImage ();
    void SetImage (std::string );
    int GetStatAttack ();
    void SetStatAttack (int );
    int GetStatBlock ();
    void SetStatBlock (int );
    std::vector<std::shared_ptr<Buff>> GetBuffs ();
    void SetBuffs (std::vector<std::shared_ptr<Buff>> );
    std::vector<std::shared_ptr<Debuff>> GetDebuffs ();
    void SetDebuffs (std::vector<std::shared_ptr<Debuff>> );
    bool GetIsPlayer ();
    void SetIsPlayer (bool );
    bool GetIsEnemy ();
    void SetIsEnemy (bool );
    int GetBlock ();
    void SetBlock (int );
    // Setters and Getters
  };

};

#endif
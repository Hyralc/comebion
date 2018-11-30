#include "SkillManager.h"
#include <iostream>
#include <memory>

using namespace state;

SkillManager* SkillManager::inst;

SkillManager::SkillManager (){
  //buff: blockplus, attackplus, heal, evade, retaliate
  //debuff: blockminus, attackminus
  //int attack, int heal, int block, std::unique_ptr<Buff> buff, std::unique_ptr<Debuff> debuff, std::string intentimage, int cooldown, int target
  skills.push_back(std::move(std::make_unique<EnemySkill>(10, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/attack.png", 1, 0)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(5, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 3), "res/textures/icons/attack_debuff.png", 0, 0)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 0, std::make_unique<Buff>(0, 0, 0, 1, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/block_up.png", 1, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(5, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(3, 0), "res/textures/icons/attack_debuff.png", 0, 0)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 10, std::make_unique<Buff>(0, 0, 6, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/heal_block.png", 2, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 5, std::make_unique<Buff>(3, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/block_up.png", 0, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 10, std::make_unique<Buff>(0,3, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/block.png", 1, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 10, std::make_unique<Buff>(0, 0, 0, 0, 4), std::make_unique<Debuff>(0, 0), "res/textures/icons/retaliate.png", 2, 0)));
  // boss skills
  //air: (8)
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 0, std::make_unique<Buff>(0, 0, 0, 2, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/evade.png", 2, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(7, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 3), "res/textures/icons/attack_debuff.png", 0, 0)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(15, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/attack.png", 1, 0)));
// water: (11)
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 20, 20, std::make_unique<Buff>(0, 0, 0, 5, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/heal_block.png", 2, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(10, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/attack.png", 0, 0)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(7, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(3, 0), "res/textures/icons/attack_debuff.png", 1, 0)));
  //earth: (14)
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 30, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/block.png", 1, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 10, std::make_unique<Buff>(3, 3, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/block_up.png", 2, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(15, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/attack.png", 0, 0)));
  //fire 1: (17)
  skills.push_back(std::move(std::make_unique<EnemySkill>(7, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(3, 0), "res/textures/icons/attack_debuff.png", 1, 0)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(7, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 3), "res/textures/icons/attack_down.png", 1, 0)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(15, 0, 0, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/attack.png", 0, 0)));
  //fire 2: (20)
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 10, std::make_unique<Buff>(0, 0, 0, 0, 4), std::make_unique<Debuff>(0, 0), "res/textures/icons/retaliate.png", 1, 1)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 10, std::make_unique<Buff>(3, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/attack.png", 2, 3)));
  skills.push_back(std::move(std::make_unique<EnemySkill>(0, 0, 15, std::make_unique<Buff>(0, 0, 0, 0, 0), std::make_unique<Debuff>(0, 0), "res/textures/icons/attack.png", 0, 1)));

}

SkillManager* SkillManager::instance (){
  if (!inst){
    inst = new SkillManager();
  }
  return inst;
}

EnemySkill* SkillManager::operator[] (int i){
  return skills[i].get();
}

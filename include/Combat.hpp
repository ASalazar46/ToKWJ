#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <iostream>
#include <cassert>      // for assert()
#include <utility>      // for std::move()
#include <cstdlib>	// for std::rand(), std::srand()
#include <ctime>	// for std::time() 
#include <string>
#include <sstream>
#include <vector>
#include "Characters.hpp"

// this function returns a 0 if the enemy dies and a 1 if the hero dies.
int combat(Unit& hero, Unit& enemy); 

//the rest of these functions are just attacks.
//combat.cpp uses them, but you shouldnt need to use them.
unsigned deadly_strike(Unit& hero, Unit& enemy);
unsigned quick_strike(Unit& hero, Unit& enemy);
unsigned fire_ball(Unit& hero, Unit& enemy);
unsigned force_lightning(Unit& hero, Unit& enemy);
unsigned saber_slash(Unit& hero, Unit& enemy);
unsigned enemy_attack(Unit& hero, Unit& enemy);
unsigned kraken_attacks(Unit& hero, Unit& enemy);
unsigned pincer_attack(Unit& hero, Unit& enemy);
unsigned poison_tenticle(Unit& hero, Unit& enemy);
unsigned occultist_attacks(Unit& hero, Unit& enemy);
unsigned life_siphon(Unit& hero, Unit& enemy);
unsigned brutal_swing(Unit& hero, Unit& enemy);
unsigned fire_breath(Unit& hero, Unit& enemy);
unsigned tail_swipe(Unit& hero, Unit& enemy);


#endif //COMBAT_HPP

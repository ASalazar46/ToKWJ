#include "Combat.hpp"

unsigned deadly_strike(Unit& hero, Unit& enemy) {

	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << "Deadly Strike missed!" << std::endl;
		return 0;
	}
	//we want to give our normal attack some varriance.
	int y = std::rand() % 5;
	int z = std::rand() % 3;
	int dmg = (5 + y + hero.get_strength()) - (z + enemy.get_defense());
	if (dmg < 0) {
		dmg = 0;
	}
	//if x >= 75 the attack will crit for double damage.
	if (x >= 75 && dmg > 0) {
		dmg = dmg * 2;
		std::cout << "Deadly Strike Crit for " << dmg << " damage!!" << std::endl;
	}
	else {
		std::cout << "Deadly Strike hit for " << dmg << " damage." << std::endl;
	}
	//modify the HP values 
	enemy.set_HP(enemy.get_HP() - dmg); //HP can be a negative value.
	if (enemy.get_HP() > 0) {
		std::cout << enemy.get_name() << " has " << enemy.get_HP() << " HP remaining." << std::endl;
	}
	else {
		std::cout << enemy.get_name() << " has 0 HP remaining." << std::endl;
	}
	return 0;
}

unsigned quick_strike(Unit& hero, Unit& enemy) {

	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << "Quick Strike missed!" << std::endl;
		return 0;
	}
	//we want to give our attacks some varriance.
	int y = std::rand() % 5;
	int z = std::rand() % 3;
	int dmg = (y + (hero.get_strength() * .67)) - (z + enemy.get_defense());
	if (dmg < 0) {
		dmg = 0;
	}
	//if x >= 75 the attack will crit for double damage.
	if (x >= 75 && dmg > 0) {
		dmg = dmg * 2;
		std::cout << "Quick Strike Crit for " << dmg << " damage!!" << std::endl;
	}
	else {
		std::cout << "Quick Strike hit for " << dmg << " damage." << std::endl;
	}
	//modify the HP values 
	enemy.set_HP(enemy.get_HP() - dmg); //HP can be a negative value.
	if (enemy.get_HP() > 0) {
		std::cout << enemy.get_name() << " has " << enemy.get_HP() << " HP remaining." << std::endl;
	}
	else {
		std::cout << enemy.get_name() << " has 0 HP remaining." << std::endl;
	}
	return 0;
}

unsigned fire_ball(Unit& hero, Unit& enemy) {
	
	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << "Fire Ball missed!" << std::endl;
		return 0;
	}
	//we want to give our attacks some varriance.
	int y = std::rand() % 5;
	int z = std::rand() % 3;
	int dmg = (y + (hero.get_wisdom() * 1.34)) - (z + enemy.get_defense());
	if (dmg < 0) {
		dmg = 0;
	}
	//if x >= 75 the attack will crit for double damage.
	if (x >= 65 && dmg > 0) {
		dmg = dmg * 2;
		std::cout << "Fire Ball Crit for " << dmg << " damage!!" << std::endl;
	}
	else {
		std::cout << "Fire ball hit for " << dmg << " damage." << std::endl;
	}
	//modify the HP values 
	enemy.set_HP(enemy.get_HP() - dmg); //HP can be a negative value.
	if (enemy.get_HP() > 0) {
		std::cout << enemy.get_name() << " has " << enemy.get_HP() << " HP remaining." << std::endl;
	}
	else {
		std::cout << enemy.get_name() << " has 0 HP remaining." << std::endl;
	}
	return 0;
}

unsigned force_lightning(Unit& hero, Unit& enemy) {
	
	int a = 2 + std::rand() % 5;
	int b = a;
	for (a; a > 0; a--) {
		int x = 1 + std::rand() % 100;
		//see if we hit or miss 5% chance to miss
		if (x <= 5) {
			std::cout << "Force ligntning missed!" << std::endl;
			return 0;
		}		
		//we want to give our attacks some varriance.
		int y = std::rand() % 5;
		int z = std::rand() % 3;
		int dmg = (y + (hero.get_wisdom() * .6)) - (z + enemy.get_defense());
		if (dmg < 0) {
			dmg = 0;
		}
		//if x >= 75 the attack will crit for double damage.
		if (x >= 75 && dmg > 0) {
			dmg = dmg * 2;
			std::cout << "Force lightning Crit for " << dmg << " damage!!" << std::endl;
		}
		else {
			std::cout << "Force lightning hit for " << dmg << " damage." << std::endl;
		}
		//modify the HP values 
		enemy.set_HP(enemy.get_HP() - dmg); //HP can be a negative value.
	}
	std::cout << "Force lightning hit " << b << " times." << std::endl;
	if (enemy.get_HP() > 0) {
		std::cout << enemy.get_name() << " has " << enemy.get_HP() << " HP remaining." << std::endl;
	}
	else {
		std::cout << enemy.get_name() << " has 0 HP remaining." << std::endl;
	}
}

unsigned saber_slash(Unit& hero, Unit& enemy) {

	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << "Saber Slash missed!" << std::endl;
		return 0;
	}
	//we want to give our attacks some varriance.
	int y = std::rand() % 5;
	int z = std::rand() % 3;
	int dmg = (y + (hero.get_strength() * 3)) - (z + enemy.get_defense());
	if (dmg < 0) {
		dmg = 0;
	}
	if (x >= 65 && dmg > 0) {
		dmg = dmg * 2;
		std::cout << "Saber Slash Crit for " << dmg << " damage!!" << std::endl;
	}
	else {
		std::cout << "Saber Slash hit for " << dmg << " damage." << std::endl;
	}
	//modify the HP values 
	enemy.set_HP(enemy.get_HP() - dmg); //HP can be a negative value.
	if (enemy.get_HP() > 0) {
		std::cout << enemy.get_name() << " has " << enemy.get_HP() << " HP remaining." << std::endl;
	}
	else {
		std::cout << enemy.get_name() << " has 0 HP remaining." << std::endl;
	}
	return 0;
}



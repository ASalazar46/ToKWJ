#include "Combat.hpp"

unsigned enemy_attack(Unit& hero, Unit& enemy) {
	int x = 1 + std::rand() % 100;
	if (enemy.find_item("Heavy_Stone")) { //check if enemy is a Bolder
		std::cout << "The Bolder is just sitting there doing nothing." << std::endl;
		return 0;
	}
	if (enemy.find_item("Ancient_Tome")) { //check if enemy is Occultist Curly
		occultist_attacks(hero, enemy);
		return 0;		
	}
	if (enemy.find_item("Slimy_Tenticle")) { // check if enemy is a Kraken
		kraken_attacks(hero, enemy);
		return 0;
	}
	if (enemy.find_item("Dragon_Claw")) { // check if enemy is a dragon and if it will preform a Fire Breath
		if (x >= 70) {
			fire_breath(hero, enemy);
			return 0;
		}
		if (x >= 35) {
			if (tail_swipe(hero, enemy) == 1) { //function returns 1 on a miss, block(knight) or deflect(jedi)
				return 0;
			}
			if (hero.get_HP() < 0){
				return 0;
			}
			std::cout << enemy.get_name() << "'s Tail swipe temporarily disoriented you!" << std::endl;
		}
	}
	brutal_swing(hero, enemy);
	return 0;
}

unsigned kraken_attacks(Unit& hero, Unit& enemy) {
	if (enemy.find_item("poisoned")) {
		std::cout << hero.get_name() << " suffered 7 poison damage." << std::endl;
		hero.set_HP(hero.get_HP() - 7);
	}	
	int x = 1 + std::rand() % 100;
	if (x < 50) {
		pincer_attack(hero, enemy);
		pincer_attack(hero, enemy); //easiest way to make it hit 2 times =)
		return 0;
	}
	else {
		poison_tenticle(hero, enemy);
	}
}

unsigned pincer_attack(Unit& hero, Unit& enemy) {
	int dmg = 0;
	int y = 0;
	int z = 0;
	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << enemy.get_name() << "'s attack missed!" << std::endl;
		return 0;
	}
	if (hero.find_item("Awsome_Sword") && x <= 25) {
		std::cout << "You blocked the " << enemy.get_name() << "'s attack!" << std::endl;
		return 0;
	}
	if (hero.find_item("Light_Saber") && x <= 45) {
		std::cout << "You dodged the " << enemy.get_name() << "'s attack with your Jedi reflexes!" << std::endl;
		return 0;
	}
	y = std::rand() % 5;
	z = std::rand() % 3;
	dmg = (y + enemy.get_strength()) - (z + hero.get_defense());
	if (dmg < 0) {
		dmg = 0; 
	}
	if (x >= 75 && dmg > 0) {
		dmg = dmg * 2;
		std::cout << enemy.get_name() << "'s Tenticle Pincer Attack Crit you for " 
			  << dmg << " damage!!" << std::endl;
	}
	else {
		std::cout << enemy.get_name() <<"'s Tenticle Pincer Attack hit you for " << dmg << " damage." << std::endl;
	}

	//modify the HP values 
	hero.set_HP(hero.get_HP() - dmg); //HP can be a negative value.
	return 0;

}

unsigned poison_tenticle(Unit& hero, Unit& enemy) {
	int dmg = 0;
	int y = 0;
	int z = 0;
	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << enemy.get_name() << "'s attack missed!" << std::endl;
		return 0;
	}
	if (hero.find_item("Awsome_Sword") && x <= 25) {
		std::cout << "You blocked the " << enemy.get_name() << "'s attack!" << std::endl;
		return 0;
	}
	if (hero.find_item("Light_Saber") && x <= 45) {
		std::cout << "You dodged the " << enemy.get_name() << "'s attack with your Jedi reflexes!" << std::endl;
		return 0;
	}
	y = std::rand() % 5;
	z = std::rand() % 3;
	dmg = (y + enemy.get_strength()) - (z + hero.get_defense());
	if (dmg < 0) {
		dmg = 0; 
	}
	if (x >= 80 && dmg > 0) {
		dmg = dmg * 2;
		std::cout << enemy.get_name() << "'s Poison Tenticle Crit you for " 
			  << dmg << " damage!!" << std::endl;
	}
	else {
		std::cout << enemy.get_name() <<"'s Poison Tenticle hit you for " << dmg << " damage." << std::endl;
	}
	if (enemy.find_item("poisoned")) {
		std::cout << hero.get_name() << " suffered 7 extra poison damage!" << std::endl;
		hero.set_HP(hero.get_HP() - 7);
	}
	else {
		std::cout << hero.get_name() << " became poisoned." << std::endl;
		enemy.add_item("poisoned"); // I would rather mess with the enemie's items than the hero's since the enemie's items
					    // aren't really used for anything. This item acts like a buff, instead of an item.
	} 
	hero.set_HP(hero.get_HP() - dmg); //HP can be a negative value.
	return 0;
}

unsigned occultist_attacks(Unit& hero, Unit& enemy) {
	int x = 1 + std::rand() % 100;
	int a = enemy.get_HP();
	// I decided to just use item to remeber the occultists HP at the time he starts casting Total Annihilation,
	// since item is only really used for identification purposes in combat. Items were origonaly meant for the 
	// main character only during the story portion of the game, but Occultists uses items like a temporary buff.
	if (enemy.find_item("TA_cast")) {
		if (enemy.find_item(std::to_string(a))) { //you current HP should be = to your old HP value to verify you were not attacked.
			std::cout << "Occultist's Total Annihilation fizzled out!" << std::endl;
			enemy.delete_all_items();
			enemy.add_item("Ancient_Tome");
			return 0;
		}
		else {	
			std::cout << "Total Annihilation was amplified 100 fold due to your attack!!!" << std::endl << std::endl;
			std::cout << "You scream as you body is ripped apart!!" << std::endl;
			hero.set_HP(0);
	 		enemy.delete_all_items();
			enemy.add_item("Ancient_Tome");
			return 0;
		}		
	}
	if (x >= 80) {
		std::cout << "Occultist shouts 'Fools! hit me with everything you've got!!'" << std::endl;
		std::cout << "Occultist started charging up Total Annihilation." << std::endl << std::endl;
		std::cout << "You have a very bad feeling about this," << std::endl; 
		std::cout << "maybe you shouldn't damage the Occultist this turn..." << std::endl << std::endl;
		//a = enemy.get_HP();
		enemy.add_item("TA_cast"); //we add TA_cast. it works like a temporary buff.
		enemy.add_item(std::to_string(a)); //now we are adding the occultists HP 
		return 0;
	}
	else {
		life_siphon(hero, enemy);
		return 0;
	}	

}

unsigned life_siphon(Unit& hero, Unit& enemy) {
	int dmg = 0;
	int y = 0;
	int z = 0;
	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << enemy.get_name() << "'s attack missed!" << std::endl;
		return 0;
	}
	if (hero.find_item("Awsome_Sword") && x <= 25) {
		std::cout << "You blocked the " << enemy.get_name() << "'s attack!" << std::endl;
		return 0;
	}
	if (hero.find_item("Light_Saber") && x <= 45) {
		std::cout << "You dodged the " << enemy.get_name() << "'s attack with your Jedi reflexes!" << std::endl;
		return 0;
	}
	y = std::rand() % 5;
	z = std::rand() % 3;
	dmg = (y + enemy.get_wisdom()) - (z + hero.get_defense());
	if (dmg < 0) {
		dmg = 0; 
	}
	else {
		std::cout << enemy.get_name() <<"'s Siphon Life stole " << dmg << " HP from you." << std::endl;
	}

	//modify the HP values 
	hero.set_HP(hero.get_HP() - dmg); //HP can be a negative value.
	enemy.set_HP(enemy.get_HP() + dmg);
	return 0;
}

unsigned brutal_swing(Unit& hero, Unit& enemy) {
	int dmg = 0;
	int y = 0;
	int z = 0;
	int x = 1 + std::rand() % 100;
	//see if we hit or miss 5% chance to miss
	if (x <= 5) {
		std::cout << enemy.get_name() << "'s attack missed!" << std::endl;
		return 0;
	}
	if (hero.find_item("Awsome_Sword") && x <= 25) {
		std::cout << "You blocked the " << enemy.get_name() << "'s attack!" << std::endl;
		return 0;
	}
	if (hero.find_item("Light_Saber") && x <= 45) {
		std::cout << "You dodged the " << enemy.get_name() << "'s attack with your Jedi reflexes!" << std::endl;
		return 0;
	}
	y = std::rand() % 5;
	z = std::rand() % 3;
	dmg = (y + enemy.get_strength()) - (z + hero.get_defense());
	if (dmg < 0) {
		dmg = 0; 
	}
	if (x >= 80 && dmg > 0) {
		dmg = dmg * 2;
		std::cout << enemy.get_name() << "'s Brutal Swing Crit you for " 
			  << dmg << " damage!!" << std::endl;
	}
	else {
		std::cout << enemy.get_name() <<"'s Brutal Swing hit you for " << dmg << " damage." << std::endl;
	}

	//modify the HP values 
	hero.set_HP(hero.get_HP() - dmg); //HP can be a negative value.
	return 0;
}

unsigned fire_breath(Unit& hero, Unit& enemy) {
	int dmg = 0;
	int y = 0;
	int z = 0;
	int x = 1 + std::rand() % 100;

	//see if we hit or miss 25% chance to miss for fire breath
	if (x <= 25) {
		std::cout << enemy.get_name() << "'s Fire Breath missed!" << std::endl;
		return 0;
	}
	if (hero.find_item("Awsome_Sword") && x <= 45) {
		std::cout << "You blocked the " << enemy.get_name() << "'s Fire Breath!" << std::endl;
		return 0;
	}
	if (hero.find_item("Light_Saber") && x <= 65) {
		std::cout << "You dodged the " << enemy.get_name() << "'s Fire Breath with your Jedi reflexes!" << std::endl;
		return 0;
	}
	y = std::rand() % 5;
	z = std::rand() % 3;
	dmg = (y + (enemy.get_wisdom() * 2)) - (z + hero.get_defense());
	if (dmg < 0) {
		dmg = 0; 
	}
	//fire breath cannot crit
	std::cout << enemy.get_name() <<"'s Fire Breath hit you for " << dmg << " damage!!" << std::endl;
	
	//modify the HP values 
	hero.set_HP(hero.get_HP() - dmg); //HP can be a negative value.
	return 0;
}

unsigned tail_swipe(Unit& hero, Unit& enemy) {
	int dmg = 0;
	int y = 0;
	int z = 0;
	int x = 1 + std::rand() % 100;

	//see if we hit or miss 5% chance to miss for tail swipe.
	if (x <= 5) {
		std::cout << enemy.get_name() << "'s Tail Swipe missed!" << std::endl;
		return 1;
	}
	if (hero.find_item("Awsome_Sword") && x <= 25) {
		std::cout << "You blocked the " << enemy.get_name() << "'s Tail Swipe!" << std::endl;
		return 1;
	}
	if (hero.find_item("Light_Saber") && x <= 45) {
		std::cout << "You dodged the " << enemy.get_name() << "'s Tail Swipe with your Jedi reflexes!" << std::endl;
		return 1;
	}
	y = std::rand() % 5;
	z = std::rand() % 3;
	dmg = (y + (enemy.get_strength() * .85)) - (z + hero.get_defense());
	if (dmg < 0) {
		dmg = 0; 
	}
	//tail swipe cannot crit
	std::cout << enemy.get_name() <<"'s Tail Swipe hit you for " << dmg << " damage." << std::endl;
	
	//modify the HP values 
	hero.set_HP(hero.get_HP() - dmg); //HP can be a negative value.
	return 0;
}


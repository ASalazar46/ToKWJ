#include "Combat.hpp"


int combat(Unit& hero, Unit& enemy) {
	
	std::srand(std::time(0)); //use current time as seed for random generator
	char choice = '0';
	int defense_modifier = 0;
	int qs = 1; //for quick strike 

	std::cout << "Entering combat with a " << enemy.get_name() << " ." <<std::endl;
	std::cout << "How would you like to attack?"<< std::endl;

	while(hero.get_HP() > 0 && enemy.get_HP() > 0) {
		if (hero.find_item("Awsome_Sword")) { //hero is a knight
			std::cout << "Knight's Current HP: " << hero.get_HP() << std::endl;
			std::cout << "	1) Use 'Deadly strike' (powerfull Melee hit)"<< std::endl; //standard attack
			std::cout << "	2) Use a healing potion (unlimited uses!)"<< std::endl; //heals for 30HP
			std::cout << "	3) Use 'Quick Strike'(skips one enemy turn)"<<std::endl;  // will skip one of the enemies turns
			std::cout << "	4) Do nothing "<< std::endl;
			
			std::cin >> choice;
			while (choice < '1' || choice > '4') {
				std::cout << "Invalid option" << std::endl;
				std::cin >> choice;
			}
			switch (choice) {
				case '1' : 
					deadly_strike(hero, enemy);
					break;
				case '2' : 
					if (hero.get_HP() <= 70) {
						hero.set_HP(hero.get_HP() + 30);
						std::cout << "Potion healed you for 30 HP."<< std::endl;
					}
					else {
						hero.set_HP(100);
						std::cout << "Potion healed you to max HP."<< std::endl;
					}
					break;
				case '3' :
					quick_strike(hero, enemy);
					if (qs == 1) {
						qs = 0;
						std::cout << "You moved with such speed the enemy could not retaliate." << std::endl;
						goto skip_one_turn;
					}
					break;
				case '4' :
					std::cout << "You stand there and do nothing." << std::endl;
					break;
				default :
					std::cout << "***Something went wrong***" << std::endl;
					break;
			}	
		}
		if (hero.find_item("Magic_Staff")) { //hero is a wizard
			std::cout << "Wizards's Current HP: " << hero.get_HP() << std::endl;
			std::cout << "	1) Cast 'Fire Ball'(powerfull damage spell)"<< std::endl; //standard attack
			std::cout << "	2) Cast 'Healing Grace'(heals you)"<< std::endl; //heals for 50HP
			std::cout << "	3) Cast 'Iron Skin'(greatly increases defense)"<<std::endl; // raises defense
			std::cout << "	4) Do nothing "<< std::endl;
			
			std::cin >> choice;
			while (choice < '1' || choice > '4') {
				std::cout << "Invalid option" << std::endl;
				std::cin >> choice;
			}
			switch (choice) {
				case '1' : 
					fire_ball(hero, enemy);
					break;
				case '2' : 
					if (hero.get_HP() <= 50) {
						hero.set_HP(hero.get_HP() + 50);
						std::cout << "Healing Grace healed you for 50 HP."<< std::endl;
					}
					else {
						hero.set_HP(100);
						std::cout << "Healing grace healed you to max HP."<< std::endl;
					}
					break;
				case '3' :
					if (qs == 1) {
						qs = -1;
						hero.set_defense(25);
						std::cout << "Your skin becomes tough as iron!" << std::endl;
						std::cout << "Only powerfull attacks now hurt you." << std::endl;
						break;
					}
					if (qs == -1) {
						std::cout << "'Iron Skin' had no effect." << std::endl; 
					}
					break;
				case '4' :
					std::cout << "You stand there and do nothing." << std::endl;
					break;
				default :
					std::cout << "***Something went wrong***" << std::endl;
					break;
	
			}
		}
		if (hero.find_item("Light_Saber")) { //hero is a jedi
			std::cout << "Jedi's Current HP: " << hero.get_HP() << std::endl;
			std::cout << "	1) Use 'Force Lightning'(hits multiple times)"<< std::endl;
			std::cout << "	2) Use 'Saber Slash'(powerfull melee attack)"<< std::endl;
			std::cout << "	3) Quit messing around and cut him in half. (grants evil points)"<<std::endl;
			std::cout << "	4) Do nothing "<< std::endl;
			
			std::cin >> choice;
			while (choice < '1' || choice > '4') {
				std::cout << "Invalid option" << std::endl;
				std::cin >> choice;
			}
			switch (choice) {
				case '1' : 
					force_lightning(hero, enemy);
					break;
				case '2' : 
					saber_slash(hero, enemy);
					break;
				case '3' :
					std::cout << "You give in to your hatred and viciously slice your oponent in half."<< std::endl;
					std::cout << "Feel the power of the Dark side!" << std::endl;
					enemy.set_HP(0);
					hero.set_evil_points(hero.get_evil_points() + 2);			
					break;
				case '4' :
					std::cout << "You stand there and do nothing." << std::endl;
					break;
				default :
					std::cout << "***Something went wrong***" << std::endl;
					break;
	
			}
		}
			if (enemy.get_HP() > 0) {
				enemy_attack(hero, enemy);
				if (qs ==0) {
					qs = 1;
				}
			}	
			skip_one_turn: ; // see goto in quickstrike^
		

	}//end of while loop
	if (qs == -1) {
		hero.set_defense(5);
	}
	if (enemy.get_HP() <= 0) {
		std::cout << enemy.get_name() << " has been defeated!!!" << std::endl << std::endl << std::endl;
		return 0;
	}
	if (hero.get_HP() <= 0) {
		std::cout << "You have died." << std::endl << std::endl << std::endl;
		return 1;
	}
	else {
		std::cout << "***While loop ended too soon.***" << std::endl;	
	}
	
}






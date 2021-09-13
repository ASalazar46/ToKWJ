#include "Characters.hpp"

	/*
	private:
		std::string name; 
		int goodpoints;
		int evilpoints;
		int HP;
		int defense;
		int strength;
		int wisdom;
		std::vector<std::string> pouch;
	*/
	
	//constructor
	Unit::Unit (std::string bob, int hp, int def, int str, int wis) :
		name(bob), 
		goodpoints(0),
		evilpoints(0),
		HP(hp),
		defense(def),
		strength(str),
		wisdom(wis) {}
	
	std::string Unit::get_name() const {return name; }
	int Unit::get_good_points() const { return goodpoints; }	
	int Unit::get_evil_points() const { return evilpoints; }
	int Unit::get_HP() const { return HP; }
	int Unit::get_defense() const { return defense; }
	int Unit::get_strength() const { return strength; }
	int Unit::get_wisdom() const { return wisdom; }
	std::vector<std::string> Unit::get_pouch() const { return pouch; }	

	unsigned Unit::find_item(std::string item) const { 
		for (auto it: pouch) {
			if (it == item) {
				return 1;
			}
		}
		return 0;
	}	

	void Unit::set_name(std::string bob) { name = bob; }
	void Unit::set_good_points(int pts) { goodpoints = pts; }
	void Unit::set_evil_points(int pts) { evilpoints = pts; }
	void Unit::set_HP(int hp) { HP = hp; }
	void Unit::set_defense(int def) { defense = def; }
	void Unit::set_strength(int str) { strength = str; }
	void Unit::set_wisdom(int wis) { wisdom = wis; }
	void Unit::add_item(std::string item) { pouch.push_back(item); }
	void Unit::delete_all_items() { pouch.clear(); }


// Unit (std::string hp, def, str, wis)//
//     ^^for reference^^    //

	//Knight constructor
	Knight::Knight() : Unit("Knight", 100, 20, 30, 5){
		add_item("Awsome_Sword");
		add_item("Health_Potion");
	}	

	//Wizard constructor
	Wizard::Wizard() : Unit("Wizard", 100, 5, 5, 30){
		add_item("Magic_Staff");
	}	

	//Jedi constructor
	Jedi::Jedi() : Unit("Jedi", 200, 22, 30, 30){
		add_item("Light_Saber");	
	}	

	//Villager constructor
	Villager::Villager() : Unit("Villager", 70, 7, 25, 0){
		add_item("Wooden_Stick");
	}

	//Dragon constructor
	Dragon::Dragon() : Unit("Dragon", 400, 7, 30, 30){
		add_item("Dragon_Claw");	
	}
	
	//Bolder constructor
	Bolder::Bolder() : Unit("Bolder", 200, 27, 5, 0){
		add_item("Heavy_Stone");
	}

	//Occultist constructor
	Occultist::Occultist() : Unit("Occultist Curly", 250, 7, 10, 30){
		add_item("Ancient_Tome");
	}

	//Kraken constructor
	Kraken::Kraken() : Unit("Kraken", 400, 7, 30, 30){
		add_item("Slimy_Tenticle");
	}



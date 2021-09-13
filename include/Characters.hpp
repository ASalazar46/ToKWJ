#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include <iostream>
#include <cassert>      // for assert()
#include <utility>      // for std::move()
#include <string>
#include <sstream>
#include <vector>

class Unit {
	private:
		std::string name; 
		int goodpoints;
		int evilpoints;
		int HP;
		int defense;
		int strength;
		int wisdom;
		std::vector<std::string> pouch;

	public:
	//constructor
	Unit (std::string bob, int hp, int def, int str, int wis);

	//getters
	std::string get_name() const;
	int get_good_points() const; //* 
	int get_evil_points() const; //*
	int get_HP() const;
	int get_defense() const;
	int get_strength() const;
	int get_wisdom() const;
	std::vector<std::string> get_pouch() const;	

	unsigned find_item(std::string item) const; //returns 1 if item is there and 0 if it is not.

	//setters
	void set_name(std::string bob);
	void set_good_points(int pts); //* might need to modify this depending on the combat outcome
	void set_evil_points(int pts); //*
	void set_HP(int hp);
	void set_defense(int def);
	void set_strength(int str);
	void set_wisdom(int wis);
	void add_item(std::string item);
	void delete_all_items();

};


class Knight : public Unit {
	public:
	//constructor
	Knight();	
};

class Wizard : public Unit {
	public:
	//constructor
	Wizard();	
};

class Jedi : public Unit {
	public:
	//constructor
	Jedi();	
};

class Villager : public Unit {
	public: 
	//constructor
	Villager();
};

class Dragon : public Unit {
	public:
	//constructor
	Dragon();
};

class Bolder : public Unit {
	public:
	//constructor	
	Bolder();
};

class Occultist : public Unit {
	public:
	//constructor
	Occultist();
};

class Kraken : public Unit {
	public:
	//constructor
	Kraken();
};



#endif // CHARACTERS_HPP

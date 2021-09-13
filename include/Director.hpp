#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include <iostream>
#include <string>
#include <nlohmann/json.hpp> // provides access to json assets/class
#include "Display.hpp" // accesses the Display class functions
#include "Characters.hpp" // to create the characters

using json = nlohmann::json;

// this class directs the flow of the story
class Director {
   private:
	Unit* you;
	int quest; // 1 for forest, 2 for ocean, 3 for space

   public:
	// constructor / destructor for the manager object
	Director();
	~Director();

	// get and set the player's quest choice
	void setQuest(int q) {quest = q;};
	int getQuest(void) const {return quest;};

	// continue to the next paragraph or quit to menu, 
        // depending on user input
	// if input is 1, continue. if 0, quit to menu
	int CorQ(int r);

	// directs each part of the story for display
	// takes in a json object (story files)
	// and the display object
	// and runs a specific part of the story from there
	void Prologue(json j, Display d);
	void Forest(json j, Display d);
	void Ocean(json j, Display d);
	void Space(json j, Display d);

};

#endif // DIRECTOR_HPP

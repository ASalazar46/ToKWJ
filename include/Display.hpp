#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>          // standard
#include <nlohmann/json.hpp> // used to access syntax and functions for json

using json = nlohmann::json; // for convenience

// this class handles the displaying of the story stuff
class Display {
   public:
	// constructor / destructors for a display object
	Display();
	~Display();

	// display specified parts of the story
	// takes in a json object (the story files, j), a specific scene
	// of that story file (scene), and an event in that scene (part)
	// as an added bonus the text is delayed when printing
	void print(json j, std::string scene, std::string part);

	//clear the screen
	void clearScreen(void);

};

#endif // DISPLAY_HPP



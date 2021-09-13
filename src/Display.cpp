#include <iostream>
#include <nlohmann/json.hpp> // to access syntax and function for json
#include <string> // used to clear the screen
#include <thread> // used to access the sleep_for() funciton
#include <chrono> // used to set the time for sleep_for()
#include "Display.hpp" //Declarations for functions in this file

using json = nlohmann::json; // for convenience 

// default constructors and destructors
Display::Display() {};
Display::~Display() {};

// display specified parts of the story
void Display::print(json j, std::string scene, std::string part) {
	// takes the event data and puts it into a string
	std::string p = j[scene][part];
	
	// do a loop to print each individual character
	for (char c: p) {
		// uses the sleep_for function, which delays the printing
		std::this_thread::sleep_for(std::chrono::nanoseconds(40000000));

		// print out letters individually
		std::cout << c << std::flush;
	}

	// make a new line
	std::cout << '\n';
};

//clear the screen
//two ways: 1) use system("clear") 2) use another way
void Display::clearScreen(void) {
	system("clear");
	//std::cout << std::string(50, '\n');
};



#include <iostream> //standard
#include <fstream>  //to read the .json files
#include <nlohmann/json.hpp> // to access syntax and function for json
using json = nlohmann::json; // 


//put these in a separate cpp and hpp file.
void printDialogue(json j, std::string scene, std::string part);
void printText(json j, std::string scene, std::string part);

void printDialogue(json j, std::string scene, std::string part) {
	std::cout << j[scene][part] << std::endl;
};

void printText(json j, std::string scene, std::string part) {
	std::cout << j[scene][part].get<std::string>() << std::endl;
};

int main () {
	//access (read-only) the file with all the story stuff
	//each area will probably have its own set of scenes, 
        //so one .json file per area
	std::ifstream i("../other/Test.json");
	
	//creates an empty json object here
	json j;
	
	//sets the file data to the json object
	i >> j;

	//print out the data for both test scenes
	//if I want the quotes around the result of the print outs,
	//then I would remove the '.get<std::string> part

	std::cout << j["testscene"]["name"].get<std::string>() << std::endl;
	std::cout << j["testscene"]["CBL"] << std::endl;
	std::cout << j["testscene"]["examine"].get<std::string>() << std::endl;
	
	std::cout << j["testscene2"]["name"].get<std::string>() << std::endl;
	std::cout << j["testscene2"]["CBL"] << std::endl;
	std::cout << j["testscene2"]["examine"].get<std::string>() << std::endl;
	
	//this test which parts will have quotes around them or not
	//Dialogue will have quotes
	//Other text will not	
	std::cout << j["testscene3"]["event"] << std::endl; //have quotes
	printDialogue(j, "testscene3", "event");            //no quotes
	printText(j, "testscene3", "event");                //have quotes
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//to use json, go to https://github.com/nlohmann/json and 
	//download the files, then read the README.md for more details

	//to run this, use 
	//g++ test.cpp -I json-develop/include
	//then run the a.out file
	//have the json-develop folder in the same directory as the test.cpp


#include<iostream>
#include<fstream> //read json files
#include<nlohmann/json.hpp>//access syntax and function for json
#include "Display.hpp"
#include "Director.hpp"
#include "menu.hpp"

using json = nlohmann::json;

int main(){
	char gamestart=0;
	
	while(1){
		system("clear");
		if(gamestart!=1){
			gamestart=mainmenu();
			if (gamestart==-1) {break;};
		}
		else{
			
			json j; //create json object
			Display d;  //create Display object
			Director l; //create director object
			
			std::ifstream i("../story/Prologue.json");
			i>>j;
			
			l.Prologue(j, d);
			
			if (l.getQuest()==1) {
				std::ifstream i("../story/Forest.json");
				i >> j;
				l.Forest(j, d);
			}
			if (l.getQuest()==2) {
				std::ifstream i("../story/Ocean.json");
				i >> j;
				l.Ocean(j, d);
			}
			if (l.getQuest()==3) {
				std::ifstream i("../story/Space.json");
				i >> j;
				l.Space(j, d);
			}
			gamestart=0;

		}
	}
}

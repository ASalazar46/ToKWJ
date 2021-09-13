#include<stdio.h>
#include<iostream>
#include"menu.hpp"


char mainmenu(){
	char menuoption;

	std::cout<<"A Knight, a Wizard, and a Jedi"<<std::endl;
	std::cout<<" "<<std::endl;
	std::cout<<"press 1 to start"<<std::endl;
	std::cout<<"press 2 for directions"<<std::endl;
	std::cout<<"press 3 to quit"<<std::endl;
	std::cin>>menuoption;
	system("clear");
	if(menuoption<49||menuoption>51){
		std::cout<<"Entered Incorrect Value. Please submit correct value\n"<<std::endl;
	}
	else if(menuoption==49){
		std::cout<<"start game"<<std::endl;
		return 1;
	}
	else if(menuoption==50){
		std::cout<<"You are the chosen hero in this new and exciting world\n"
			"Choose from 3 different quests and save whoever needs saving.\n" 
			"Choose your path by selecting the different actions\n"
			"Choose wisely to become the hero this world needs!\n"
			"\n Enter any value to return to main menu\n"<<std::endl;
		std::cin>>menuoption;
		system("clear");

	}
	else if(menuoption==51){
		return -1;
	}


}

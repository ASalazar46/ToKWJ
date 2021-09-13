#include <iostream>
#include <fstream> // to open the story files
#include <string>  // 
#include <nlohmann/json.hpp> // access json assets/class
#include "Director.hpp" // access director functions
#include "Characters.hpp" // access to the characters of the story
#include "Combat.hpp" // access to combat functions

using json = nlohmann::json;

// default constructors and destructors
Director::Director() {
	int choose;
	int run=1;
	while(run!=0){
	std::cout<<"  Townsburg has become so boring.\n  There is no challenge for an aspiring adventurer such as yourself.\n  You decide to go out of town to hone your skills as a...\n 1)Brave Knight\n 2)Powerful Wizard \n 3)God-status OP Jedi\n\nChoose your Character"<<std::endl;
	std::cin>>choose;
	if(choose==1){
		you=new Knight();
		system("clear");
		std::cout<<"You go forth as a Brave Knight."<<std::endl;
		if (CorQ(run) == 0) {setQuest(0);break;}
		system("clear");
	}
	else if(choose==2){
		you=new Wizard();
		system("clear");
		std::cout<<"You go forth as a Powerful Wizard."<<std::endl;
		if (CorQ(run) == 0) {setQuest(0);break;}
		system("clear");
	}
	else if(choose==3){
		you=new Jedi();
		system("clear");
		std::cout<<"You go forth as a Godly Jedi. May the force be with you."<<std::endl;
		if (CorQ(run) == 0) {setQuest(0);break;}
		system("clear");
	}
	run=0;
	setQuest(4);
	}
};
Director::~Director() {delete you;};

// continue to the next event or quit, depending on user input
int Director::CorQ(int r) {
	std::cout << "Press 1 to advance, 0 to quit: ";
	std::cin >> r;
	std::cout << '\n';
	return r;
};

// handle the prologue
void Director::Prologue(json j, Display d) {
	int run=1;
	if(getQuest()==0){run=0;}
	int choice;
	while (run != 0) {
		d.clearScreen();
		d.print(j, "scene000", "event1");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen();
		d.print(j, "scene000", "event2");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen();
		d.print(j, "scene000", "event3");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen();
		d.print(j, "scene000", "event4");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		d.clearScreen();
		d.print(j, "scene000", "event5");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen();
		d.print(j, "scene000", "event6");
		std::cout << '\n';
		std::cin >> choice;
		setQuest(choice);
		run = 0;
	}

};

// handle the Forest quest
void Director::Forest(json j, Display d) {
	int run = 1;
	int choice1, choice2, choice3, choice4;
	while (run != 0) {
		d.clearScreen();    //display event1
		d.print(j, "scene100", "event1");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		d.clearScreen();     //display event2
		d.print(j, "scene100", "event2");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen();    //fight Hurley
		Villager Hurley;
		if (combat(*you, Hurley) == 1) {break;};
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen(); //display event3 and make first choice
		d.print	(j, "scene100", "event3");	
		std::cout << '\n';		
		std::cin >> choice1;
		if (choice1 == 1) {
			you->set_good_points(1+you->get_good_points() );
			d.print (j, "scene100", "choice1g");
		}	
		else if(choice1 == 2) {
			you->set_evil_points(1+you->get_evil_points() );
			d.print (j, "scene100", "choice1e");
		}
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen();    // display event4 and make second choice
		d.print	(j, "scene100", "event4");	
		std::cout << '\n';		
		std::cin >> choice2;
		if (choice2 == 1) {
			you->set_good_points(1+you->get_good_points() );
			d.print (j, "scene100", "choice2g");
		}	
		else if(choice2 == 2) {
			you->set_evil_points(1+you->get_evil_points() );
			d.print (j, "scene100", "choice2e");
		}
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};	
		 	
		d.clearScreen(); // display event5
		d.print(j, "scene100", "event5");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};

		d.clearScreen(); // display event6
		d.print(j, "scene100", "event6");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
	
		d.clearScreen();   // fight curly
		Occultist Curly;
		if (combat(*you, Curly) == 1) {break;};
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		d.clearScreen(); // display event7 and make third choice
		d.print	(j, "scene100", "event7");	
		std::cout << '\n';		
		std::cin >> choice3;
		if (choice3 == 2) {
			you->set_good_points(1+you->get_good_points() );
			d.print (j, "scene100", "choice3g");
		}	
		else if(choice3 == 1) {
			you->set_evil_points(1+you->get_evil_points() );
			d.print (j, "scene100", "choice3e");
		}
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		d.clearScreen(); // display event8
		d.print(j, "scene100", "event8");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
	
		d.clearScreen(); // display event9, make fourth choice, 
		d.print	(j, "scene100", "event9");	
		std::cout << '\n';		
		std::cin >> choice4;
		if (choice4 == 1) {
			you->set_good_points(1+you->get_good_points() );
			d.print (j, "scene100", "choice4g");
		}	
		else if(choice4 == 2) {
			you->set_evil_points(1+you->get_evil_points() );
			d.print (j, "scene100", "choice4e");
		}
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		d.clearScreen(); // fight Burly
		Bolder Burly;
		if(combat(*you, Burly) == 1) {break;};
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		d.clearScreen(); // display event10
		d.print(j, "scene100", "event10");
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		d.clearScreen(); // fight the dragon
		Dragon dragon;
		if(combat(*you, dragon) == 1) {break;};
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		//do the endings
		d.clearScreen();
		if (you->get_good_points() == 4) {
			d.print(j, "scene100", "endingg");
		}	
		else if (you->get_evil_points() == 4) {
			d.print(j, "scene100", "endinge");
		}
		else {
			d.print(j, "scene100", "endingn");
		}
		std::cout << '\n';
		if (CorQ(run) == 0) {break;};
		
		run = 0;
	} // while loop

}; // forest

// handle the Ocean quest
void Director::Ocean(json j, Display d) {
	int run = 1;
	int choice;
	while (run != 0) {
		d.clearScreen();

		d.print(j, "scene200", "event1");
		std::cout << '\n';
		run = 0;

	}

};

// handle the Space quest
void Director::Space(json j, Display d) {
	int run = 1;
	int choice;
	while (run != 0) {
		d.clearScreen();

		d.print(j, "scene300", "event1");
		std::cout << '\n';
		run = 0;

	}

};

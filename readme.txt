Project contents:
-----------------
The bin folder holds the compiled game.

The include folder holds all the hpp files needed to make the game. 

The other folder contains files that were needed for testing certain parts of
the program (mostly for display and combat; folder not used in final version)

The src folder contains all the cpp files needed to make the game. 

The story folder contains the json files that holds all the story dialogue.

The makefile, which compiles the files into an executable (saved to the bin folder)

The team.txt, which lists off the members of this group and who did what.

This readme.txt file


Instructions on how to setup:
-----------------------------
This project assumes that 1) you are using a Linux operating system, and 2) compilers and build essentials are updated.

This project make use of a custom json library, one made by Niels Lohmann and his various other colleagues. 
1) Go to this link: https://github.com/nlohmann/json
2) Click on the big green button that says "Clone or Download." 
3) Click "Donwload ZIP."
4) Extract this zip file. Doing so will produce a single folder called "json-develop." 
5) Move the "json-develop" folder into the "include" folder

For compiling:
---------------
In the main project folder (the directory with all the project folders and the makefile), run in a terminal:
make game

For running:
------------
Move to the bin folder, and type ./game to run the program


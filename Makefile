game: ./bin/game

./bin/game: ./src/*.cpp
	g++ ./src/*.cpp -o ./bin/game -I ./include/json-develop/include/ -I ./include

clean:
	rm ./bin/game

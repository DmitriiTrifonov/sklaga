build: bin/
	clang++ -std=c++2b src/main.cpp -o bin/game `sdl2-config --cflags` `sdl2-config --libs`
bin/:
	mkdir bin

run: bin/game
	./bin/game

clean:
	rm bin/*
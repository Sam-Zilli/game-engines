// game.cpp
#include <iostream>
#include "GameState.hpp"

void prompt() {
	std::cout << "1. Advance\n";
	std::cout << "2. Go back...\n";
	std::cout << std::endl;
}

void input(GameState& gs) {
	int value;
	std::cin >> value;
	gs.SetChoice(value);
}

void update(GameState& gs) {
	if(1==gs.GetChoice()) {
		// moving forward one line
		gs.SetCurrentLine(gs.GetCurrentLine()+1);
	}
	else if(2 == gs.GetChoice()) {
		// moving backwards one line
		gs.SetCurrentLine(gs.GetCurrentLine()-1);
	}
}

void render(GameState& gs) {
	gs.PrintCurrentLine();
}

int main(int argc, char* argv[]) {
	if(argc<2) {
		std::cout << "./prog story.txt\n";
	}

	GameState gs(argv[1]);

	while(true) {
		prompt();
		input(gs);
		update(gs);
		render(gs);
	}
}

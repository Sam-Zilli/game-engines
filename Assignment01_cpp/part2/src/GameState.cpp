#include "GameState.hpp"
#include <iostream>

// Constructor - takes a file as a string
GameState::GameState(std::string file) {
	std::ifstream myFile(file.c_str());
	std::string line;


	if(myFile.is_open()) {
		while(getline(myFile, line)) {
			if(!line.empty()) {
					mStory.push_back(line);
			}
		}
	} else {
		std::cout<<"unable to open file\n";
	}

	mChoice = 0;
	mCurrentLine = 0;

	std::cout << mStory[0] << std::endl;
}

// Destructor 
GameState::~GameState() {
	std::cout << "The end" << std::endl;
}


// Get Current Line
size_t GameState::GetCurrentLine() const { 
	return mCurrentLine;
}

// Set Current Line
void GameState::SetCurrentLine(size_t value) {
	// cannot be a "negative" line
	if(value < 0) {
		mCurrentLine = 0;
	}
	// if at end, set back to 0
	else if(value > mStory.size()-1) {
		mCurrentLine = 0;
	}
	else {
		mCurrentLine = value;
	}
}


// Print Current Line
void GameState::PrintCurrentLine() {
	std::cout << mStory[mCurrentLine] << std::endl;
}

void GameState::SetChoice(int value) {
	mChoice = value;
}

int GameState::GetChoice() const {
	return mChoice;
}




// GameState.hpp
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>


class GameState {
	public:
		// Constructor
		GameState(std::string file);

		// Destructor
		~GameState();

		// Get current line
		size_t GetCurrentLine() const;

		// Set current line
		void SetCurrentLine(size_t value);

		void PrintCurrentLine();

		void SetChoice(int value);

		// Get last choice made
		int GetChoice() const;

	private:
		int mChoice;
		size_t mCurrentLine;
		std::vector<std::string> mStory;
};

#endif

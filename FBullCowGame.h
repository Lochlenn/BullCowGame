#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset();  // TODO make a more rich return value
	int GetMaxTries();
	bool CheckGuessValidity(std::string);
	bool IsGameWon();
	int GetCurrentTry();





private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
#pragma once
#include <string>

class FBullCowGame {
public:
	int GetMaxTries() const;
	bool IsGameWon() const;
	int GetCurrentTry() const;

	void Reset();  // TODO make a more rich return value
	bool CheckGuessValidity(std::string);
	// SomeNewType to submit valid guess STRING
	// provide a method for counting bulls and cows and increasing try #


private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
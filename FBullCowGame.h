#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	int32 GetMaxTries() const;
	bool IsGameWon() const;
	int32 GetCurrentTry() const;

	void Reset();  // TODO make a more rich return value
	bool CheckGuessValidity(FString);
	// SomeNewType to submit valid guess STRING
	// provide a method for counting bulls and cows and increasing try #


private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;
};
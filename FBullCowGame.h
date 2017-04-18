#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	bool IsGameWon() const;
	int32 GetCurrentTry() const;

	void Reset();  // TODO make a more rich return value
	bool CheckGuessValidity(FString);

	BullCowCount SubmitGuess(FString);


private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;
	FString MyHiddenWord;
};
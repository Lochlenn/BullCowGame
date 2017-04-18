#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

FBullCowGame::FBullCowGame()
{

}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// recieves a valid guess, increments turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment turn number
	MyCurrentTry++;
	// setup a return variable
	BullCowCount BullCowCount;
	// loop through letters in guess
		// compare letters against hidden word 

	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}



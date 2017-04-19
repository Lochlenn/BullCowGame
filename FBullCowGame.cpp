#include "FBullCowGame.h"

using int32 = int;


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

FBullCowGame::FBullCowGame() { Reset(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// recieves a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through letters in guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against hidden word 
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
					
				}
				else {
					BullCowCount.Cows++;
					
				}
			}
		}
	}

	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}



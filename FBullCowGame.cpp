#include "FBullCowGame.h"

using int32 = int;

// getters
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

FBullCowGame::FBullCowGame() { Reset(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isnt an isogram, return an error
	{
		return EGuessStatus::Not_IsoGram;
	}
	else if (false)  //if the guess isnt all lowercase return error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (GetHiddenWordLength() != Guess.length()) 	// if guess length is wrong, return error
	{
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
	// otherwise return OK



	return EGuessStatus::OK; 
}

// recieves a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	// loop through letters in word
	int32 WordLength = MyHiddenWord.length(); // assuming the same length as guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
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



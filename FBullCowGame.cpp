#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

// getters
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame() { Reset(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) 
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
	bGameIsWon = false;
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
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter strings as isograms
	
	// loop through all the letter of the word
		// if letter is in the map
			// we do NOT have an isogram
		// otherwise
			// add letter to the map as seen

	return true; // for example in cases where /0 is entered
}



#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

// getters
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,5}, {4, 8}, {5,10}, {6,15}, {7, 21} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{

	const FString HIDDEN_WORD = "merlin";
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
	else if (!IsLowercase(Guess))  //if the guess isnt all lowercase return error
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
	if (Word.length() <= 1) { return true; }
	
	// setup map
	TMap<char, bool> LetterSeen;
	// loop through all the letter of the word
	for (auto Letter : Word) // for all letter of the word
	{	
		Letter = tolower(Letter);
		// if letter is in the map
		if (LetterSeen[Letter] == true) { return false; } // we do NOT have an isogram
		else { LetterSeen[Letter] = true; } // add letter to the map as seen
			
	}
	return true; // for example in cases where \0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) { 
			return false; 
		}
	}
	return true;
}



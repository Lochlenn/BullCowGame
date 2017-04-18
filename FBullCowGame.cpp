#include "FBullCowGame.h"

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

void FBullCowGame::Reset()
{
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}



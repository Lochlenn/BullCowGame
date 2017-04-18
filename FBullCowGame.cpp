#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

void FBullCowGame::Reset()
{
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}



#pragma once

class FBullCowGame {
public:
	void Reset();  // TODO make a more rich return value
	int GetMaxTries();
	bool CheckGuessValidity();
	bool IsGameWon();
	int GetCurrentTry;





private:
	int MyCurrentTry;
	int MyMaxTries;
};
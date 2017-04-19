/* This is the console executable that makes use of
   the BullCow class.  This acts as the view in a MVC
   patters responsible for all user interaction. For game logic
   see FBullCowGame class
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// entry point into the application
int main() 
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0;
}

void PrintIntro() 
{
	// int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	// introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram that I'm thinking of?\n";

	return;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	//TODO change from FOR to WHILE loop once validating tries
	for (int32 i = 1; i <= 5; i++) {
		FText Guess = GetValidGuess(); 

		// submit valild guess to game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << "\n\n";
	}
	// TODO add game summary
}

FText GetValidGuess() // loop continually until valid guess is given

{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try: " << CurrentTry << "\nEnter a guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_IsoGram:
			std::cout << "Please enter an isogram (no letters used more than once).\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all guesses in lowercase only.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y'); // return value of 1 if conditions met
	return false;
}


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
FText GetGuess();
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
	// introduce the game
	constexpr int32 WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram that I'm thinking of?\n";

	return;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	//TODO change from FOR to WHILE loop once validating tries
	for (int32 i = 1; i <= 5; i++)
	{
		FText Guess = GetGuess(); // TODO make loop check for valid guesses before decrimenting tries remaining
		
		// submit valild guess to game
		// print number of bulls and cows

		std::cout << "Your guess was " << Guess << ".\n";
	}
	// TODO add game summary
}

FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// get a guess from the player
	std::cout << "Try: " << CurrentTry << "\nEnter a guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y'); // return value of 1 if conditions met
	return false;
}


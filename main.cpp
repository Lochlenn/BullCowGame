#include <iostream>
#include <string>


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


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
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram that I'm thinking of?\n";

	return;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was " << Guess << ".\n";
	}
}

std::string GetGuess() 
{
	// get a guess from the player
	std::cout << "\nEnter a guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y'); // return value of 1 if conditions met
	return false;
}


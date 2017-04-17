#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();


// entry point into the application
int main() 
{
	PrintIntro();
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++) 
	{
		GetGuessAndPrintBack();
	}
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

string GetGuessAndPrintBack() 
{
	// get a guess from the player
	std::cout << "\nEnter a guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	// repeat guess back to player
	std::cout << "Your guess was " << Guess << ".\n";
	
	return Guess;
}
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram that I'm thinking of?\n";

	// get a guess from the player
	std::cout << "\n\nEnter a guess: ";
	std::string Guess = "";
	std::getline (std::cin, Guess);

	// repeat guess back to player
	std::cout << "\nYour guess was " << Guess << ".\n";

	// get a guess from the player
	std::cout << "\n\nEnter a guess: ";
	std::getline(std::cin, Guess);

	// repeat guess back to player
	std::cout << "\nYour guess was " << Guess << ".\n";
	return 0;
}
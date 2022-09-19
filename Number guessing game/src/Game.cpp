#include "Game.h"
#include "include.h"

void Game::Life()
{
	if (i == 1) {
		life = 4;
	}
	else if (i < 1) {
		life = life - 1;
	}
	i = 1;
	
}
void Game::Round()
{
Round_Start:
	int User_Guess = 0;

	std::cout << "\n" << "Current Life: " << life << "\n";
	std::cout << "Guess a number betwean 1 and 100: ";
	std::cin >> User_Guess;
	if (User_Guess == Correct_Number) {
		std::cout << "Good job! you guessed correctly." << "\n";
		std::cout << "Number of successful guesses: " << Number_Of_Success;
	}
	else if (User_Guess > Correct_Number) {
		std::cout << "Too bad! Your guess was too high." << "\n";
		i = i - 1;
		Life();
		if (life <= 0) {
			std::cout << "\n" << "You have died! Too bad" << "\n";
			return;
		}
		goto Round_Start;
	}
	else {
		std::cout << "Too bad! Your guess was too low." << "\n";
		i = i - 1;
		Life();
		if (life <= 0) {
			std::cout << "\n" << "You have died! Too bad" << "\n";
			return;
		}
		goto Round_Start;
	}

}
void Game::Run() 
{
Start:
	std::string again;
	srand(time(NULL));
	Life();
	Correct_Number = rand() % 2 + 1;
	Round();
	Number_Of_Success++;
Writing_error:
	std::cout << "\n" << "Do you want to play again?" << "\n";
	std::cin >> again;
	if (again == "yes") {
		goto Start;
	}
	else if (again == "no")
	{

	}
	else {
		std::cout << "\n" << "please write yes or no";
		goto Writing_error;
	}
}
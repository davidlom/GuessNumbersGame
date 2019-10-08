#include <iostream>
#include <ctime>

void IntroText(int Difficulty)
{
	//Intro Text
	std::cout << "\nHello, Player!\n";
	std::cout << "\nImagine, that you are a secret agent, who is breaking the most secret code.\n\nNow, you are on the Level: " << Difficulty << "!";
	std::cout << "\n\nTo break the code, you have to enter the correct numbers!";
	std::cout << "\nHurry up! You are running out of time...\n";
}

bool PlayGame(int Difficulty)
{
	IntroText(Difficulty);

	//Veriables - Declaring Numbers
	const int CodeA = rand() % Difficulty + 2;
	const int CodeB = rand() % Difficulty + 2;
	const int CodeC = rand() % Difficulty + 2;

	const int CodeSum = CodeA + CodeB + CodeC;

	const int CodeProduct = CodeA * CodeB * CodeC;

	//Printing Out Results Text
	std::cout << std::endl;
	std::cout << "There are 3 numbers in the secret Code." << std::endl;
	std::cout << std::endl;
	std::cout << "The result of their Adding is: " << CodeSum << std::endl;
	std::cout << "The result of their Multiply is: " << CodeProduct << std::endl;


	//Store player guess input
	int GuessA, GuessB, GuessC;
	std::cout << std::endl;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//Check if player's guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\nCorrect Answers! Well Done!\n";
		std::cout << "-------------------------------------------------------------";
		std::cout << "\n :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :)\n";
		std::cout << "-------------------------------------------------------------\n";
		return true;
	}
	else
	{
		std::cout << "\nYou Loose, Try Again!\n";
		std::cout << "-------------------------------------------------------------";
		std::cout << "\n :( :( :( :( :( :( :( :( :( :( :( :( :( :( :( :( :( :( :( :(\n";
		std::cout << "-------------------------------------------------------------\n";
		return false;
	}

}

int main()
{
	srand(time(NULL)); //Creats random number based on time

	int LevelDifficulty = 1;

	int const MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) // Loops game until all levels are completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); //Clears any Errors
		std::cin.ignore(); //Discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty; // increas difficulty!
		}

	}

	std::cout << "\nCongratulations! You've completed all levels!" << std::endl;

	return 0;
}
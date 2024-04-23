#include <iostream>

class startInput {
public:
	char userInput = 0;
	void yesOrNo() {   // Takes the user input, ensures it's valid, and sets it lowercase for compatibility.
		bool response;
		do {
			std::cin >> userInput;
			userInput = tolower(userInput);
			if (userInput == 'n') {
				std::cout << "\nYou've entered 'n', see ya!\n\n";
				response = false;
				system("pause");
			}
			else if (userInput == 'y') {
				std::cout << "You've entered 'y', your game will begin shortly...";
				response = false;
			}
			else {
				std::cout << "You've entered an invalid response, please type either 'y' or 'n'.\nThank you. (y\\n) ";
				response = true;
			}
		} while (response == true);
	}
};

class activeGame {  // Game: number generator and user input
public:
	int winnerNum = 0;
	int userInput = 0;
	const int randMax = 10;
	const int randMin = 1;
	bool winStatus = false;
	void randomNum() {
		srand(time(NULL));
		int winnerNum = rand() % randMax + randMin;
		std::cout << "\nThe winning number is ";
		std::cout << winnerNum << " ";
		if (winnerNum == userInput) {
			winStatus = true;
		}
	}
};

int main() {	//Game Start
	std::cout << "Welcome to Trent's guessing game!\n";
	std::cout << "Type 'y' to start playing or 'n' to quit. ";
	startInput gameStart;
	activeGame gameWorking;
	gameStart.yesOrNo();
	if (gameStart.userInput == 'y') {
		std::cout << "\n\nStarting Game...Please Wait";
		std::cout << "\n\nGuess a number between 1 and 10: ";
		std::cin >> gameWorking.userInput;
		gameWorking.randomNum();
		std::cout << "\nYou picked " << gameWorking.userInput << ".";
		if (gameWorking.winStatus) { // Checks if you're a winner or not
			std::cout << "\n\nYou won, Congradulations!\n\n";
			system("pause");
		}
		else {
			std::cout << "\n\nYou guessed incorrectly, better luck next time!\n\n";
			system("pause");
		}
	}
	return 0;
}
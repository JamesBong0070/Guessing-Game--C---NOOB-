#include <iostream>

class startInput {
public:
	const char yesInput = 'y';
	const char noInput = 'n';
	char userInput = NULL;
	bool run = true;
	void yesOrNo() { // Takes the user input, ensures it's valid, and sets it lowercase for compatibility.
		do {
			std::cin >> userInput;
			userInput = tolower(userInput);
			if (userInput == noInput) {
				std::cout << "You've entered 'n', the program will end now.";
				run = false;
				break;
			}
			if (userInput == yesInput) {
				std::cout << "You've entered 'y', your game will begin shortly...";
				run = false;
				break;
			}
			else {
				std::cout << "You've entered an invalid response, please type either 'y' or 'n'.\nThank you. (y\\n) ";
			}
		} while (run);
	}
};

class activeGame {  // Game: number generator and user input
public:
	int winnerNum = NULL;
	int userInput = NULL;
	const int randMax = 10;
	const int randMin = 1;
	void randomNum() {
		srand(time(NULL));
		int winnerNum = rand() % randMax + randMin;
		std::cout << "The winning number is ";
		std::cout << winnerNum << " ";
	}
};

int main() {
	               //Game Start
	std::cout << "Welcome to Trent's guessing game!\n";
	std::cout << "Type 'y' to start playing or 'n' to quit. ";
	startInput gameStart;
	activeGame gameWorking;
	gameStart.yesOrNo();
	if (gameStart.userInput == gameStart.yesInput) {
		std::cout << "\n\nStarting Game...Please Wait";
		std::cout << "\n\nGuess a number between 1 and 10: ";
		std::cin >> gameWorking.userInput;
		gameWorking.randomNum();
		std::cout << "\nYou picked " << gameWorking.userInput << ".";
		if (gameWorking.userInput == gameWorking.winnerNum) { // Checks if you're a winner or not
			std::cout << "\nYou won, Congradulations!";
		}
		else {
			std::cout << "\nYou guessed incorrectly, better luck next time!";
		}
	}
	return 0;
}
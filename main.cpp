#include <iostream>
#include <random>
#include <format>

void displayWelcomeMessage();
void displayIncorrectGuessMessage();
void displayCorrectGuessMessage(int);
void displayGoodbyeMessage();
void displayGuessCountMessage(int);

int displayGuessPrompt();
bool displayReplayPrompt();

int	generateRandomNumber(int, int);


const int MIN_VALUE = 1;
const int MAX_VALUE = 10;


int main()
{
	while (true)
	{
		displayWelcomeMessage();

		int randomNumber = generateRandomNumber(MIN_VALUE, MAX_VALUE);
		int guessCounter = 0;

		while (displayGuessPrompt() != randomNumber)
		{
			guessCounter++;
			displayIncorrectGuessMessage();
		}

		guessCounter++;
		displayCorrectGuessMessage(randomNumber);
		displayGuessCountMessage(guessCounter);

		

		if (!displayReplayPrompt()) {
			displayGoodbyeMessage();
			break;
		}
	}

	return 0;
}


void displayWelcomeMessage()
{
	std::string copyrightNotice = "(c)2023 ByteHowler all rights reserved\n\n";

	std::string welcomeMessage = "Number Guesser\nIn this game the objective is"
		" to guess the randomly generated game in as few guesses as possible.\n\n";

	std::cout << copyrightNotice << welcomeMessage;
}

void displayIncorrectGuessMessage()
{
	std::string wrongMessage = "Oops, that guess was incorrect, please try again.\n\n";

	std::cout << wrongMessage;
}

void displayCorrectGuessMessage(int correctNumber)
{
	std::string correctMessage = std::format(
		"Congratulations, you guessed correctly, the number was indeed {}.\n", correctNumber
	);

	std::cout << correctMessage;
}

void displayGoodbyeMessage()
{
	std::string goodbyeMessage = "Thank you for playing!\nShutting down...";

	std::cout << goodbyeMessage << std::endl;
}


void displayGuessCountMessage(int guessCount)
{
	std::string guessCountMessage = std::format(
		"It took you {} {}.\n\n", guessCount, (guessCount > 1 ? "guesses" : "guess"));

	std::cout << guessCountMessage;
}


int displayGuessPrompt()
{
	std::string guessPromptMessage = std::format(
		"Please choose a number between {} and {}: ", MIN_VALUE, MAX_VALUE
	);
	int playerGuess;

	while (std::cout << guessPromptMessage && !(std::cin >> playerGuess) 
		|| playerGuess < MIN_VALUE || playerGuess > MAX_VALUE)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::format(
			"Invalid input. please enter a number between {} and {}.\n", MIN_VALUE, MAX_VALUE
		);
	}

	return playerGuess;
}

bool displayReplayPrompt()
{
	return false;
}


int generateRandomNumber(int min, int max)
{
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}
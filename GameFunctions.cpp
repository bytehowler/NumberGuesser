#include <iostream>
#include <random>
#include <format>

#include "GameFunctions.h"


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
	int playerGuess{};

	// Ensures that an int is entered, then checks if the input is between MIN_VALUE and MAX_VALUE.
	// If any of these conditions is incorrect, an error message is outputted and the prompt repeats.
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
	std::string replayPromptMessage = "Do you wish to play again? (Y/n) ";
	char playerInput{};

	// Ensures that a char is entered, then checks if the input is 'y' or 'n'.
	// If any of these conditions is incorrect, an error message is outputted and the prompt repeats.
	while (std::cout << replayPromptMessage && !(std::cin >> playerInput)
		|| !(tolower(playerInput) == 'y') && !(tolower(playerInput) == 'n'))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Invalid input. please enter either 'Y' or 'n'.\n";
	}

	return tolower(playerInput) == 'y';
}


int generateRandomNumber(int min, int max)
{
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}
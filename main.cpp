#include <iostream>
#include <random>

void displayWelcomeMessage();
void displayIncorrectGuessMessage();
void displayCorrectGuessMessage();
void displayGoodbyeMessage();

void displayGuessCount(int);
bool displayReplayPrompt();

int	generateRandomNumber(int, int);
int getPlayerGuess();


int main()
{
	while (true)
	{
		displayWelcomeMessage();

		int randomNumber = generateRandomNumber(1, 10);

	}

	return 0;
}
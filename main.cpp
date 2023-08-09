#include "GameFunctions.h"

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
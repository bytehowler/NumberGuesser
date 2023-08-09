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

		// This is the main guessing loop, it keeps repeating
		// and incrementing the guess counter untill the correct number is guessed
		while (displayGuessPrompt() != randomNumber)
		{
			guessCounter++;
			displayIncorrectGuessMessage();
		}

		guessCounter++;
		displayCorrectGuessMessage(randomNumber);
		displayGuessCountMessage(guessCounter);

		
		// This in the replay prompt loop, it only accepts 'Y' or 'N' (case insensitive).
		// Any other input causes the prompt to repeat until the proper input is given.
		// 
		// If 'N' is given, the program shuts down, 
		// if 'Y' is given, the program starts from the top. 
		if (!displayReplayPrompt()) {
			displayGoodbyeMessage();
			break;
		}
	}

	return 0;
}
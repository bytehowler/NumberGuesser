#pragma once

extern const int MIN_VALUE;
extern const int MAX_VALUE;

void displayWelcomeMessage();
void displayIncorrectGuessMessage();
void displayCorrectGuessMessage(int);
void displayGoodbyeMessage();
void displayGuessCountMessage(int);

int displayGuessPrompt();
bool displayReplayPrompt();

int	generateRandomNumber(int, int);


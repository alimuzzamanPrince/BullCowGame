#include "stdafx.h"
#include <iostream>
#include <string>
#include "BullCowGame.h"

using namespace std;
using FText = string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

BullCowGame BCGame;

int main()
{
	PrintIntro();
	cout << BCGame.GetCurrentTry() << endl;
	cout << BCGame.GetMaxTry() << endl;

	bool PlayAgain;
	do
	{
		PlayGame();
		PlayAgain = AskToPlayAgain();
	} while (PlayAgain);
	return 0;
}

void PlayGame()
{
	//TODO implement game logic
	BCGame.Reset();
	int32 MAX_TRY = BCGame.GetMaxTry();
	for (int32 i = 0; i < MAX_TRY; i++) {
		FText UserGuess = GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(UserGuess);
		cout << "Bulls: " <<BullCowCount.Bulls<<". Cows: "<<BullCowCount.Cows<< endl;
	}
}
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	cout << "Welcome to bulls and cows::A fun game\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

FText GetGuess()
{
	FText Guess;
	int32 CRR_TRY = BCGame.GetCurrentTry();
	cout << "Try " << CRR_TRY << ": Enter your guess: ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?(y/n)\n";
	FText Response;
	getline(cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}
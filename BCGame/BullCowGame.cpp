#include "stdafx.h"
#include "BullCowGame.h"
#include <string>
using int32 = int;
using FText = std::string;
// BullCowGame.cpp : Defines the entry point for the console application.
//

BullCowGame::BullCowGame()
{
	Reset();
}

void BullCowGame::Reset()
{
	const int32 MAX_TRIES = 5;
	const FText HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	MyMaxTry = MAX_TRIES;
	return;
}

int32 BullCowGame::GetMaxTry() const
{
	return MyMaxTry;
}

int32 BullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool BullCowGame::IsGameWon() const
{
	return false;
}

bool BullCowGame::IsValid(FText)
{
	//TODO implement checking conditions
	return false;
}

//Receives a valid guess, increments turn, & returns count
FBullCowCount BullCowGame::SubmitGuess(FText Guess)
{
	//increment turn
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++){
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (Guess[i]==MyHiddenWord[i])
			{
				BullCowCount.Bulls++;
			}
			else
			{
				BullCowCount.Cows++;
			}
		}
	}
	  //compare with the hidden word
	return BullCowCount;
}

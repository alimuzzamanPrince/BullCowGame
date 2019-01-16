#pragma once
#include <string>
using FText = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class BullCowGame {
public:
	BullCowGame();
	void Reset();
	int32 GetMaxTry() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool IsValid(FText);
	FBullCowCount SubmitGuess(FText);

private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTry = 5;
	FText MyHiddenWord;
};

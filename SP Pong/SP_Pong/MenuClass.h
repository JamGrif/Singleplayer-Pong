#pragma once
#include <string>
#include "windows.h"
using namespace std;

class MenuClass
{
public:

	void Ask(); //Ask the user if they want to play, view instructions or exit
	void EndGameAsk(int score); //Appears when the player loses the game.

	void MChoice (string MenuChoice); //Takes the users input and makes an apprioate action to input
	void EChoice(string EndChoice);

	bool GetIsGameRunning(); //Returns if the game is running or not
	void FlipGameState(); //Changes IsGameRunning to false if true or vice versa

	void ShowConsoleCursor(bool ShowCursor);

private:
	bool m_IsGameRunning = false;

	int m_scorevalue = 0;
};



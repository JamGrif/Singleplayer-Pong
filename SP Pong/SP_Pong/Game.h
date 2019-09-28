#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuClass.h"
#include "CourtClass.h"
#include "PaddleClass.h"
#include "BallClass.h"
#include "ScoreClass.h"
using namespace std;

class Game
{
public:
	void Initialize();
	void Run();

private:
	char Direction; //Used to save what direction the player wants to move. Either u or d
	char key; //Used to save what keyboard key the player pressed

	int PadY = 0;
	int PadXL = 0;
	int PadXR = 0;
	int PadUpSize = 0;
	int PadDownSize = 0;

};


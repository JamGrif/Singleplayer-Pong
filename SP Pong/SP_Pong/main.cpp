#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuClass.h"
#include "CourtClass.h"
#include "PaddleClass.h"
#include "BallClass.h"
#include "ScoreClass.h"
using namespace std;

MenuClass menuobj;
int main() 
{ 
	menuobj.ShowConsoleCursor(false);
	//Showing the user the main menu and waiting for player decision
	menuobj.Ask();
	
	//Creating the objects and drawes them if needed
	CourtClass courtobj;
	courtobj.DrawCourt();
	PaddleClass leftobj(4,13);
	PaddleClass rightobj(45,13);
	BallClass ballobj;
	ScoreClass scoreobj;
	
	char Direction; //Used to save what direction the player wants to move. Either u or d
	char key; //Used to save what keyboard key the player pressed
	//Variables used to retrive information from the paddles object to be sent to the ball object. PadL = left paddle / PadR = right paddle
	int PadY = 0;
	int PadXL = 0;
	int PadXR = 0;
	int PadUpSize = 0;
	int PadDownSize = 0;

	PadXL = leftobj.GetXPos();
	PadXR = rightobj.GetXPos();
	PadUpSize = leftobj.GetUpSize();
	PadDownSize = leftobj.GetDownSize();

	while (menuobj.GetIsGameRunning() == true && ballobj.IsBallAlive() == true) //Main game loop
	{
		//If keyboard input is detected
		if (_kbhit()) 
		{
			key = _getch();
			switch (key) 
			{
				case 72: //Up arrow pressed
					Direction = 'u';
					leftobj.MovePaddle(Direction); //Moves left paddle
					rightobj.MovePaddle(Direction); //Moves right paddle
					break;
				case 80: //Down arrow pressed
					Direction = 'd';
					leftobj.MovePaddle(Direction); //Moves left paddle
					rightobj.MovePaddle(Direction); //Moves right paddle
					break;
			}
			//Gets position of left and right paddle. This gets sent to the ball class
			PadY = leftobj.GetYPos();
			
		}
		//Moves the ball
		ballobj.MoveBall(PadY,PadXL,PadXR,PadUpSize,PadDownSize);
		//Increase score if ball hits a paddle
		if (ballobj.ShouldScoreIncrease() == true) 
		{
			scoreobj.IncreaseScore();
		}
		//Prints the score
		scoreobj.PrintScore();
	}
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //Change text colour back to the default white
	cout << "You have lost!" << endl;
	cout << "Your final score was " << scoreobj.GetScore() << "!" << endl;
	return 0;
}
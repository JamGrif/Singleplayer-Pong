#include "Game.h"

void Game::Initialize()
{
}

void Game::Run()
{
	MenuClass menuobj;
	menuobj.ShowConsoleCursor(false);
	//Showing the user the main menu and waiting for player decision
	menuobj.Ask();

	while (menuobj.GetIsGameRunning() == true) //Main game loop
	{
		//Creating the objects and drawes them if needed
		CourtClass* courtobj = new CourtClass;
		courtobj->DrawCourt();
		PaddleClass* leftobj = new PaddleClass(4, 13);
		PaddleClass* rightobj = new PaddleClass(45, 13);
		BallClass* ballobj = new BallClass;
		ScoreClass* scoreobj = new ScoreClass;

		PadXL = leftobj->GetXPos();
		PadXR = rightobj->GetXPos();
		PadUpSize = leftobj->GetUpSize();
		PadDownSize = leftobj->GetDownSize();
		while (ballobj->IsBallAlive() == true)
		{
			//If keyboard input is detected
			if (_kbhit())
			{
				key = _getch();
				switch (key)
				{
				case 72: //Up arrow pressed
					Direction = 'u';
					leftobj->MovePaddle(Direction); //Moves left paddle
					rightobj->MovePaddle(Direction); //Moves right paddle
					break;
				case 80: //Down arrow pressed
					Direction = 'd';
					leftobj->MovePaddle(Direction); //Moves left paddle
					rightobj->MovePaddle(Direction); //Moves right paddle
					break;
				}
				//Gets position of left and right paddle. This gets sent to the ball class
				PadY = leftobj->GetYPos();
			}
			//Moves the ball
			ballobj->MoveBall(PadY, PadXL, PadXR, PadUpSize, PadDownSize);
			//Increase score if ball hits a paddle
			if (ballobj->ShouldScoreIncrease() == true)
			{
				scoreobj->IncreaseScore();
			}
			//Prints the score
			scoreobj->PrintScore();
		}
		//Asked if want to replay or exit game
		menuobj.EndGameAsk(scoreobj->GetScore());
		//Game ends here. Game objects are deleted
		delete courtobj;
		delete leftobj;
		delete rightobj;
		delete ballobj;
		delete scoreobj;
	}
}

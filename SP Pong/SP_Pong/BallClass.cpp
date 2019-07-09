#include "BallClass.h"

BallClass::BallClass()
{
	m_BallAlive = true; //Variable used to tell main function if ball is alive or not
	srand(time(0));
	//Sets balls starting position
	m_XPos = 25; 
	m_YPos = 13;

	m_XNext = m_XPos;
	m_YNext = m_YPos;

	//Random numbers generator to randomize the balls direction when it is first spawned. Can only pick either 1 or 2.
	m_RandomNumber = (1 + (rand() % 2));
	m_XDirection = m_RandomNumber == 1 ? Right : Left;

	m_RandomNumber = (1 + (rand() % 2));
	m_YDirection = m_RandomNumber == 1 ? Down : Up;
	
	//Draws the ball in it starting position
	coord.X = m_XPos;
	coord.Y = m_YPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_BallColour);
	cout << m_Block;
}


void BallClass::MoveBall(int PadY, int LeftX, int RightX, int UpSize, int DownSize)
{
	if (m_XPos == 1 || m_XPos == 49) //Check if ball has hit the red wall behind the paddles
	{
		m_BallAlive = false;
	}

	m_times++;
	if (m_times == 300) //Times variable is used to slow down the movement of the ball without using a sleep funciton. If a sleep function is used then the players movement is lagged
	{
		m_times = 0;
		//Determine where the balls next position is
		//Decide if the Y balue needs to be flipped
		if (m_YPos == 1) //If ball is touching the top of court
		{
			m_YDirection = Down; //Ball starts moving down
		}
		else if (m_YPos == 24) //If ball is touching bottom of court
		{
			m_YDirection = Up; //Balls starting moving up
		}	
		m_YNext = m_YPos + m_YDirection;

		if ((m_XPos == LeftX+1) && (m_YPos < PadY+DownSize+1 && m_YPos > PadY-UpSize-1)) //If ball is touching the left paddle
		{
			m_XDirection = Right; //Ball starts moving right
			m_ScoreIncrease = true;
		}
		else if ((m_XPos == RightX-1) && (m_YPos < PadY+DownSize+1 && m_YPos > PadY-UpSize-1)) //If ball is touching the right paddle
		{
			m_XDirection = Left; //Ball starts moving left
			m_ScoreIncrease = true;
		}
		m_XNext = m_XPos + m_XDirection;

		//Sets the balls next cordinates and draws it on that position. 

		coord.X = m_XNext;
		coord.Y = m_YNext;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_BallColour);
		cout << m_Block;

		//Removes the old ball by drawning over it with the court colour
		coord.X = m_XPos;
		coord.Y = m_YPos;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_CourtBackColour);
		cout << m_Block;

		//Updates the balls position 
		m_XPos = m_XNext;
		m_YPos = m_YNext;
	}
}

bool BallClass::ShouldScoreIncrease()
{
	if (m_ScoreIncrease == true)
	{
		m_ScoreIncrease = false;
		return true;
	}
	return false;
	
}

bool BallClass::IsBallAlive()
{
	return m_BallAlive;
}







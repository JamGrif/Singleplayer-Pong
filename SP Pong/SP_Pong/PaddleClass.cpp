#include "PaddleClass.h"
PaddleClass::PaddleClass(int XValue, int YValue)
{
	//Sets the starting position of the paddle
	m_PaddleX = XValue;
	m_PaddleY = YValue;  

	//Sets NextX Y variables to same as starting position
	m_NextX = m_PaddleX;
	m_NextY = m_PaddleY;

	coord.X = m_PaddleX;

	//Works out the size of paddles from text file value
	m_UpSize = (m_PaddleSize / 2) - 1;
	m_DownSize = m_PaddleSize / 2;

	//Draws the paddles in their starting position
	//Centre block
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_PaddleColour);
	coord.Y = m_PaddleY;
	
	//Blocks above centre block
	for (int i = 0; i <= m_UpSize; i++) 
	{
		coord.Y -= i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << m_Block;
		coord.Y = m_PaddleY;
	}

	//Blocks below centre block
	for (int i = 0; i <= m_DownSize; i++) //Draws blocks below centre block
	{
		coord.Y += i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << m_Block;
		coord.Y = m_PaddleY;
	}
}

void PaddleClass::MovePaddle(char Direction)
{
	//Take users input and change change NextY value as the paddles next Y position
	if (Direction == 'u' && m_PaddleY - m_UpSize != 1) //Checks that the paddle can move up and not outside the court area. It checks the middle paddles squares position.
	{
		m_NextY = m_PaddleY - 1;
	}
	else if (Direction == 'd' && m_PaddleY + m_DownSize != 24) //Checks that the paddle can move down and not outside the court area. It checks the middle paddles squares position.
	{
		m_NextY = m_PaddleY + 1;
	}
	
	if (m_PaddleY != m_NextY) //Runs if the paddles next position is not the same as the current position indicating the paddle is trying to move outside the court area
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_PaddleColour);
		//Centre block
		coord.Y = m_NextY;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << m_Block;

		//Blocks above centre block
		for (int i = 0; i <= m_UpSize; i++)
		{
			coord.Y -= i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << m_Block;
			coord.Y = m_NextY;
		}

		//Blocks below centre block
		for (int i = 0; i <= m_DownSize; i++) //Draws blocks below centre block
		{
			coord.Y += i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << m_Block;
			coord.Y = m_NextY;
		}

		//Removes old paddle block in old Y position
		if (Direction == 'u') 
		{
			coord.Y = m_PaddleY + m_DownSize;
		}
		else 
		{
			coord.Y = m_PaddleY - m_UpSize;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_CourtBackColour);
		cout << m_Block;

		//sets Y value to the current position
		m_PaddleY = m_NextY;
	}
}

int PaddleClass::GetYPos()
{
	return m_PaddleY;
}

int PaddleClass::GetXPos()
{
	return m_PaddleX;
}

int PaddleClass::GetUpSize()
{
	return m_UpSize;
}

int PaddleClass::GetDownSize()
{
	return m_DownSize;
}






#include "CourtClass.h"

using namespace std;

void CourtClass::DrawCourt()
{
	while (m_PosX != m_MaxX && m_PosY != m_MaxY) //Loop to draw the court. Ensures the left and right walls are red with the rest being white
	{
		// set cursor to position PosX and PosY and print
		coord.X = m_PosX;
		coord.Y = m_PosY;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (m_PosX == m_MinX || m_PosX == m_MaxX-1 || m_PosY == m_MinY || m_PosY == m_MaxY - 1) {
			//Left/Right wall
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_CourtSideColour); //Red
			cout << m_Block;
		}
		else 
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_CourtBackColour); //White
			cout << m_Block;
		}
		
		// increase PosX by one
		m_PosX++;

		//If PosX is 25 or larger then it will be reset and PosY will be increased by one
		if (m_PosX == m_MaxX) 
		{
			m_PosX = 0;
			m_PosY++;
		}
	}
}



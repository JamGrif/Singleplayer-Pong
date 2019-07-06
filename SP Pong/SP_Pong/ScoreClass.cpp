#include "ScoreClass.h"

ScoreClass::ScoreClass()
{
	PrintScore();
}

void ScoreClass::PrintScore()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_ScoreColour);
	coord.X = 0;
	coord.Y = m_ScoreColumn - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "===================================================" << endl;
	coord.X = m_ScoreRow;
	coord.Y = m_ScoreColumn;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "Your current score is " << m_Score << endl;
	cout << "===================================================" << endl;
}

void ScoreClass::IncreaseScore()
{
	m_Score++;
}

int ScoreClass::GetScore()
{
	return m_Score;
}

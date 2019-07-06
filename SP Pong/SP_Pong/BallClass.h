#pragma once
#include "DataReadClass.h"
#include <ctime>

class BallClass : public DataReadClass 
{
public:
	BallClass();
	void MoveBall(int PadY, int LeftX, int RightX, int UpSize, int DownSize);
	bool ShouldScoreIncrease();
	bool IsBallAlive();
	
	enum Direction
	{
		Left = -1,
		Right = 1,
		Up = -1,
		Down = 1
	};

	int m_times = 0;
private:
	//Position of the ball
	int m_XPos = 0;
	int m_YPos = 0;

	int m_XNext = 0;
	int m_YNext = 0;
	COORD coord = { 0,0 };

	//Used to determine where the balls next position is. These numbers can either be 1 or -1.
	int m_XDirection = 0;
	int m_YDirection = 0;

	//Used around main
	bool m_ScoreIncrease = false;
	int m_RandomNumber = 0;
	const char m_Block = (char)178;

	bool m_BallAlive = false;

	//Court Dimensions
	static const int m_MinX;
	static const int m_MaxX;
	static const int m_MinY;
	static const int m_MaxY;
};


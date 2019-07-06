#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
class DataReadClass
{
public:
	DataReadClass();

protected:
	//Variables read from text file. To be used in other classes 
	unsigned int m_ScoreRow = 0;
	unsigned int m_ScoreColumn = 0;
	unsigned short int m_ScoreColour = 0;

	int m_PaddleSize = 0;
	unsigned short int m_PaddleColour = 0;

	unsigned short int m_BallColour = 0;

	unsigned short int m_CourtBackColour = 0;
	unsigned short int m_CourtSideColour = 0;
};


#pragma once
#include "DataReadClass.h"

class CourtClass : public DataReadClass
{
public:
	void DrawCourt(); //Draws the court before game loop
	

private:
	//What the court will be made out of	
	const char m_Block = (char)178;
	//Used to draw the court
	int m_PosX = 0;
	int m_PosY = 0;
	//Maximum dimensions of the court
	const int m_MinX = 0;
	const int m_MaxX = 51;
	const int m_MinY = 0;
	const int m_MaxY = 26;
	
	COORD coord = { 0,0 };
};


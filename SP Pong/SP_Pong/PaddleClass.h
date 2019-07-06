#pragma once
#include "DataReadClass.h"
class PaddleClass: public DataReadClass
{
public:
	PaddleClass(int XValue, int YValue); //Constructor to set the Y value of the paddle

	void MovePaddle(char Direction); //This function takes the players input and changes the cordinates of the paddles. Paramater Direction can either be u or d (up or down).
									 //It then redraws the paddle in its new position while removing the old version of the paddle.
	int GetYPos();
	int GetXPos();

	
private:
	COORD coord = { 0,0 };
	//Position is worked out from the centre paddle block
	int m_PaddleX = 0; //X posiion of paddle
	int m_PaddleY = 0; //Y position of paddle

	int m_NextX = 0; //Used to move the paddle along the X axis
	int m_NextY = 0; //Used to move the paddle along the Y axis

	//Used to work out and draw the size of the paddles from text file
	int m_UpSize = 0;
	int m_DownSize = 0;

	const char m_Block = (char)178;
};


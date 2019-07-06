#pragma once
#include "DataReadClass.h"
class ScoreClass : public DataReadClass
{
public:
	ScoreClass();
	void PrintScore();
	void IncreaseScore();
	int GetScore();

private:
	COORD coord = { 0,0 };
	int m_Score = 0;
};


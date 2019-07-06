#include "DataReadClass.h"

DataReadClass::DataReadClass()
{
	//Open the text file
	ifstream ReadInformation;
	ReadInformation.open("GameInformation.txt");

	//Check for errors
	if (ReadInformation.fail())
	{
		cout << "Failed to read from text file, reset program." << endl;
		exit(0);
	}

	//Read values of text file and save into variables
	ReadInformation.seekg(22); //Used to set position of the read stream
	ReadInformation >> m_ScoreRow >> m_ScoreColumn >> m_ScoreColour;

	ReadInformation.seekg(50);
	ReadInformation >> m_PaddleSize >> m_PaddleColour;

	ReadInformation.seekg(68);
	ReadInformation >> m_BallColour;

	ReadInformation.seekg(89);
	ReadInformation >> m_CourtBackColour >> m_CourtSideColour;

	//Close the text file
	ReadInformation.close();




}

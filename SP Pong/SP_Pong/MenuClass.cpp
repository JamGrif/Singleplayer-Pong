#include "MenuClass.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

void MenuClass::Ask()
{
	system("CLS");
	string Menuchoice = "";
	cout << "Would you like to (P)lay the game, view (I)nstructions or (E)xit the game?" << endl;
	cin >> Menuchoice;
	ChoiceFunction(Menuchoice);
}

void MenuClass::ChoiceFunction(string MenuChoice)
{
	if (MenuChoice == "P" || MenuChoice == "p") //Starts the while loop in main essentially starting the game
	{
		m_IsGameRunning = true;
		system("CLS");
		
	}
	else if (MenuChoice == "I" || MenuChoice == "i") //Prints the game instructions and waits for the user to press a key before returning to main menu
	{
		system("CLS");
		cout << "This is a single player version of Pong. You can control your paddles by using the up and down arrow keys." << endl << endl;
		cout << "You can increase your score by hitting the ball with your paddles." << endl << endl;
		cout << "If the ball hits the different coloured wall behind your paddle, the game will end." << endl << endl;
		cout << "Press a key to return to the menu." << endl;
		_getch(); 
		Ask();
	}
	else if (MenuChoice == "E" || MenuChoice == "e") //Exits the console
	{
		exit(0); 
	}
	else //If user doesnt input a valid key then the program reasks what they want to do
	{
		Ask();
	}
}

bool MenuClass::GetIsGameRunning()
{
	return m_IsGameRunning;
}

void MenuClass::FlipGameState()
{
	if (m_IsGameRunning == true)
	{
		
		m_IsGameRunning = false;
	}
	else
	{
		m_IsGameRunning = true;
	}
}

void MenuClass::ShowConsoleCursor(bool ShowCursor) //Used to hide the cursor during play
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = ShowCursor; 
	SetConsoleCursorInfo(out, &cursorInfo);
}

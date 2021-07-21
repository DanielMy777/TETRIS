#include "io.h"


void IO::gotoxy(int x, int y) 
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	std::cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}


void IO::colorize(int c) 
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, c);
	
}


void IO::colorizeText(int c) 
{
    HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(outcon, c);

}

void IO::hidecursor(bool val)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = val;
	SetConsoleCursorInfo(consoleHandle, &info);
}


void IO::printResultHelper(bool p1lose, bool p2lose, bool tie, bool p1IsHuman, bool p2IsHuman) 
{
	IO::clrscr();
	char press;
	bool exit = false;
	IO::colorizeText(CYAN);

	std::cout << "\n\n\n\t\t\t*********************************************************************\n";

	if (tie)
		std::cout << "\t\t\t*                             it's a tie!                           *\n";

	else if (!p1lose) {

		if(p1IsHuman)
			std::cout << "\t\t\t*                     player 1 won!                                 *\n";
		else
			std::cout << "\t\t\t*                     computer player 1 won!                        *\n";

	}
		
	else{

		if (p2IsHuman)
			std::cout << "\t\t\t*                     player 2 won!                                 *\n";
		else
			std::cout << "\t\t\t*                     computer player 2 won!                        *\n";
	
	}
		

	std::cout << "\t\t\t*                                                                   *\n";
	std::cout << "\t\t\t*********************************************************************";
	IO::colorizeText(WHITE);
	std::cout << "\n\n\t\t\t\nPress ESCAPE key to go back to the menu\n";

	while (!exit)
	{
		press = _getch();
		if (press == ESCAPE)
			exit = true;
	}
	return;
}
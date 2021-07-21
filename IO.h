/* This file includes the IO (input output) class  */

#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include<string.h>
#include <iostream>
#include<windows.h>
#include <mmsystem.h>
#include <process.h>
#include <conio.h>
#include <cwchar>
#include <cstdlib> 
#include <ctime> 
#include <iomanip>
#include <typeinfo>

/* This class includes static functions which related to input and output operations */
class IO {

 public:
	
	static constexpr int ESC =-1;
	static constexpr int ESCAPE = 27;
	static constexpr int CYAN = 3;
	static constexpr int WHITE = 15;
	static constexpr int MAGNETA = 13;
	static constexpr int NUMOFSHAPES = 7;
	static constexpr int RANDBOMB = 20;
	
	/* This function recieves x and y coordinates and sets the console cursor position to be at this coordinate */
	static void gotoxy(int x, int y) ;

	/* This function clears the console screen */
	static void clrscr() { system("cls"); }

	/* This function recieves an integer which represents a color and it sets the chosen color to the output on the console (full color) */
	static void colorize(int c);

	/* This function recieves an integer which represents a color and it sets the chosen color to the output text on the console */
	static void colorizeText(int c);

	/* This function recieves a boolean value that indicates whether to hide the cursor on the
	console screen or not */
	static void hidecursor(bool val);

	/* This function recieves three boolean values indicates the game result (which player lost / it's a tie)
	and prints the result to the screen, accordingly. */
	static void printResultHelper(bool p1lose, bool p2lose, bool tie, bool p1IsHuman, bool p2IsHuman);

};


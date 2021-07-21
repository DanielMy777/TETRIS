/*This header file contains the Menu class*/

#pragma once
#include "Game.h"
#include "Settings.h"

class Menu {

	// private data memebers, functions and constExpressions:
	Game* game;
	bool inProgress = false;

	static constexpr int HUMVSHUM = 1;
	static constexpr int HUMVSCOMP = 2;
	static constexpr int COMPVSCOMP = 3;
	static constexpr int CONTINUE = 4;
	static constexpr int SETTINGS = 7;
	static constexpr int INSTRUCTIONS = 8;
	static constexpr int EXIT = 9;

	/*This function prints the menu out*/
	void printMenu() const;

	/*This functions sets a new game*/
	void newGame();

	/*This function continues a paused game*/
	void continueGame();

	/*This function shows the game's instructions on the screen*/
	void showInstructions() const;

	/*This function sets the game's settings according to the players' requests*/
	void setSettings() const;

	/*This function prints out the game's settings to the screen*/
	void printSettings() const;

	/*This function sets the computers' levels according to the players' requests*/
	void chooseLevel(bool& chosen, int cmp) const;


public:
	
	/*This function is a Menu ctor*/
	Menu() { game = nullptr; }

	//not used cpy ctor and operator =
	Menu(const Menu& other) = delete;
	Menu& operator=(const Menu& other) = delete;

	/*This function runs the game*/
	void run();

	/* This is the distructor of the class Menu; it deletes all the memory that was allocated for using this class  */
	~Menu() { if (inProgress)delete game;}

};
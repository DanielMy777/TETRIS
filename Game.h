/* This file includes the class which represents a game object */
#pragma once
#include "ComputerPlayer.h"

/* This class represents a game which contains two objects of player, one to represent each player in the game*/
class Game {

	Player* p1;
	Player* p2;

	/* This function recieves an enum MOVES value ( one of the following : {NONE,RIGHT,LEFT,CLOCK,COUNTER,DROP} )
   which represents a keyboard press by the player, and operates the right movement of the sahpe, accordingly.
   the function returns true if ESCAPE was pressed and false if not */
	bool getPress(MOVES& p1, MOVES& p2);

	/* This function recieves two boolean values indicates the game result (which player lost)
	and prints the result to the screen, accordingly.*/
	void printResult(bool p1lose, bool p2lose) const;

public:

	//not used cpy ctor and operator =
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;

	/* This function is the ctor of the game object. it creates two players with two boards, each board to one player  */
	Game();

	/* This function includes the whole course of the game, it operates the game settings on the current game,
	prints the boards, the shapes and constantly checking for lose\tie.
	it returns a boolean value that indicates whether the game is on pause (true) or ended (false) */
	bool play();

	/* This is the dtor of game class */
	~Game();
};

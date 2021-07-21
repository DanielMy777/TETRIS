/*This header file contains the Player class*/

#pragma once
#include "Board.h"

enum class MOVES { NONE, RIGHT, LEFT, CLOCK, COUNTER, DROP };//enum of moves

class Player {

	Board* players_Board;
	Shape* current_Shape;
	int shapesCounter;
	int id;

	/*This function gets a move enum and moves the players' shape accordingly*/
	void makeMove(MOVES& m);

	/*This function checks wheather a player lost the game*/
	bool checkLost() const;

	/*This function drops the players' shape to the bottomn of the board*/
	void dropShape();

public:
	static constexpr int PLAYER1 = 1;
	static constexpr int PLAYER2 = 2;

	/*This function is a player ctor that gets 3 integers*/
	Player(int x, int y, int id);

	//not used cpy ctor and operator =
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;

	/*This function gets a move enum and returns a boolean value that indicates whether the player lost in this turn*/
	int takeTurn(MOVES& move);

	/*This function prints the shape out*/
	void printShape() const { (*current_Shape).print();}

	/*This function print the players board out*/
	void printBoard() const;

	/*This function returns an integer that represents the players' current score*/
	int getScore() const { return this->players_Board->getScore(); }

	/* This function gets the current move of the player and calculates the player's best next move and returns it  */
	virtual MOVES& calcBestMove(MOVES& currMove) { return currMove; }

	/* This function gets four boolean values (indicates the levels and sets them - in human player there are not levels) */
	virtual void setLevels(bool set1, bool set2, bool set3, bool set4) { return; };
	
	/* The function returns the player's current shape */
	Shape* getCurrShape() { return current_Shape; }

	/* The function returns the player's current shape */
	Board* getPlayersBoard() { return players_Board; }

	/* This is the distructor of the class Player; it deletes all the memory that was allocated for using this class  */
	virtual ~Player() { delete players_Board; delete current_Shape;}
};
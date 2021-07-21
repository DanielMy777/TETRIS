/* This file includes the class which represents a computer player */
#pragma once
#include "Player.h"

class ComputerPlayer : public Player
{
	bool godMode;
	bool best;
	bool good;
	bool novice;
	bool fakeMove;

	/* This function gets the current move of the pc player and calculates the pc player's best next move and returns it  */
	virtual MOVES& calcBestMove(MOVES& currMove);

	/* This function gets the current good offset of the current shape from the board and it's good size (by refernce- they
	might change in the function). it calculates the best place for the pc player's curr shape and updates the ouput parameters  */
	void calcBestPlace(int& goodOffset, SIDE& goodSide);

	/* this function recieves 4 parameters, while each one of them indicates some data about the next move success,
	   we made a calculation using those parameters, in order to find the best next move, and create the best pc player.
	   the function returns the score of that specific move*/
	double calcMoveScore(int a, int b, int c,int e) const { return ((-0.510066) * (a)+(0.760666) * b + (-0.35663) * c + (-0.184483) * e); }

	/* This function returns the sum of heights (of shapes) in the computer player's board at that time.*/
	int calcHeights() { return (*this->getPlayersBoard()).getHeights(); }

	/* This function checks whether the curr move just made a tetris */
	int calcCompleteLines() { return (*this->getPlayersBoard()).didTetris(1); }

	/* This function returns how many holes there are in the computer player's board at that time */
	int calcHoles() { return (*this->getPlayersBoard()).getHoles(); }

	/* This function returns how many vallies there are in the player's board at that time */
	int calcValley() { return (*this->getPlayersBoard()).getValley(); }

	/* This function recieves a pointer to a shape and makes it settle in the right place in the board (dropping it straight until reaching the bottom) */
	void dropShape(Shape* sh);

	/* This function checks whether it's the time to generate a fake move */
	void generateFakeMove();

	/* This function generates a fake move */
	void generateMiss(int& i, SIDE& s);

	/* This function gets four boolean values (indicates the levels of the computer player and sets them ) */
	virtual void setLevels(bool _novice, bool _good, bool _best, bool _godMode);


public:

	static constexpr int INITPOS = 6;

	/* this is the ctor of computer player */
	ComputerPlayer(int x, int y, int id) : Player(x, y, id), godMode(false), fakeMove(false), best(false),good(false),novice(false){}
	
};
/* This file includes the class which represents a board object */
#pragma once
#include "Shape.h"

/* This class represents a board (it's x,y starting coordinate, a matrix of block object and a player's score)*/
class Board {

	Block** board;
	Block start;
	int score;

	/* this function recieves an integer representing a row number and clears this row and lowers the blocks above it*/
	void lowerBlocks(int row);

public:
	static constexpr int HEIGHT = 18;
	static constexpr int WIDTH = 12;
	static constexpr int STARTX1 = 5;
	static constexpr int STARTY1 = 5;
	static constexpr int STARTX2 = 40;
	static constexpr int STARTY2 = 5;

	
	/* this is a board's ctor that recieves the start block x and y coordinates (blocks that represents the starting block of the board)
	and sets them to be the current board stating point. 
	the function creates a board accordingly */
	Board(int x, int y);

	//not used cpy ctor and operator =
	Board(const Board& other)=delete;
	
	Board& operator=(const Board& other) = delete;

	/* this function returns a reference to the board start point (represented by a BLOCK object) */
	Block& getStart() { return start; }

	/* This function prints the player's board , with it's filled/ not filled blocks */
	void printBoard() const;

	/* This function initializes the board ( sets all it's inner blocks (inside the boards frame) to be unfilled  */
	//void initBoard();

	/* This function recieves a pointer to shape and sets the board to be filled with that shape, at the right location  */
	void fillBoard(Shape* shape);

	/*  this function recieves a pointer to a shape and presents it on the right position in the board
	the function returns true if the shape was able to settle and false otherwise */
	bool checkHit(Shape& s) const;

	/* this function handles the case of the player's tetris (full line completed) */
	int didTetris(bool dry);

	/* this function returns the score of the player's on the cuurent board */
	int getScore() const { return score; }

	/* this function recieves a number and updates the score as a sum of the old score and the new number recieved */
	void addScore(int sum) { score += sum; }

	/* This function recieves array of blocks which represents a bomb shape
	   and makes the bomb explode (clears all 9*9 square around it)*/
	void explode(Block* coords);

	/* This function recieves a reference to a block which represents a bomb and counts how many
       shapes are around the position of the bomb and returns the value of the counted shapes */
	int shapesAround(const Block& bomb) const;

	/* This funtion returns the board as a Block** array */
	Block** getBoard() const { return board; }

	/* This function counts and returns how many holes there are in the board at that time */
	int getHoles() const;

	/* This function counts and returns the sum of heights in the board at that time.*/
	int getHeights() const;

	/* This function counts and returns how many vallies there are in the board at that time */
	int getValley() const;

	/* This function recieves a pointer to a shape and clears it from the board */
	void unFillBoard(Shape* shape);


	/* This function recieves a pointer to a shape and checkes whether that shape's coordinates
	   are inside the board brders. the function returns the appropriate boolean value */
	bool inBoard(Shape* s) const;

	/* This is the distructor of the class Board; it deletes all the memory that was allocated for using this class  */
	~Board();
};
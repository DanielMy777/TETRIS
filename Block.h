/* This file includes the class which represents a block object */

#pragma once
#include "io.h"

/* This class represents a block on the board (it's x coordinate, y coordinate and boolean fiels indicates whether it's filled or not)*/
class Block {
	int x = 0; // block's x coordinate
	int y = 0; // block's y coordinate
	bool filled = false; // block's filled field
	
public:
	static constexpr char ASCIIBLOCK = (char)219u;
	static constexpr int SIZE = 4;
	
	/* this is the  default ctor of block*/
	Block() = default; 

	/* this is block ctor that recieves x and y coordinates and a boolean value and sets them to the current block*/
	Block(int _x, int _y, bool _filled = false) { x = _x; y = _y; filled = _filled; } 


	/* this function returns the x coordinate of the current block */
	int getX() const { return x; } 

	/* this function returns the y coordinate of the current block */
	int getY() const { return y; } 

	/* this function returns the filled value of the current block */
	bool getFilled() const { return filled; } 

	/* this function recieves x coordinate and updates it to be the x coordinate of the current block */
	void setX(int _x) { x = _x; } 

	/* this function recieves y coordinate and updates it to be the y coordinate of the current block */
	void setY(int _y) { y = _y; } 

	/* this function recieves filled value and updates it to be the filled value of the current block */
	void setFilled(bool _filled) { filled = _filled;}  

	/* This function prints a point which is specific (x,y) coordinate as a block (full square, if filled) and as " " (if not filled) */
	void printBlock () const;

	/* This function defines the operator " = " between two blocks.
	it recieves a block object and creates a new block with the same values of the recieved one.
	the function returns the new block*/
	Block& operator=(const Block& other) = default; 

	/* This function defines the operator " += " between two blocks.
	it recieves a block object and adds the x value of the recieved block to the current block's x value
	and the same with it's y value*/
	void operator+=(const Block& other) { x = x + other.x;y = y + other.y;}

	/* This function defines the operator " += " between a block and an integer.
	it recieves recieves an integer and adds the value of the recieved integer to the current block's x value */
	void operator+=(int x) { this->x += x; }

	/* This function defines the operator " ++ " on a block object.
	This function adds 1 to the y value of the current block */
	void operator++(int) { y = y + 1; }

	/* This function defines the operator " -- " on a block object.
	This function decreases 1 from the y value of the current block */
	void operator--(int) { y = y - 1; }

	/* This function recieves a block object and defines the operator " == " between two blocks.
	it checks whether their x and y values are equal
	and returns an apropriate boolean value */
	bool operator==(const Block& other) const;

};
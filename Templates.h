/*This header file contains the templates class*/

#pragma once
#include "Block.h"
enum class SIDE { UP, RIGHT, DOWN, LEFT }; //enum of sides

class Templates {
public:
	/*This function gets a SIDE enum and returns a Block that represent the cubic shape in the game*/
	static Block* getO(const SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the S shape in the game*/
	static Block* getS(const SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the Z shape in the game*/
	static Block* getZ(const SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the T shape in the game*/
	static Block* getT(const SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the J shape in the game*/
	static Block* getJ(const SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the L shape in the game*/
	static Block* getL(const SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the I shape in the game*/
	static Block* getI(const SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the Bomb shape in the game*/
	static Block* getB(const SIDE& side) { Block* blocks = new Block[Block::SIZE]; return blocks; }

};
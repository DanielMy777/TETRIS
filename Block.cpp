#include "Block.h"


void Block::printBlock () const
{
	if (filled)
	{
		IO::gotoxy(x, y);
		std::cout << ASCIIBLOCK; // print a block in ascii 
	}
	else
	{
		IO::gotoxy(x, y);
		std::cout << " ";
	}
}

bool Block::operator==(const Block& other) const
{
	return ((this->y == other.y) && (this->x == other.x));
}
#include "Board.h"



Board::Board(int x, int y) :start(x, y, false) {

	this->score = 0;
	int i,j;
	int currx, curry;
	board = new Block * [HEIGHT+1];
	for (i = 0,curry=start.getY(); i < HEIGHT+1; i++)
	{
		board[i] = new Block[WIDTH+2];
		for (j = 0,currx = start.getX(); j < WIDTH+2; j++)
		{
			board[i][j].setX(currx + j);
			board[i][j].setY(curry + i);
		}
	}

	for (i = 0; i < HEIGHT+1; i++)
	{
		board[i][0].setFilled(true);
	}

	for (i = 0; i <WIDTH+2; i++)
	{
		board[HEIGHT][i].setFilled(true);
	}

	for (i = 0; i < HEIGHT+1; i++)
	{
		board[i][WIDTH+1].setFilled(true);
	}

}


void Board::printBoard() const
{
	for (int i = 0; i < HEIGHT + 1; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			board[i][j].printBlock();
		}
	}
}



void Board::fillBoard(Shape* shape)
{
	int bx, by, x, y;
	if (!inBoard(shape))
		return;
	for (int i = 0; i < Block::SIZE; i++)
	{
		x = (*shape)[i].getX();
		y = (*shape)[i].getY();
		bx = x - this->start.getX();
		by = y - this->start.getY();
		board[by-1][bx].setFilled(true);
	}
	if (shape->getKind() == SHAPES::B)
		board[by - 1][bx].setFilled(false);

}

bool Board::checkHit(Shape& s) const
{
	for (int i = 0; i < Block::SIZE; i++)
	{
		int xoffset = (s)[i].getX() - this->start.getX();
		int yoffset = (s)[i].getY() - this->start.getY();
		if (board[yoffset][xoffset].getFilled())
			return false;
	}
	return true;
}


int Board::shapesAround(const Block& bomb) const
{
	int count = 0;
	int xoffset = bomb.getX() - this->start.getX();
	int yoffset = bomb.getY() - this->start.getY();
	for (int i = xoffset-Block::SIZE; i < xoffset+ Block::SIZE; i++)
	{
		for (int j = yoffset - Block::SIZE; j < yoffset + Block::SIZE; j++)
		{
			if (j<1 || j >HEIGHT || i<1 || i>WIDTH)
				continue;
			if (board[j - 1][i].getFilled())
				count++;
		}
	}
	return count;
}


int Board::didTetris(bool dry) 
{
	bool flag = true;
	int amount = 0;
	for (int i = HEIGHT-1; i >= 0; i--,flag=true)
	{
		for (int j = 0; j < WIDTH + 1; j++)
		{
			if (!(this->board[i][j].getFilled()))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (!dry)
			{
				lowerBlocks(i);
				i--;
			}
			amount++;
		}
	}
	if(amount != 0 && !dry) //had a tetris
		addScore(100 * pow(2, amount-1));
	return amount;
}


void Board::lowerBlocks(int row)
{
	for (int i = row; i >= 1; i--)
	{
		for (int j = 1; j < WIDTH + 1; j++)
		{
			this->board[i][j].setFilled(this->board[i - 1][j].getFilled());
		}
	}

	for (int i = 1; i < WIDTH + 1; i++)//clear top row
	{
		this->board[0][i].setFilled(false);
	}
}


void Board::explode(Block* coords)
{
	int xoffset = (coords)[0].getX() - this->start.getX();
	int yoffset = (coords)[0].getY() - this->start.getY();
	board[yoffset - 1][xoffset].setFilled(false);

	for (int i = yoffset - Block::SIZE; i <= yoffset + Block::SIZE; i++)
	{
		for (int j = xoffset - Block::SIZE; j <= xoffset + Block::SIZE; j++)
		{
			if (i<1 || i >HEIGHT || j<1 || j>WIDTH)
				continue;
			this->board[i - 1][j].setFilled(false);
		}
	}

}

void Board::unFillBoard(Shape* shape)
{
	int bx, by, x, y;
	if (!inBoard(shape))
		return;
	for (int i = 0; i < Block::SIZE; i++)
	{
		x = (*shape)[i].getX();
		y = (*shape)[i].getY();
		bx = x - this->start.getX();
		by = y - this->start.getY();
		board[by - 1][bx].setFilled(false);
	}
}


bool Board::inBoard(Shape* s) const
{
	for (int i = 0; i < Block::SIZE; i++)
	{
		int xoffset = (*s)[i].getX() - this->start.getX();
		int yoffset = (*s)[i].getY() - this->start.getY();
		if (xoffset < 1 || xoffset > WIDTH || yoffset <= 0)
			return false;
	}
	return true;
}


int Board::getHoles() const
{
	int sum = 0;
	bool up;
	for (int i = HEIGHT; i >= 1; i--)
	{
		for (int j = 1; j < WIDTH; j++)
		{
			if (!(this->board[i][j].getFilled()))
			{
				up = this->board[i - 1][j].getFilled();
				if (up)
					sum++;
			}
		}
	}
	return sum;
}

int Board::getHeights() const
{
	int sum = 0;
	for (int i = 1; i < WIDTH + 1; i++)
	{
		int currHeight = 0;
		for (int j = HEIGHT; j > 0; j--)
		{
			if (this->board[j][i].getFilled())
				if (currHeight < HEIGHT - j)
					currHeight = HEIGHT - j;
		}
		sum += currHeight;
	}
	return sum;
}

int Board::getValley() const
{
	int sum = 0;
	int currcol = 0, prevcol = 0;
	for (int i = 1; i < WIDTH + 1; i++)
	{
		prevcol = currcol;
		currcol = 0;
		for (int j = HEIGHT; j > 0; j--)
		{
			if (this->board[j][i].getFilled())
				if (currcol < HEIGHT - j)
					currcol = HEIGHT - j;
		}
		if (i != 1)
			sum += abs(prevcol - currcol);
	}
	return sum;
}

Board::~Board()
{
	for(int i=0;i< HEIGHT+1;i++)
		delete[] board[i];

	delete[] board;
}
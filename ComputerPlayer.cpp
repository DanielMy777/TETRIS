#include "ComputerPlayer.h"
#include"Board.h"


 void ComputerPlayer:: setLevels(bool _novice, bool _good, bool _best, bool _godMode) {
	 good = _good;
	 novice = _novice;
	 best = _best;
	 godMode = _godMode;

}
MOVES& ComputerPlayer::calcBestMove(MOVES& currMove) 
{
	MOVES m = currMove;
	static int goodOffset = INITPOS;
	static SIDE goodSide = SIDE::UP;
	if (this->getCurrShape()->getCoords()[0].getY() - 1 == this->getPlayersBoard()->getStart().getY())
	{
		fakeMove = false;
		goodOffset = INITPOS;
		goodSide = SIDE::UP;
		generateFakeMove();
	}
	if (!fakeMove)
		calcBestPlace(goodOffset, goodSide);
	else
		generateMiss(goodOffset, goodSide);

	if ((((*this->getCurrShape()).getSide() + 1) % Block::SIZE == (int)goodSide))
		m = MOVES::CLOCK;

	else if ((*this->getCurrShape()).getSide() != (int)goodSide)
		m = MOVES::COUNTER;

	else if ((*this->getCurrShape()).getPlace() - (*this->getPlayersBoard()).getStart().getX() > goodOffset)
		m = MOVES::LEFT;

	else if ((*this->getCurrShape()).getPlace() - (*this->getPlayersBoard()).getStart().getX() < goodOffset)
		m = MOVES::RIGHT;

	else
	{
		if (godMode)
			m = MOVES::DROP;
		else
			m = MOVES::NONE;
	}

	currMove = m;
	return currMove;
}

void ComputerPlayer::calcBestPlace(int& goodOffset, SIDE& goodSide)
{
	int a, b, c,e;
	double currScore = 0, bestScore = -FLT_MAX;
	for (int i = 0; i < Board::WIDTH+2; i++)
	{
		for (int k = 0; k < Block::SIZE; k++)
		{
			Block tmp_block = { i ,0 };
			SIDE currSide = (SIDE)k;
			Shape* tmp_shape = new Shape((*this->getCurrShape()).getKind(), currSide);
			(*tmp_shape) += (*this->getPlayersBoard()).getStart();
			(*tmp_shape) += tmp_block;
			dropShape(tmp_shape);
			if (!(*this->getPlayersBoard()).inBoard(tmp_shape))
			{
				delete tmp_shape;
				continue;
			}
				
			if (tmp_shape->getKind() != SHAPES::B)
			{
				(*this->getPlayersBoard()).fillBoard(tmp_shape);
				a = calcHeights();
				b = calcCompleteLines();
				c = calcHoles();
				e = calcValley();
				currScore = calcMoveScore(a, b, c, e);
				(*this->getPlayersBoard()).unFillBoard(tmp_shape);
			}
			else //bomb
			{
				currScore = this->getPlayersBoard()->shapesAround(tmp_shape->getCoords()[0]);
				k = 3; //break
			}
			if (currScore > bestScore)
			{
				goodOffset = i;
				goodSide = (SIDE)k;
				bestScore = currScore;
			}
			delete tmp_shape;
		}
	}
}

void ComputerPlayer::generateFakeMove()
{
	if (good)
	{
		int x = rand() % 200;
		if (x >= 0 && x <= 4) //chance of 5% to happen
		{
			fakeMove = true;
		}
	}
	else if (novice) 
	{
		int x = rand() % 10; 
		if (x == 1) // chance of 10% to happen 
		{
			fakeMove = true;
		}
	}
}

void ComputerPlayer::generateMiss(int& i, SIDE& s)
{
	if (i == INITPOS && s == SIDE::UP) //the move is initialized
	{
		i = (rand() % Board::WIDTH) + 1;  // generate position on the board
		s = (SIDE)(rand() % Block::SIZE); // generate side 
  	}
}

void ComputerPlayer::dropShape(Shape* sh)
{
	bool stop = false;
	while (!stop)
	{
		(*sh)++;
		stop = !(this->getPlayersBoard()->checkHit(*sh));
	}
}


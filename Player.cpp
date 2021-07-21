#include "Player.h"


Player::Player(int x, int y, int id)
{
	SHAPES shape;
	srand((unsigned)time(0)); // make rand function reset every second 
	players_Board = new Board(x, y); 
	int rando = (rand() % IO::NUMOFSHAPES) + 1;
	shape = (SHAPES)rando;

	SIDE side = SIDE::UP;
	current_Shape = new Shape(shape,side);
	(*current_Shape) += (*players_Board).getStart(); // set the shape to be on the board
	(*current_Shape)++;
	(*current_Shape).randomizePos(); // randomize position to drop the shape from the top of the board
	players_Board->printBoard();
	this->id = id;
}


int Player::takeTurn(MOVES& move)
{
	(*current_Shape).clear();
	makeMove(move);
	bool stop = !(this->players_Board->checkHit(*current_Shape));
	SHAPES shape;

	if (stop)
	{
		if (checkLost())
			return 1; //return 1 if lost

		players_Board->fillBoard(current_Shape);
		if ((*this->current_Shape).getKind() == SHAPES::B)
			(*this->players_Board).explode((*this->current_Shape).getCoords());
		else
		players_Board->didTetris(0);

		players_Board->addScore(10);
		printBoard();
		delete current_Shape;
		
		int rando = (rand() % IO::NUMOFSHAPES) + 1;
		int randBomb = rand() % IO::RANDBOMB;

		if (randBomb == 0) // %5 chance for a bomb
		{
			shape = (SHAPES)randBomb;
		}
		else
			shape = (SHAPES)rando;
		
		SIDE side = SIDE::UP;
		current_Shape = new Shape(shape, side);
		(*current_Shape) += (*players_Board).getStart();
		(*current_Shape)++;
		(*current_Shape).randomizePos();
	}

	return 0; 
}

void Player::printBoard() const
{
	int xstart = this->players_Board->getStart().getX();
	int ystart = this->players_Board->getStart().getY();
	IO::gotoxy(xstart + 3, ystart - 3);
	std::cout << "Player " << this->id;
	this->players_Board->printBoard();
	if (Settings::getScore())
	{
		IO::gotoxy(xstart + 3, ystart + 20);
		std::cout << "Score: " << this->players_Board->getScore();
	}

}

void Player::makeMove(MOVES& m)
{
	Block b(-1, 0);
	Shape old = *(this->current_Shape);
	switch (m)
	{
	case MOVES::COUNTER:
		this->current_Shape->turnLeft();
		break;
	case MOVES::CLOCK:
		this->current_Shape->turnRight();
		break;
	case MOVES::LEFT:
		(*(this->current_Shape)) += b;
		break;
	case MOVES::RIGHT:
		b.setX(1);
		(*(this->current_Shape)) += b;
		break;
	case MOVES::DROP:
		dropShape();
		(*this->current_Shape)--;
		break;
	default:
		break;
	}
	if (!(this->players_Board->checkHit(*(this->current_Shape))))
	{
		*(this->current_Shape) = old;
	}

	(*this->current_Shape)++;
}

bool Player::checkLost() const
{
	int boundry = this->players_Board->getStart().getY();
	boundry++;
	for (int i = 0; i < Block::SIZE; i++)
	{
		if ((*this->current_Shape)[i].getY() <= boundry)
			return true;
	}
	return false;
}

void Player::dropShape()
{
	bool stop = false;
	while (!stop)
	{
		(*current_Shape)++;
		stop = !(this->players_Board->checkHit(*current_Shape));
	}
}

#include "Shape.h"
#include "Board.h"




Shape::Shape(const SHAPES& _kind, const SIDE& _side)
{

	coords = getShape(_kind, _side);
	kind = _kind;
	side = _side;
}

Shape::Shape(const Shape& other) : Shape()
{
	
	if (this == &other)
	{
		return;
	}
	delete[] this->coords;
	(*this) = other;
	
}
Block* Shape::getShape(const SHAPES& _kind, const SIDE& _side) const
{
	Block* tmp = nullptr;
	switch (_kind)
	{
	case SHAPES::I:
		tmp = Templates::getI(_side);
		break;
	case SHAPES::Z:
		tmp = Templates::getZ(_side);
		break;
	case SHAPES::O:
		tmp = Templates::getO(_side);
		break;
	case SHAPES::L:
		tmp = Templates::getL(_side);
		break;
	case SHAPES::T:
		tmp = Templates::getT(_side);
		break;
	case SHAPES::J:
		tmp = Templates::getJ(_side);
		break;
	case SHAPES::S:
		tmp = Templates::getS(_side);
		break;
	case SHAPES::B:
		tmp = Templates::getB(_side);
		break;
	default:
		break;
	}
	return tmp;
}

void Shape::print() const
{
	if (Settings::getColors())
		IO::colorize((int)this->kind+1);
	for (int i = 0; i < Block::SIZE; i++)
	{
		IO::gotoxy(coords[i].getX(), coords[i].getY());
		std::cout << Block::ASCIIBLOCK;
	}
	IO::colorize(IO::WHITE);

}

void Shape::clear() const
{
	for (int i = 0; i < Block::SIZE; i++)
	{
		IO::gotoxy(coords[i].getX(), coords[i].getY());
		std::cout << " ";
	}
}


void Shape::operator+=(const Block& other)
{
	for (int i = 0; i < Block::SIZE; i++)
	{
		coords[i] += other;
	}
}

void Shape::randomizePos()
{
	int offset = rand() % ((Board::WIDTH) - 2);
	offset += 2;
	for (int i = 0; i < Block::SIZE; i++)
	{
		coords[i] += offset;
	}
}

void Shape::operator++(int)
{
	for (int i = 0; i < Block::SIZE; i++)
	{
		(coords[i])++;
	}
}

void Shape::operator--(int)
{
	for (int i = 0; i < Block::SIZE; i++)
	{
		(coords[i])--;
	}
}

bool Shape::operator==(const Block& other) const
{
	for (int i = 0; i < Block::SIZE; i++)
	{
		if (coords[i].getY() == other.getY())
		{
			return true;
		}
	}
	return false;
}

Shape& Shape::operator=(const Shape& other)
{
	this->kind = other.kind;
	this->side = other.side;
	if (coords)
		delete[] coords;
	coords = new Block[Block::SIZE];
	for (int i = 0; i < Block::SIZE; i++)
	{
		this->coords[i] = other.coords[i];
	}
	return *this;
}


void Shape::turnLeft() {

	int s = (int)this->side;// getting the right SIDE enum to turn the shape
	s = (s - 1) % Block::SIZE;
	if (s < 0)
		s = Block::SIZE + s;
	SIDE side = (SIDE)s;
	rotate(side);
}
void Shape::turnRight() {

	int s = (int)this->side;//getting the right SIDE enum to turn the shape
	s = (s + 1) % Block::SIZE;
	SIDE side = (SIDE)s;
	rotate(side);
}

void Shape::rotate(const SIDE& newSide)
{
	int xcontrol, ycontrol;
	xcontrol = coords[0].getX();//every shape holds a pivot coordinates in coords[0] and the shape rotates according to it
	ycontrol = coords[0].getY();
	delete[] coords;
	coords = getShape(this->kind, newSide);
	xcontrol = xcontrol - coords[0].getX();
	ycontrol = ycontrol - coords[0].getY();
	for (int i = 0; i < Block::SIZE; i++)
	{
		coords[i].setX(coords[i].getX() + xcontrol);
		coords[i].setY(coords[i].getY() + ycontrol);
	}
	this->side = newSide;
}

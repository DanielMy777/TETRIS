/*This header file contains the shapes class */

#pragma once
#include "Templates.h"
#include "Settings.h"


enum class SHAPES {B, I , Z, O, L, T, J, S }; //enum of shapes 

class Shape {
	
	Block* coords;
	SHAPES kind;
	SIDE side;


public:
	/*This function is the default shape ctor*/
	Shape() :coords (nullptr),kind(SHAPES::I),side (SIDE::UP) {};

	/*This function is a ctor that gets 2 enums that represent the side and kind of shape to be constructed*/
	Shape(const SHAPES& _kind, const SIDE& _side);

	/*This function is a copy ctor that gets a shape by ref and copies its' values to another shape*/
	Shape(const Shape& other);

	/*This function ptints out a shape */
	void print() const;

	/*This function delets the shape from the screen*/
	void clear() const;

	/*This functions sets a random position to the shape on the screen*/
	void randomizePos();

	/*This function gets 2 enums and returns an array of blocks that represent the wanted shape*/
	Block* getShape(const SHAPES& _kind, const SIDE& _side) const;

	/*This function gets a Block by ref and performs the += operator on a Shape */
	void operator+=(const Block& other);

	/*This function gets an integer and performs the ++ operator on a Shape */
	void operator++(int);

	/*This function gets an integer and performs the -- operator on a Shape */
	void operator--(int);

	/*This function gets a Block by ref and performs the == operator on a Shape */
	bool operator==(const Block& other) const;

	/*This function gets a const Shape ref and performs the = operator on a Shape */
	Shape& operator=(const Shape& other);

	/*This function gets an integer and performs the [] operator on a Shape */
	Block& operator[](int i) { return this->coords[i]; }

	/*This function changes the Shapes' coords and moves it to the left*/
	void turnLeft();

	/*This function changes the Shapes' coords and moves it to the right*/
	void turnRight();

	/*This function gets an enum and rotates the Shape to the wanted side*/
	void rotate(const SIDE& newSide);

	/* this function returns the kind of the current shape (this->kind) */
	SHAPES& getKind() { return kind; }

	/* this function returns the coords array of the current shape (this->coords) */
	Block* getCoords() { return coords; }

	/* this function returns the first element's x value (the pivot's x value) in the coords array of the current shape */
	int getPlace() const { return coords[0].getX(); }

	/* this function returns the side of the current shape (this->side) */
	int getSide() const { return (int)side; }

	/* This is the distructor of the class Shape; it deletes all the memory that was allocated for using this class  */
	~Shape() { delete[] coords; }
};
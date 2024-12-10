#include "Rectangle.h"
#include <iostream>
#include "framework.h"

// Defines a rectangle
Rectangle::Rectangle(int gScreenWidth, int gScreenHeight)
{
	moveRectangleX = rand() % gScreenWidth / 2 + gScreenWidth / 4;
	moveRectangleY = rand() % gScreenHeight / 2 + gScreenWidth / 4;

	width = rand() % 20 + 5;
	height = rand() % 20 + 5;

	std::cout << "Rectangle Constructed" << std::endl;
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle Destructed" << std::endl;
}

// Creates a rectangle
void Rectangle::Draw()
{
	// Draws a circle at 100,200 with radius 20
	DrawRectangle(moveRectangleX, moveRectangleY, width, height);
}
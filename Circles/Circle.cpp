#include "Circle.h"
#include <cstdlib>
#include <iostream>
#include "framework.h"

// Defines a circle
Circle::Circle(int gScreenWidth, int gScreenHeight, int speed)
{
	moveCircleX = rand() % gScreenWidth / 2 + gScreenWidth / 4;
	moveCircleY = rand() % gScreenHeight / 2 + gScreenWidth / 4;
	radius = rand() % 20 + 5;

	xDir = rand() % speed - 5;
	yDir = rand() % speed - 5;

	red = 255;
	green = 0;
	blue = 0;
	alpha = 255;

	std::cout << "Circle Constructed" << std::endl;
}

Circle::~Circle()
{
	std::cout << "Circle Destructed" << std::endl;
}

// Causes the circle to bounce and duplicate if it hits the sides of the screen
void Circle::Update(int gScreenWidth, int gScreenHeight, int speed)
{
	// Causes the circles to move
	moveCircleX = moveCircleX + xDir;
	moveCircleY = moveCircleY + yDir;

	if (moveCircleX > gScreenWidth - radius * 2 || moveCircleX < 0)
	{
		xDir *= -1;

		/*Circle newCircle;
		circles.push_back(newCircle);*/

		// Sets the circles colour to a random value
		//ChangeColour(rand() % 256, rand() % 256, rand() % 256);
	}

	if (moveCircleY > gScreenHeight - radius * 2 || moveCircleY < 0)
	{
		yDir *= -1;

		/*Circle newCircle;
		circles.push_back(newCircle);*/

		// Sets the circles colour to a random value
		//ChangeColour(rand() % 256, rand() % 256, rand() % 256);
	}

	// Inverts direction once a random number is equal
	int randNum = rand() % 100;
	if (randNum == 50)
	{
		xDir *= -1;
		yDir *= -1;
	}

	// Checks if the left mouse button is pressed, and moves all circles to its location if it is
	if (IsButtonPressed(EButton::eLeft))
	{
		GetMousePosition(moveCircleX, moveCircleY);
	}
}

// Creates a circle
void Circle::Draw()
{
	// Draws a circle at 100,200 with radius 20
	DrawCircle(moveCircleX, moveCircleY, radius);
	ChangeColour(red, green, blue, alpha);
}
#pragma once
// Class defining a rectangle
class Rectangle
{
private:
	// Variables
	int width;
	int height;

	int moveRectangleX;
	int moveRectangleY;
public:
	// Constructors
	Rectangle(int gScreenWidth, int gScreenHeight);
	~Rectangle();

	void Draw();
};


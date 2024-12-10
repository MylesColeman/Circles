#pragma once
// Class defining a circle
class Circle
{
private:
	// Variables
	int radius;

	int xDir;
	int yDir;

	int red;
	int green;
	int blue;
	int alpha;

	int moveCircleX;
	int moveCircleY;
public:
	// Constructors
	Circle(int gScreenWidth, int gScreenHeight, int speed);
	~Circle();

	void Update(int gScreenWidth, int gScreenHeight, int speed);
	void Draw();
};
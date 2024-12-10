#include <iostream>
#include "Framework.h"

#include <vector>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;
// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

int speed = 10;

int main()
{
	srand(time(NULL));

	const int numCircles = 1;
	
	// Creating a vector of our circles and rectangles
	vector<Circle> circles;
	vector<Rectangle> rectangles;
	
	{

		Circle newCircle(gScreenWidth, gScreenHeight, speed);
		circles.push_back(newCircle);
	}

	{
		Rectangle newRectangle(gScreenWidth, gScreenHeight);
		rectangles.push_back(newRectangle);
	}

	std::cout << "Hello circles" << endl;

	while(UpdateFramework())
	{
		// Calls the functions to be used later
		bool IsButtonPressed(EButton whichButton);
		void GetMousePosition(int &x, int &y);
			
		// Iterates through the circles vector
		for (auto &p : circles)
		{
			p.Draw();
			p.Update(gScreenWidth, gScreenHeight, speed);

			// Checks if the right mouse button is pressed, and creates another circle if it is
			bool createCircle = false;
			while (IsButtonPressed(EButton::eRight))
			{
				createCircle = true;
			}
			if (createCircle)
			{
				Circle newCircle(gScreenWidth, gScreenHeight, speed);
				circles.push_back(newCircle);

				createCircle = false;
			}
		}

		for (auto& p : rectangles)
		{
			p.Draw();
		}
	}
	std::cout << "Bye bye" << endl;

	return 0;
}
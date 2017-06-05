#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Point
{
	float x, y;
public:
	Point()
	{

	}

	Point(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};

struct Circle
{
	Point position;
	float radius;
public:
	Circle()
	{
		position = Point(0, 0);
	}

	Circle(float x, float y, float r)
	{
		position = Point(x, y);
		radius = r;
	}

	bool Contains(Point p)
	{
		float xSquare = pow(p.x - position.x, 2);
		float ySquare = pow(p.y - position.y, 2);
		float rSquare = pow(radius, 2);
		return xSquare + ySquare <= rSquare;
	}
};

int main()
{
	Circle circle(5, 3, 2);
	Point p(5, 0);
	cout << circle.Contains(p) << endl;
	return 0;
}
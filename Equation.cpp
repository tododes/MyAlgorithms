#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Point
{
public:
	float x;
	float y;
	Point(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};

class Equation2
{
private:
	
public:
	float kx;
	float ky;
	float konst;

	Equation2(float _kx, float _ky, float _ko)
	{
		kx = _kx;
		ky = _ky;
		konst = _ko;
	}

	Equation2& operator +(Equation2 b)
	{
		kx += b.kx;
		ky += b.ky;
		konst += b.konst;
		return *this;
	}

	Equation2& operator -(Equation2 b)
	{
		kx -= b.kx;
		ky -= b.ky;
		konst -= b.konst;
		return *this;
	}

	Equation2& operator *(int e)
	{
		kx *= e;
		ky *= e;
		konst *= e;
		return *this;
	}

	Equation2& operator /(int e)
	{
		kx /= e;
		ky /= e;
		konst /= e;
		return *this;
	}

	Point getResultWithX(float v)
	{
		konst += kx * v;
		Equation2 e(0, ky, konst);
		return Point(v, -1.0f * konst / ky);
	}

	Point getResultWithY(float v)
	{
		konst += ky * v;
		Equation2 e(kx, 0, konst);
		return Point(-1.0f * konst / kx, v);
	}

};

Equation2 Line1(int x1, int y1, int x2, int y2)
{
	Equation2 e1(0, 1, -y1);
	Equation2 e2(1, 0, -x1);
	e2 = e2 * ((y1 - y2) / (x1 - x2));
	e2 = e2 + (e1 * -1);
	return e2;
}

Point getIntersectionPoint(Equation2 a, Equation2 b)
{
	Equation2 tempA = Equation2(0, 0, 0);
	Equation2 tempB = Equation2(0, 0, 0);

	tempA.kx = a.kx / (-1.0f * a.ky);
	tempA.ky = 0.0f;
	tempA.konst = a.konst / (-1.0f * a.ky);

	tempB.kx = b.kx / (-1.0f * a.ky);
	tempB.ky = 0.0f;
	tempB.konst = b.konst / (-1.0f * a.ky);
	
	tempA = tempA - tempB;
	tempA.konst /= -1.0f * tempA.kx;

	Point p = a.getResultWithX(tempA.konst);
	return p;
}

int main()
{
	Equation2 e1 = Equation2(1, -1, 1);
	Equation2 e2 = Equation2(-5, -1, 3);
	Point p = getIntersectionPoint(e1, e2);
	return 0;
}
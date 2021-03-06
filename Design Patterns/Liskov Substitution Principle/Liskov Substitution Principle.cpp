// Liskov Substitution Principle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Rectangle
{
protected:
	int width;
	int height;
public:
	Rectangle(int width, int height):width(width),height(height)
	{
	}
	int area()
	{
		return width * height;
	}

	virtual void setWidth(int w)
	{
		width = w;
	}

	virtual void setHeight(int h)
	{
		height = h;
	}

	int getWidth()
	{
		return width;
	}

	int getHeight()
	{
		return height;
	}

};

class Square: public Rectangle
{
public:
	Square(int size) : Rectangle(size, size) {};



	 

	void setWidth(int w) override
	{
		this->width = this->height = w;
	}
	void setHeight(int h) override
	{
		this->width = this->height = h;
	}

};
void  process(Rectangle &r)
{
	int w= r.getWidth();
	r.setHeight(10);

	cout << "Expected output :" << w * (10) << endl;
	cout << "Actual output :" << r.area() << endl;
	cout << "---------------------------" << endl;

}
int main()
{
    cout << "Liskov Substitution Principle!\n";

	/*If you have a function that takes a base class,
	then any derived class should be able to be substituted without any problem  */

	Rectangle r(3, 4);
	process(r);

	Square sq(5);	// The following violates the Liskov Substitutional principle

	process(sq);

}
// Inheriting a Square from a Rectangle is not the best idea

// In terms of the language a square is in fact a rectangle so you can say a square should inherit from rectangle because it is such.

//But you could do it differently.

//So for example you could just keep rectangles and have a rectangle with a boolean flag indicating whether it's square or not.

// But You can fix this my creating a factory for Rectangle and square
// Both should return a Rectangle

class RectangleFactory
{
public:
	static Rectangle createRectangle(int w, int h);
	static Rectangle createSquare(int size);
};




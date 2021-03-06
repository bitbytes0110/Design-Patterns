// Open Close Principle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>


using namespace std;

enum Color { red, green, blue };
enum Size {small, medium, large};

class Product
{
public:
	Product(string name, Color color, Size size) :name(name), color(color), size(size) {};
	string name;
	Color color;
	Size size;

	friend ostream& operator<<(ostream& os, const vector<Product*>& product);
};

class ProductFilter
{
public:
	ProductFilter() = default;
	~ProductFilter() = default;

	vector <Product*> Result;

	void byColor(vector<Product*> items, Color color)
	{
		for (auto& i : items)
		{
			if (i->color == color)
				Result.push_back(i);
		}
	}
	// If you wanted to add another filter..
	void bySize(vector<Product*> items, Size size)
	{
		for (auto& i : items)
		{
			if (i->color == size)
				Result.push_back(i);
		}
	}

};

ostream& operator<<(ostream& os, const vector<Product*>& product)
{
	for (const auto p : product)
	{
		os << " \""<< p->name<< " \"\t" << p->color << "\t" << p->size << endl;
	}
	return os;
}




template < typename T> class Specification
{
public:
	virtual bool isSatisfied(T* item) = 0;
};

template <typename T> class AndSpecification : public Specification<T>
{
public:
	Specification <T>& first;
	Specification <T>& second;
	AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}
	bool isSatisfied(T *item) override
	{
		return (first.isSatisfied(item) && second.isSatisfied(item));
	}

};

template < typename T> class Filter
{
public:
	virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;

};

class BetterFilter : public Filter<Product>
{
public:

	vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override
	{
		vector<Product*> result;
		for (auto& item : items)
		{
			if (spec.isSatisfied(item))
			{
				result.push_back(item);
			}
		}
		return result;
	}
};

class ColorSpecification : public Specification<Product>
{
public:
	Color color;
	ColorSpecification(Color color) : color(color) {}
	bool isSatisfied(Product *item) override
	{
		return item->color == color;
	}
};


class SizeSpecification : public Specification<Product>
{
public:
	Size size;
	SizeSpecification(Size size) :size(size) {}
	bool isSatisfied(Product* item) override
	{
		return item->size == size;
	}
};
int main()
{
    std::cout << "Open Close Principle!\n";

	Product apple("Apple", Color::green, Size::small);
	Product tree("Tree", Color::green, Size::large);
	Product house("House", Color::blue, Size::large);

	vector<Product*> myItems{ &apple, &tree, &house };
	cout << " My current Items : " << endl;
	cout << myItems << endl;

	/* OLD SCHOOL
	
	ProductFilter myColorFilter;
	myColorFilter.byColor(myItems, Color::green);
	cout << " My Filtered Items by Color : " << endl;

	cout << myColorFilter.Result << endl;

	// If you wanted to add another filter..

	ProductFilter mySizeFilter;
	mySizeFilter.bySize(myItems, Size::large);
	cout << " My Filtered Items by size : " << endl;

	cout << mySizeFilter.Result << endl;


	*/

	/*So this is once again a workable solution but the problem is you've had to go back into a chunk of code
	that you've already tested and not only have your you tested it may be you've already shipped it to
	the client.
	So now you have to introduce this binary compatibility by adding another interface member to proc filter
	which isn't so great.
	And somewhere down the line of course your boss is going to come back to you once again and say Can
	you please make sure that our clients can filter him by both size and color.
	So you go back into an existing code you replicate this.
	*/

	/*So the open closed principle basically states that your systems should be open to extensions so you
	should be able to extend systems by inheritance for example but closed for modification.*/

	BetterFilter bfColor;
	ColorSpecification greenSpec(Color::green);

	for (auto& item: bfColor.filter(myItems, greenSpec))
	{
		cout << item->name << " is green" << endl;
	}

	BetterFilter bfSize;
	SizeSpecification largeSpec(Size::large);

	for( auto& item: bfSize.filter(myItems, largeSpec))
	{
		cout << item->name << " is large" << endl;
	}
	BetterFilter bfColorSize;
	AndSpecification<Product> GreenLargeSpec(greenSpec, largeSpec);

	for (auto& item : bfSize.filter(myItems, GreenLargeSpec))
	{
		cout << item->name << " is green and large" << endl;
	}
	return 0;



	// Open & Closed : Open to Extension, Closed to modification


}


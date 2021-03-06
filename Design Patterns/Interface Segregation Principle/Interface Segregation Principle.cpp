// Interface Segregation Principle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Document;

class WIMachine
{
public:
	virtual void print(Document &doc) = 0;
	virtual void scan(Document &doc) = 0;
	virtual void fax(Document &doc) = 0;

};
//Now the problem that you typically encounter is what happens if you need to implement just a printer
//or just a scanner because you only have this machine interface to work with.


class WScanner : WIMachine
{
public:
	void print(Document &doc) override
	{
		//Now the question is Well what do I put inside print.
	}
	void scan(Document &doc) override
	{
	
	}
	void fax(Document &doc) override
	{

	}
};

/*What do I put inside facts there are different options here.
So for example you might say Well how about we throw some sort of not implemented exception and we basically throw some exceptions saying you're doing something invalid.
But some people might say well it's OK let's just leave them blank let's leave them as not just empty bodies.
So if somebody calls scanner the printer they just don't get anything.
Now the problem is that either way what you're doing is you're sending the client a wrong message you're sending them the message that you've got the scanner which can also print which isn't true but you're
giving them the API anyway simply because the interface that's been defined for handling all of this
stuff is just too big.*/

//Solution :

/*So instead of this approach you would actually segregate the interfaces so you would have different

interfaces for the princeling the scanning and the faxing as well.
*/

class IPrinter
{
public:
	virtual void print(Document& doc) = 0;
};

class IScanner
{
public:
	virtual void scan(Document& doc) = 0;
};

class IFax
{
public:
	virtual void fax(Document& doc) = 0;
};

// If you want to have a printer

class Printer : public IPrinter
{
public:
	void print(Document &doc) override
	{
		// Printing code here 
	}
};

// If you want to have a scanner

class Scanner : public IScanner
{
public:
	void scan(Document &doc) override
	{
		// Scanning code here 
	}
};


// If you want both a printer and a scanner 

class IMachine : public IPrinter, public IScanner {};	// No need implementation. Can keep abstract

class Machine : public IMachine
{
public:
	// Build a decorator

	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

	void print(Document &doc) override
	{
		// Printing code here 
	}

	void scan(Document &doc) override
	{
		// Scanning code here 
	}

};





int main()
{
    std::cout << "Interface Segregation Principle!\n"; 
}

/*
Ovoid stuffing too much in one interface 
Break up your interface into smaller interface to make more sense!
*/

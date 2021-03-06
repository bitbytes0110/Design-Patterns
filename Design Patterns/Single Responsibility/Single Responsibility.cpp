// Single Responsibility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Journal.h"
#include "PersistentManager.h"

using namespace std;

int main()
{
	std::cout << "Single Responsibility!\n";
	Journal myJournal{ "Dear Diary" };
	myJournal.add_entry("I started learning design patterns today");
	myJournal.add_entry("I ate a bug today");
	myJournal.add_entry("I feel happy");


	/* 
	The problem with this approach is you are adding saving code in your journal
	In the future say if you want to use a database instead of a file, then you have to change the whole code
	Now we will do SEPERATION OF CONCERNS.

	Create a Persistence Manager to save, load and do all persistent related functions
	*/


	//myJournal.save("Dear Diary");
	PersistentManager myPersistenceManager;
	myPersistenceManager.save(myJournal, "Dear Diary.txt");

}
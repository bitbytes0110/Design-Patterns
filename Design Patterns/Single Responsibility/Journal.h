#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Journal
{
public:
	Journal();

	Journal(const string& title) : Title(title) {}

	void save(const string& filename);

	void add_entry(const string& entry);

	string Title;
	vector <string> Entries;

	~Journal();
};


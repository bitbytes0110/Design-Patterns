#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Journal.h"

using namespace std;


class PersistentManager
{
public:
	PersistentManager();
	void save(const Journal &myJournal, const string& filename);

	~PersistentManager();
};


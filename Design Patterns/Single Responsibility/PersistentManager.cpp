#include "pch.h"
#include "PersistentManager.h"
#include "Journal.h"


PersistentManager::PersistentManager()
{
}


void PersistentManager::save(const Journal &myJournal, const string& filename)
{
	ofstream ofs(filename);

	for (const auto& entry : myJournal.Entries)
	{
		ofs << entry << endl;
	}
}

PersistentManager::~PersistentManager()
{
}

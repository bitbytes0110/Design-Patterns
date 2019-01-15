#include "pch.h"
#include "Journal.h"


Journal::Journal()
{
}


void Journal::save(const string& filename)
{
	ofstream ofs(filename);

	for (const auto& entry : Entries)
	{
		ofs << entry << endl;
	}
}

void Journal::add_entry(const string& entry)
{
	static int count = 1;
	Entries.push_back(to_string(count++) + ": " + entry);
}

Journal::~Journal()
{
}

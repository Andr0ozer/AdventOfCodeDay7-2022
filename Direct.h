#ifndef DIRECTORY
#define DIRECTORY

#include "file.h"
#include <string>
#include <vector>
#include <map>

class dir
{
public:

	dir();

	dir(string inputname);

	void addfile(compfile file);

	void adddir(dir dir);

	void addparent(string par);

	string getparent();

	string getname();

	vector<dir> getdirs();

	vector<compfile> getfiles();

	int getsize(map<string, dir> directories);

private:
	string name;
	string parent;
	vector<compfile> containedfiles;
	vector<dir> containeddir;
};

#endif DIRECTORY



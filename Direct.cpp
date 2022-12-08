#include "Direct.h"
#include <iostream>
using namespace std;

dir::dir()
{
}

dir::dir(string inputname)
{
	name = inputname;
}

void dir::addfile(compfile file)
{
	containedfiles.push_back(file);
}

void dir::adddir(dir dir)
{
	containeddir.push_back(dir);
}

void dir::addparent(string par)
{
	parent = par;
}

string dir::getparent()
{
	return parent;
}

string dir::getname()
{
	return name;
}

vector<dir> dir::getdirs()
{
	return containeddir;
}

vector<compfile> dir::getfiles()
{
	return containedfiles;
}

int dir::getsize(map<string, dir> directories)
{
	int size = 0;
	for (int j = 0; j < containeddir.size(); j++)
	{
		size = size + directories[containeddir[j].getname()].getsize(directories);
	}
	for (int i = 0; i < containedfiles.size(); i++)
	{
		size = size + containedfiles[i].getfilesize();
	}
	return size;
}



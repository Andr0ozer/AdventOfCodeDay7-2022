#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "file.h"
#include "Direct.h"

using namespace std;

int main()
{
	vector<string> directorylist;
	string currentline, inputline;
	map<string, dir> directories;
	string currentdirectory = "/";
	dir working;
	int lastslash = 0, total = 0;
	bool exist;

	directories[currentdirectory] = dir::dir(currentdirectory);
	directories[currentdirectory].addparent("/");
	directorylist.push_back(currentdirectory);

	ifstream infile;
	infile.open("input.txt");

	while (!infile.eof())
	{
		getline(infile, inputline);
		currentline = inputline;

		if (currentline[0] == '$')
		{
			currentline = currentline.substr(2, currentline.size() - 1);
			if (currentline[0] == 'c')
			{
				currentline = currentline.substr(3, currentline.size() - 1);
				if (currentline[0] != '.')
				{
					currentdirectory = currentline;
				}
				else
				{
					currentdirectory = directories[currentdirectory].getparent();
				}
			}
		}
		else if (currentline[0] == 'd')
		{
			currentline = currentline.substr(4, currentline.size() - 1);

			dir tempdir = dir::dir(currentline);
			tempdir.addparent(currentdirectory);
			directories[currentdirectory].adddir(tempdir);
			directorylist.push_back(tempdir.getname());
			directories[tempdir.getname()] = tempdir;
		}
		else // file
		{
			for (int i = 0; i < currentline.size(); i++)
			{
				if (currentline[i] == ' ')
				{
					compfile tempfile = compfile::compfile(currentline.substr(i + 1, currentline.size() - 1), stoi(currentline.substr(0, i)));
					directories[currentdirectory].addfile(tempfile);
				}
			}
		}
	}
	infile.close();
	for (auto it = directories.begin(); it != directories.end(); it++)
	{
		working = it->second;
		cout << "Name: " << working.getname() << " |Size: " << working.getsize(directories) << " |Parent: " << working.getparent() << endl << "Files:" << endl;
		for (int i = 0; i < working.getfiles().size(); i++)
		{
			cout << working.getfiles()[i].getfilename() << ", ";
		}
		cout << endl << "Sub Dirs:" << endl;
		for (int i = 0; i < working.getdirs().size(); i++)
		{
			cout << working.getdirs()[i].getname() << ", ";
		}
		cout << endl;
		if (working.getsize(directories) <= 100000)
		{
			total = total + working.getsize(directories);
		}
	}
	cout << "Total: " << total;
}
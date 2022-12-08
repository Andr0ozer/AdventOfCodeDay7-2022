
#ifndef COMPFILE
#define COMPFILE

#include <string>
using namespace std;

class compfile
{
public:
	compfile();

	compfile(string filename, int filesize);

	int getfilesize();

	string getfilename();

private:
	//string name;
	int size;
	string name;
};
#endif COMPFILE

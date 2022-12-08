#include "file.h"

using namespace std;



compfile::compfile()
{
}

compfile::compfile(string filename, int filesize)
{
    name = filename;
    size = filesize;
}

int compfile::getfilesize()
{
    return size;
}

string compfile::getfilename()
{
    return name;
}

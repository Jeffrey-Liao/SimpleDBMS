#include "Infor.h"
#define SURFFIX ".ldata"

class DataFile
{
	char* dir;
public:
	DataFile(const char* dir)
	{
		size_t len = strlen(dir);
		this->dir = new char[len + 1];
		this->dir[len] = '\0';
		memcpy(this->dir, dir, len);
	}
	void readConfig()
	{

	}
};

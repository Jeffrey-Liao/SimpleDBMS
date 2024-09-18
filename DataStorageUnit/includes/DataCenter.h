#ifndef DATACENTER_H
#define DATACENTER_H
#include<set>
#include "Type.h"
using namespace std;
#define PAGESIZE 300000
namespace liaoStorage
{
	class DataPage
	{
		void* data;
		int1 width;
		const size_t size;
		
	public:
		DataPage(TypeTag type,const char* file)
			:width(typeTagToByteSize(type)),size(PAGESIZE)
		{
			data = new char[width * size];
			
		}
		void* take(size_t index)
		{
			return ((char*)data)+(width * index);
		}
		void put(size_t where, void* data)
		{
			memccpy((char*)this->data+(where*width), (char*)data,'\0', width);
		}
		~DataPage()
		{
			delete[] (char*)data;
		}
	};
	class DataCenter
	{
		
	};
}

#endif
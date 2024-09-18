#pragma once
#include "Infor.h"
#include "Type.h"
#include <unordered_map>
#include <unordered_set>
#define MAXNAMELEN 50
namespace liaoStorage
{
	using namespace std;
	class Record
	{
		pair<string, unordered_set<Type>> prime;
		unordered_map<string, unordered_set<Type>> attributes;
	public:
		Record(vector<string> names,vector<TypeTag> dataType)
		{}
	};
}
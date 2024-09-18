#pragma once
#include "Infor.h"
#include "Type.h"
#include <vector>
namespace liaoStorage
{
	class Attribute
	{
		using string = std::string;
		string name;
		std::vector<Type>data;
	};
}

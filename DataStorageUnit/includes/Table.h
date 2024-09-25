#pragma once
#include "Infor.h"
#include "Attributes.h"
#define MAXNAMELEN 50
namespace liaoStorage
{
	using namespace std;
	class Table
	{
		string name;
		std::list<Attribute> attributes;
	public:

		Table(string name,const vector<string>& names, const vector<TypeTag>& dataType)
			:name(name)
		{
			for (size_t n = 0; n < names.size(); ++n)
				attributes.push_back(Attribute(names[n].c_str(), dataType[n]));
		}
		vector<Type*> add(vector<Type> data)
		{

		}
		Attribute* where(const string& name)
		{
			for (auto& attribute : attributes)
			{
				if (attribute.getName() == name)
					return &attribute;
			}
			return nullptr;
		}
		Attribute& operator[](size_t position)
		{
			size_t cnt = 0;
			for (auto& attribute : attributes)
			{
				if (cnt == position)
					return attribute;
				cnt++;
			}
			return Table::null;
		}
		size_t width()
		{
			return attributes.size();
		}
		static Attribute null;
	};
	Attribute Table::null("not found",TypeTag::Null);
}
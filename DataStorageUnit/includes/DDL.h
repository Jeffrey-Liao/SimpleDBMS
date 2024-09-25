#ifndef DDL_H
#define DDL_H
#include"Table.h"
namespace liaoStorage
{
#define ERROR_NOTFOUND 0b1
#define ERROR_RECORDSIZE 0b11
#define ERRORMESSAGE int& errorCode
	class DDL
	{
		Table* table;
	public:
		DDL()
			:table(nullptr)
		{}
		DDL(Table* table)
			:table(table)
		{}
		DDL(Table& table)
			:table(&table)
		{}
		void create(string name,const vector<string>& names, const vector<TypeTag>& tags)
		{
			if (table != nullptr)
				delete table;
			table = new Table(name,names, tags);
		}
		vector<Attribute*> select()
		{
			vector<Attribute*> vec;
			for (int n = 0; n < table->width(); ++n)
			{
				vec.push_back(&(*table)[n]);
			}
			return vec;
		}
		Attribute* select(string& columnName)
		{
			return table->where(columnName);
		}
		Attribute* select(string&& columnName)
		{
			return select(columnName);
		}
		std::vector<Attribute*>select(const std::vector<string>& nameList)
		{
			std::vector<Attribute*> vec;
			for (auto& name : nameList)
			{
				Attribute* var = table->where(name);
				if(var->tag != TypeTag::Null)
					vec.push_back(var);
			}
			return vec;
		}
		void insert(const std::initializer_list<TypePlus>& newData)
		{
			if (newData.size() == table->width() && newData.size() != 0)
			{
				bool valid = true;
				int n = 0;
				for (auto& data : newData)
				{
					if(data.tag != (*table)[n].tag)
						valid = false;
					++n;
				}
				n = 0;
				for (auto& data : newData)
				{
					(*table)[n].add(data);
					++n;
				}
			}
		}
		void insert(std::vector<TypePlus>& newData)
		{
			if (newData.size() == table->width() && newData.size() != 0)
			{
				bool valid = true;
				for (int n = 0; n < newData.size(); ++n)
				{
					if (newData[n].tag != (*table)[n].tag)
						valid = false;
				}
				if (valid)
				{
					for (int n = 0; n < newData.size(); ++n)
					{
						(*table)[n].add(newData[n]);
					}
				}
			}
		}
		void insert(std::vector<TypePlus>&& newData)
		{
			insert(newData);
		}
	};
}

#endif
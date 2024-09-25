#pragma once
#include "TypePlus.h"
#include <vector>
#include <list>
#define NAMESIZE 50
/*
		void assign(const void* data)
		{
			if (space == nullptr)
				newSpace();
			if (tag == Int1)
				*(char*)space = *(char*)data;
			else if (tag == Int2)
				*(short int*)space = *(short int*)data;
			else if (tag == Int4)
				*(int*)space = *(int*)data;
			else if (tag == Int8)
				*(long long*)space = *(long long*)data;
			else if (tag == Real4)
				*(real4*)space = *(real4*)data;
			else if (tag == Real8)
				*(real8*)space = *(real8*)data;
			else if (tag == Char)
				strcpy_s((char*)space, _msize(space), (char*)data);
		}
		void add(const void* data)
		{
			if (tag == Int1)
				*(int1*)space += *(int1*)data;
			else if (tag == Int2)
				*(int2*)space += *(int2*)data;
			else if (tag == Int4)
				*(int4*)space += *(int4*)data;
			else if (tag == Int8)
				*(int8*)space += *(int8*)data;
			else if (tag == Real4)
				*(real4*)space += *(real4*)data;
			else if (tag == Real8)
				*(real8*)space += *(real8*)data;
		}
		void minus(const void* data)
		{
			if (tag == Int1)
				*(int1*)space -= *(int1*)data;
			else if (tag == Int2)
				*(int2*)space -= *(int2*)data;
			else if (tag == Int4)
				*(int4*)space -= *(int4*)data;
			else if (tag == Int8)
				*(int8*)space -= *(int8*)data;
			else if (tag == Real4)
				*(real4*)space -= *(real4*)data;
			else if (tag == Real8)
				*(real8*)space -= *(real8*)data;
		}
		void multiply(const void* data)
		{
			if (tag == Int1)
				*(int1*)space *= *(int1*)data;
			else if (tag == Int2)
				*(int2*)space *= *(int2*)data;
			else if (tag == Int4)
				*(int4*)space *= *(int4*)data;
			else if (tag == Int8)
				*(int8*)space *= *(int8*)data;
			else if (tag == Real4)
				*(real4*)space *= *(real4*)data;
			else if (tag == Real8)
				*(real8*)space *= *(real8*)data;
		}
		void divide(const void* data)
		{
			if (tag == Int1)
				*(int1*)space /= *(int1*)data;
			else if (tag == Int2)
				*(int2*)space /= *(int2*)data;
			else if (tag == Int4)
				*(int4*)space /= *(int4*)data;
			else if (tag == Int8)
				*(int8*)space /= *(int8*)data;
			else if (tag == Real4)
				*(real4*)space /= *(real4*)data;
			else if (tag == Real8)
				*(real8*)space /= *(real8*)data;
		}
		void assign(const TypePlus& data)
		{
			assign(data.space);
		}
		void add(const TypePlus& data)
		{
			if (tag == Int1)
				*(int1*)space += *(int1*)data.space;
			else if (tag == Int2)
				*(int2*)space += *(int2*)data.space;
			else if (tag == Int4)
				*(int4*)space += *(int4*)data.space;
			else if (tag == Int8)
				*(int8*)space += *(int8*)data.space;
			else if (tag == Real4)
				*(real4*)space += *(real4*)data.space;
			else if (tag == Real8)
				*(real8*)space += *(real8*)data.space;
		}
		void minus(const TypePlus& data)
		{
			if (tag == Int1)
				*(int1*)space -= *(int1*)data.space;
			else if (tag == Int2)
				*(int2*)space -= *(int2*)data.space;
			else if (tag == Int4)
				*(int4*)space -= *(int4*)data.space;
			else if (tag == Int8)
				*(int8*)space -= *(int8*)data.space;
			else if (tag == Real4)
				*(real4*)space -= *(real4*)data.space;
			else if (tag == Real8)
				*(real8*)space -= *(real8*)data.space;
		}
		void multiply(const TypePlus& data)
		{
			if (tag == Int1)
				*(int1*)space *= *(int1*)data.space;
			else if (tag == Int2)
				*(int2*)space *= *(int2*)data.space;
			else if (tag == Int4)
				*(int4*)space *= *(int4*)data.space;
			else if (tag == Int8)
				*(int8*)space *= *(int8*)data.space;
			else if (tag == Real4)
				*(real4*)space *= *(real4*)data.space;
			else if (tag == Real8)
				*(real8*)space *= *(real8*)data.space;
		}
		void divide(const TypePlus& data)
		{
			if (tag == Int1)
				*(int1*)space /= *(int1*)data.space;
			else if (tag == Int2)
				*(int2*)space /= *(int2*)data.space;
			else if (tag == Int4)
				*(int4*)space /= *(int4*)data.space;
			else if (tag == Int8)
				*(int8*)space /= *(int8*)data.space;
			else if (tag == Real4)
				*(real4*)space /= *(real4*)data.space;
			else if (tag == Real8)
				*(real8*)space /= *(real8*)data.space;
		}
		int4 compare(const void* data)
		{
			int4 result = 0;
			if (tag == Int1)
			{
				result = *(int1*)space > *(int1*)data ? 1 : 0;
				result = *(int1*)space < *(int1*)data ? -1 : 0;
			}
			else if (tag == Int2)
			{
				result = *(int2*)space > *(int2*)data ? 1 : 0;
				result = *(int2*)space < *(int2*)data ? -1 : 0;
			}
			else if (tag == Int4)
			{
				result = *(int4*)space > *(int4*)data ? 1 : 0;
				result = *(int4*)space < *(int4*)data ? -1 : 0;
			}
			else if (tag == Int8)
			{
				result = *(int8*)space > *(int8*)data ? 1 : 0;
				result = *(int8*)space < *(int8*)data ? -1 : 0;
			}
			else if (tag == Real4)
			{
				result = *(real4*)space > *(real4*)data ? 1 : 0;
				result = *(real4*)space < *(real4*)data ? -1 : 0;
			}
			else if (tag == Real8)
			{
				result = *(real8*)space > *(real8*)data ? 1 : 0;
				result = *(real8*)space < *(real8*)data ? -1 : 0;
			}
			return result;
		}
		int4 compare(const TypePlus& data)
		{
			return compare(data.space);
		}
		bool operator==(const void* data)
		{
			return compare(data) == 0;
		}
		bool operator<=(const void* data)
		{
			return compare(data) == -1;
		}
		bool operator>=(const void* data)
		{
			return compare(data) == 1;
		}
		TypePlus& operator=(const void* data)
		{
			assign(data);
			return *this;
		}
		TypePlus& operator+=(const void* data)
		{
			add(data);
			return *this;
		}
		TypePlus& operator-=(const void* data)
		{
			minus(data);
			return *this;
		}
		TypePlus& operator*=(const void* data)
		{
			multiply(data);
			return *this;
		}
		TypePlus& operator/=(const void* data)
		{
			divide(data);
			return *this;
		}
		bool operator==(const TypePlus& data)
		{
			return compare(data) == 0;
		}
		bool operator<=(const TypePlus& data)
		{
			return compare(data) == -1;
		}
		bool operator>=(const TypePlus& data)
		{
			return compare(data) == 1;
		}
		TypePlus& operator=(const TypePlus& data)
		{
			assign(data);
			return *this;
		}
		TypePlus& operator+=(const TypePlus& data)
		{
			add(data);
			return *this;
		}
		TypePlus& operator-=(const TypePlus& data)
		{
			minus(data);
			return *this;
		}
		TypePlus& operator*=(const TypePlus& data)
		{
			multiply(data);
			return *this;
		}
		TypePlus& operator/=(const TypePlus& data)
		{
			divide(data);
			return *this;
		}
*/
namespace liaoStorage
{
	using namespace std;
	Type Type::null;
	class Attribute
	{
		char name[NAMESIZE];
		std::vector<Type> data;
	public:
		const TypeTag tag;
		Attribute()
			:tag(TypeTag::Null)
		{}
		Attribute(const char* name,TypeTag tag)
			:tag(tag)
		{
			int size = strlen(name);
			if(size > NAMESIZE)
				strcpy_s(this->name,size, name);
			else
				strcpy_s(this->name, NAMESIZE, name);
		}
		void rename(const char* newName)
		{
			strcpy_s(this->name, strlen(name), newName);
		}
		const char* getName()
		{
			return name;
		}
		Type& add(const TypePlus& data)
		{
			if (data.tag != tag)
				return Type::null;
			else
				this->data.push_back(data);
		}
		Type& get(size_t index)
		{
			return data[index];
		}
		size_t size()
		{
			return data.size();
		}
		Type& operator[](size_t index)
		{
			return get(index);
		}
	};
}

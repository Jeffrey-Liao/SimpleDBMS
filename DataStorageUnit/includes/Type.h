#pragma once
namespace liaoStorage
{
#include<string>
	enum class TypeTag : char
	{
		Null,
		Int4,
		Int8,
		Int2,
		Int1,
		Char,
		VarChar,//
		Bool,//
		Date,//
		Real4,
		Real8,
		Decimal,//
		Int16,//
		Int32//
	};
	using int1 = char;
	using int2 = short int;
	using int4 = int;
	using int8 = long long;
	using real4 = float;
	using real8 = double;
	constexpr static int1 typeTagToByteSize(TypeTag tag)
	{
		if (tag == TypeTag::Int1)
			return sizeof(int1);
		else if (tag == TypeTag::Int2)
			return sizeof(int2);
		else if (tag == TypeTag::Int4)
			return sizeof(int4);
		else if (tag == TypeTag::Int8)
			return sizeof(int8);
		else if (tag == TypeTag::Real4)
			return sizeof(real4);
		else if (tag == TypeTag::Real8)
			return sizeof(real8);
	}
	static TypeTag typeId2TypeTag(std::string&& typeId)
	{
	}
	class String
	{
		char* str;
		size_t size;
	public:
		String(size_t size)
			:size(size), str(NULL)
		{}
		String(const char* str)
			:size(strlen(str))
		{
			str = new char[size + 1];
			strcpy_s(this->str, size, str);
		}
		size_t len()
		{
			return size - 1;
		}
		bool compare(const String& object)
		{
			if (size != object.size)
				return false;
			return strcmp(str, object.str) == 0;
		}
		bool operator==(const String& object)
		{
			return compare(object);
		}
		~String()
		{
			if (str != NULL)
				delete str;
		}
	};
	class Type
	{
		using enum TypeTag;
		int number;
		TypeTag tag;
		void* space;
		void newSpace()
		{
			if (tag == Int1)
				space = new char;
			else if (tag == Int2)
				space = new short int;
			else if (tag == Int4)
				space = new int;
			else if (tag == Int8)
				space = new long long;
			else if (tag == Real4)
				space = new real4;
			else if (tag == Real8)
				space = new real8;
			else if (tag == Char)
				space = new char[number + 1];
		}
	public:
		Type()
			:tag(Null), space(nullptr), number(0)
		{}
		Type(TypeTag tag,const int number=0)
			:tag(tag),space(nullptr),number(number)
		{}
		Type(TypeTag tag,const void* newData,const int number = 0)
			:tag(tag), space(nullptr), number(number)
		{
			assign(newData);
		}
		void changeTag(TypeTag newTag)
		{
			tag = newTag;
			delete space;
			space = nullptr;
		}
		bool isNull()
		{
			return space == nullptr;
		}
		TypeTag getTag()
		{
			return tag;
		}
		void assign(const void* data)
		{
			if(space == nullptr)
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
			else if (tag == Char && number != 0)
				strcpy_s((char*)space, number, (char*)data);
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
		void assign(const Type& data)
		{
			assign(data.space);
		}
		void add(const Type& data)
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
		void minus(const Type& data)
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
		void multiply(const Type& data)
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
		void divide(const Type& data)
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
		int4 compare(const Type& data)
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
		Type& operator=(const void* data)
		{
			assign(data);
			return *this;
		}
		Type& operator+=(const void* data)
		{
			add(data);
			return *this;
		}
		Type& operator-=(const void* data)
		{
			minus(data);
			return *this;
		}
		Type& operator*=(const void* data)
		{
			multiply(data);
			return *this;
		}
		Type& operator/=(const void* data)
		{
			divide(data);
			return *this;
		}
		bool operator==(const Type& data)
		{
			return compare(data) == 0;
		}
		bool operator<=(const Type& data)
		{
			return compare(data) == -1;
		}
		bool operator>=(const Type& data)
		{
			return compare(data) == 1;
		}
		Type& operator=(const Type& data)
		{
			assign(data);
			return *this;
		}
		Type& operator+=(const Type& data)
		{
			add(data);
			return *this;
		}
		Type& operator-=(const Type& data)
		{
			minus(data);
			return *this;
		}
		Type& operator*=(const Type& data)
		{
			multiply(data);
			return *this;
		}
		Type& operator/=(const Type& data)
		{
			divide(data);
			return *this;
		}
		~Type()
		{
			if (tag == Char || tag == VarChar)
			{
				if (space != nullptr)
					delete[] space;
			}
			else
			{
				if (space != nullptr)
					delete space;
			}
		}
	};
	
}
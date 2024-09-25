#include "Type.h"
namespace liaoStorage
{
	using namespace std;
	class TypePlus :public Type
	{
	public:
		TypeTag tag;
		TypePlus()
			:tag(TypeTag::Null), Type()
		{}
		
		DYNAMIC
		TypePlus(T&& value)
			:Type()
		{
			assign(value);
		}
		TypePlus(TypeTag tag)
			:tag(tag), Type()
		{}
		TypePlus(TypePlus&& data) noexcept
			:TypePlus(data)
		{}
		template<class T>
			TypePlus(T& value)
			:Type()
		{
			assign(value);
		}
		TypePlus(TypePlus& data)
			:Type(data), tag(data.tag)
		{}
		DYNAMIC
		void assign(const T& value)
		{
			string name = typeid(value).name();
			int size = sizeof(T);
			bool isChar = name.find("char") != -1 || name == typeid(string).name();
			if (isChar)
				tag = TypeTag::Char;
			else if (name == typeid(int1).name())
				tag = TypeTag::Int1;
			else if (name == typeid(int2).name())
				tag = TypeTag::Int2;
			else if (name == typeid(int4).name())
				tag = TypeTag::Int4;
			else if (name == typeid(int8).name())
				tag = TypeTag::Int8;
			else if (name == typeid(real4).name())
				tag = TypeTag::Real4;
			else if (name == typeid(real8).name())
				tag = TypeTag::Real8;
			if (isChar)
				space = new char[size + 1], ((char*)space)[size] = '\0';
			else
				space = new char[size];
			memcpy(space, &value, size);
		}
		bool isNull()
		{
			return space == nullptr;
		}
		TypeTag getTag()
		{
			return tag;
		}
		Type& toType()
		{
			return *this;
		}
	};
}

#include "Infor.h"
namespace liaoStorage
{
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
	struct chars
	{
		char* space;
		size_t capcity;
	};
	class Type
	{
	protected:
		void* space;
	public:
		Type()
			:space(nullptr)
		{}
		Type(void* ptr, int size)
		{
			this->space = new char[size];
			memcpy(space, ptr, size);
		}
		Type(Type* ptr)
		{
			this->space = ptr->space;
			ptr->space = nullptr;
		}
		Type(const Type& object)
		{
			if (!object.isNull())
			{
				int size = _msize(object.space);
				space = new char[size];
				memcpy(space, object.space, size);
			}
		}
		Type(Type& object)
		{
			space = object.space;
			object.space = nullptr;
		}
		Type(Type&& object) noexcept
			:Type(object)
		{}

		bool isNull()const
		{
			return space == nullptr;
		}
		DYNAMIC
			T& get()
		{
			return *(T*)space;
		}
		char* getStr()
		{
			return (char*)space;
		}
		DYNAMIC
			const T& get()const
		{
			return *(T*)space;
		}
		void set(void* data)
		{
			space = data;
		}
		DYNAMIC
			void set(T& data)
		{
			if (isNull())
				space = new char[sizeof(T)];
			memcpy(space, &data, sizeof(T));
		}
		DYNAMIC
			void set(T&& data)
		{
			this->set(data);
		}
		int size()
		{
			if (isNull())
				return 0;
			return _msize(space);
		}
		Type& operator=(void* data)
		{
			if (data != nullptr)
			{
				int size = _msize(data);
				if (isNull())
					space = new char[size];
				memcpy(space, data, size);
			}
			return *this;
		}
		Type& operator=(Type& data)
		{
			if (!data.isNull())
			{
				space = data.space;
				data.space = nullptr;
			}
			return *this;
		}
		~Type()
		{
			if (space != nullptr)
				delete[] space;
		}
		static Type null;
	};

}

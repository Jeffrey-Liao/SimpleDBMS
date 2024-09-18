#include"../include/Infor.h"
namespace liaoInfor
{
	using string = std::string;
	constexpr const char* Infor::getLabel()const
	{
		if (currentType == Common)
			return INFORLABEL;
		else if (currentType == InforType::Debug)
			return DEBUGLABEL;
		else if (currentType == Error)
			return ERRORLABEL;
		else if (currentType == Exception)
			return EXCEPTIONLABEL;
		else
			return "";
	}
	constexpr bool Infor::whenActive()const
	{
		return (bits & 0b11) == 0b11 || bits == 0;
	}

	Infor::Infor(InforType currentType)
		:currentType(currentType), bits(0)
	{}
	Infor::Infor(InforType currentType, bool useDefaultProcess)
		:currentType(currentType), bits(useDefaultProcess << 3)
	{}
	string Infor::log(const string& message, bool useTimeStamp)const
	{
		string str = print(message, useTimeStamp);
		switchLine();
		return str;
	}
	string Infor::log(string&& message, bool useTimeStamp)const
	{
		string str = print(message, useTimeStamp);
		switchLine();
		return str;
	}
	string Infor::log(const char* classInformation, const string& message, bool useTimeStamp)const
	{
		string str = print(classInformation, message, useTimeStamp);
		switchLine();
		return str;
	}
	string Infor::log(const char* classInformation, string&& message, bool useTimeStamp) const
	{
		string str = print(classInformation, message, useTimeStamp);
		switchLine();
		return str;
	}
	const string& Infor::getCache() const
	{
		return Cache;
	}
	string Infor::print(const string& message, bool useTimeStamp)const
	{
		string str;
		if (whenActive())
		{
			if (useTimeStamp)
				cout << (str = getTime());
			cout << getLabel() << message;
			str += getLabel() + message;
		}
		this->bits=0;
		return str;
	}
	string Infor::print(string&& message, bool useTimeStamp)const
	{
		if (whenActive())
		{
			return print(message, useTimeStamp);
		}
		return "";
	}
	string Infor::print(const char* classInformation, const string& message, bool useTimeStamp) const
	{
		string str;
		if (whenActive())
		{
			if (useTimeStamp)
				cout << (str+=getTime());
			cout << getLabel() << ClassInfor::getInstance().newInfor(classInformation).convertToString() << ":" << message;
			str += getLabel() + ClassInfor::getInstance().newInfor(classInformation).convertToString() + ":" + message;
		}
		this->bits=0;
		return str;
	}
	string Infor::print(const char* classInformation, string&& message, bool useTimeStamp) const
	{
		return print(classInformation, message, useTimeStamp);
	}
	
	Infor& Infor::when(bool condition)
	{
		bits = condition;
		bits += 0b10;
		return *this;
	}
	void Infor::toFile(string& fileName)
	{
		if (!Cache.empty())
		{
			fstream file(fileName, ios::out);
			if (!file.fail())
				file << Cache, file.close();
		}
	}
	void Infor::toFile(string&& fileName)
	{
		toFile(fileName);
	}
	string Infor::flashOut()
	{
		string str;
		if (!Cache.empty())
		{
			cout << Cache;
			str = Cache;
			Cache.clear();
			this->bits = 0;
		}
		return str;
	}
	void Infor::clear()
	{
		Cache.clear();
	}
	Infor& Infor::time()
	{
		Cache += getTime();
		return *this;
	}
	Infor& Infor::label()
	{
		Cache += getLabel();
		return *this;
	}
	Infor& Infor::append(string&& message)
	{
		return append(message);
	}
	Infor& Infor::append(string& message)
	{
		Cache += message;
		return *this;
	}
	Infor& Infor::classInfor(string& funcSig)
	{
		ClassInfor::getInstance().newInfor(funcSig);
		Cache+= ClassInfor::getInstance().convertToString();
		return *this;
	}
	Infor& Infor::operator<<(const char* message)
	{
		Cache += message;
		return *this;
	}
	void Infor::end()
	{
		flashOut();
	}
	Infor& Infor::operator<<(string& message)
	{
		append(message);
		return *this;
	}
	Infor& Infor::head()
	{
		cout << getTime() << getLabel();
		return *this;
	}
	Infor::~Infor()
	{
		flashOut();
	}
}
#include "ClassInfor.h"
namespace liaoInfor
{
	using string = std::string;
	ClassInfor* ClassInfor::instance;
	void ClassInfor::reallocate(const string& classInfor)
	{
		if (instance != NULL)
			delete instance;
		instance = new ClassInfor(classInfor);
	}
	/*
	constexpr void ClassInfor::reconstruct(const string& classInfor)
	{
		if (!classInfor.empty())
		{
			functionReturnType = classInfor.substr(0, classInfor.find_first_of(" "));
			if (!functionReturnType.empty())
			{
				functionParameter = classInfor.substr(classInfor.find_first_of("("), classInfor.find_first_of("(") - classInfor.find_first_of(")"));
				if (!functionParameter.empty())
				{
					functionName = classInfor.find_first_of(':') != -1 ?
						classInfor.substr(classInfor.find_last_of(":") + 1, classInfor.find_first_of('(') - classInfor.find_last_of(":") - 1)
						: classInfor.substr(classInfor.find_last_of(" ") + 1, classInfor.find_first_of('(') - classInfor.find_last_of(" ") - 1);
					if(!functionName.empty())
						className = classInfor.find_first_of(':') != -1 ?
							classInfor.substr(classInfor.find_last_of(" ") + 1, classInfor.find_first_of(':') - classInfor.find_last_of(" ") - 1)
							: "";
				}
			}
		}
	}
	*/
	
	ClassInfor::ClassInfor()
	{
		instance = NULL;
	}
	ClassInfor::ClassInfor(const string& classInfor)
	{
		reconstruct(classInfor);
	}
	ClassInfor& ClassInfor::updateInfor(const string& thisFunction)
	{
		reconstruct(thisFunction);
		return *instance;
	}
	ClassInfor& ClassInfor::updateInfor(const string&& thisFunction)
	{
		reconstruct(thisFunction);
		return *instance;
	}
	ClassInfor& ClassInfor::newInfor(const string& thisFunction)
	{
		this->reallocate(thisFunction);
		return *instance;
	}
	ClassInfor& ClassInfor::newInfor(const string&& thisFunction)
	{
		this->reallocate(thisFunction);
		return *instance;
	}
	bool ClassInfor::isNULL()
	{
		return instance == NULL;
	}
	const string& ClassInfor::take(ClassInforPart part)
	{
		if (part == ClassInforPart::ClassName)
			return className;
		else if (part == ClassInforPart::MethodName)
			return functionName;
		else if (part == ClassInforPart::ReturnType)
			return functionReturnType;
		else if (part == ClassInforPart::ParameterList)
			return functionParameter;
	}
	string ClassInfor::convertToString()
	{
		if (!isNULL() && !className.empty() && !functionName.empty())
		{
			string str;
			if (!className.empty())
				str = "{" + className + "}";
			if (!functionName.empty())
				str += "[" + functionReturnType + " " + functionName + +"("+functionParameter+")" + "]";
			return str;
		}
		return "";
	}
	const string& ClassInfor::operator[](ClassInforPart part)
	{
		return take(part);
	}
}
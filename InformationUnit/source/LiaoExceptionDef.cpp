#include "LiaoException.h"
namespace liaoInfor
{
#pragma region LiaoException
	using string = std::string;
	string errorMessage(Infor& instance, const char* exception,string& methodSig,string& message, long long lineNumber)
	{
		(instance.time().label() << exception).classInfor(methodSig) << ": " << message;
		if (lineNumber > 0)
			instance << ", in line " << lineNumber;
		return instance.flashOut();
	}
	string errorMessage(Infor& instance, const char* exception, string& methodSig, string& message, string& fileLocation, long long lineNumber)
	{
		(instance.time().label() << exception).classInfor(methodSig) << ": " << message;
		if (lineNumber > 0)
			instance << ", in line " << lineNumber;
		if (!fileLocation.empty())
			instance << ", in file " << fileLocation;
		return instance.flashOut();
	}
	LiaoException::LiaoException(const char* exceptionNanme, string&& methodSigniture, string& message, long long lineNumber)
		:LiaoException(exceptionNanme,methodSigniture,message,lineNumber)
	{}

	LiaoException::LiaoException(const char* exceptionNanme, string& methodSigniture, string& message, long long lineNumber)
		:instance(InforType::Exception), runtime_error(message)
	{
		information = errorMessage(instance,exceptionNanme, methodSigniture, message, lineNumber);
	}

	LiaoException::LiaoException(const char* exceptionNanme, string&& methodSigniture, string&& message, long long lineNumber )
		:LiaoException(exceptionNanme,methodSigniture, message, lineNumber)
	{}

	LiaoException:: LiaoException(const char* exceptionNanme, string& methodSigniture, string& message, string& fileLocation, long long lineNumber)
		:instance(InforType::Exception), runtime_error(message)
	{
		information = errorMessage(instance,exceptionNanme, methodSigniture, message,fileLocation, lineNumber);
	}
	LiaoException::LiaoException(const char* exceptionNanme, string&& methodSigniture, string& message, string& fileLocation, long long lineNumber)
		:LiaoException(exceptionNanme,methodSigniture, message, fileLocation, lineNumber)
	{}

	LiaoException::LiaoException(const char* exceptionNanme, string&& methodSigniture, string&& message, string& fileLocation, long long lineNumber)
		:LiaoException(exceptionNanme, methodSigniture, message, fileLocation, lineNumber)
	{
		information = errorMessage(instance,exceptionNanme, methodSigniture, message, fileLocation, lineNumber);
	}
	LiaoException::LiaoException(const char* exceptionNanme, string&& methodSigniture, string& message, string&& fileLocation, long long lineNumber)
		:LiaoException(exceptionNanme, methodSigniture, message, fileLocation, lineNumber)
	{
	}
	LiaoException::LiaoException(const char* exceptionNanme, string&& methodSigniture, string&& message, string&& fileLocation, long long lineNumber)
		:LiaoException(exceptionNanme, methodSigniture, message, fileLocation, lineNumber)
	{
	}
	//输出错误信息到控制台
	const string& LiaoException::getFuncName()
	{
		return ClassInfor::getInstance()[ClassInforPart::MethodName];
	}
	const string& LiaoException::getFuncType()
	{
		return ClassInfor::getInstance()[ClassInforPart::ReturnType];
	}
	const string& LiaoException::getParameterList()
	{
		return ClassInfor::getInstance()[ClassInforPart::ParameterList];
	}
	const string& LiaoException::getClassName()
	{
		return ClassInfor::getInstance().take(ClassInforPart::ClassName);
	}
	void LiaoException::printAll()
	{
		instance.flashOut();
	}
	void LiaoException::printErrorObjectInfor()
	{
		instance.log(ClassInfor::getInstance().convertToString());
	}
	void LiaoException::printFuncName()
	{
		instance.Log(ClassInfor::getInstance()[ClassInforPart::MethodName].c_str());
	}
	void LiaoException::printFuncType()
	{
		instance.Log(ClassInfor::getInstance()[ClassInforPart::ReturnType].c_str());
	}
	void LiaoException::printParameterList()
	{
		instance.Log(ClassInfor::getInstance()[ClassInforPart::ParameterList].c_str());
	}
	void LiaoException::printClassName()
	{
		instance.Log(ClassInfor::getInstance()[ClassInforPart::ClassName].c_str());
	}
	void LiaoException::toFile()
	{
		fstream file;
		file.open("error.log", ios::app);
		if (!file.fail())
			file << information<<"\n";
	}
	LiaoException::~LiaoException()
	{
		instance.flashOut();
	}
#pragma endregion
#pragma region FatalException
	
#pragma endregion
#pragma region CommonException
	
#pragma endregion

}

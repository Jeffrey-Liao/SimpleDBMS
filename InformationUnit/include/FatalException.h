#ifndef FATALEXCEPTION_H
#define FATALEXCEPTION_H
#include"LiaoException.h"
namespace liaoInfor
{
#define FATALEXCEPTION :public FatalException
	class FatalException:public LiaoException
	{
	protected:
		FatalException(string&& exceptionName, string& methodSigniture, string& message, long long lineNumber = 0)
			:LiaoException(("[FatalException-"+ exceptionName + "]").c_str(), methodSigniture, message, lineNumber)
		{}
		FatalException(string&& exceptionName, string&& methodSigniture, string& message, long long lineNumber = 0)
			:LiaoException(("[FatalException-"+ exceptionName + "]").c_str(), methodSigniture, message, lineNumber)
		{}
		FatalException(string&& exceptionName, string&& methodSigniture, string&& message, long long lineNumber = 0)
			:LiaoException(("[FatalException-" + exceptionName + "]").c_str(), methodSigniture, message, lineNumber)
		{}
		FatalException(string&& exceptionName, string& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:LiaoException(("[FatalException-" + exceptionName + "]").c_str(), methodSigniture, message,fileLocation, lineNumber)
		{}
		FatalException(string&& exceptionName, string&& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:LiaoException(("[FatalException-" + exceptionName + "]").c_str(), methodSigniture, message, fileLocation, lineNumber)
		{}
		FatalException(string&& exceptionName, string&& methodSigniture, string&& message, string& fileLocation, long long lineNumber = 0)
			:LiaoException(("[FatalException-" + exceptionName + "]").c_str(), methodSigniture, message, fileLocation, lineNumber)
		{}
		FatalException(string&& exceptionName, string&& methodSigniture, string& message, string&& fileLocation, long long lineNumber = 0)
			:LiaoException(("[FatalException-" + exceptionName + "]").c_str(), methodSigniture, message, fileLocation, lineNumber)
		{}
		FatalException(string&& exceptionName, string&& methodSigniture, string&& message, string&& fileLocation, long long lineNumber = 0)
			:LiaoException(("[FatalException-" + exceptionName + "]").c_str(), methodSigniture, message, fileLocation, lineNumber)
		{}
	public:
		~FatalException()
		{
			instance.flashOut();
			this->toFile();
		}
	};
}

#endif
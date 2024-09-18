#ifndef COMMONEXCEPTION
#define COMMONEXCEPTION
#include "LiaoException.h"
namespace liaoInfor
{
#define COMMONEXCEPTION :public CommonException
	class CommonException:public LiaoException
	{
		CommonException(string& methodSigniture, string& message, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, lineNumber)
		{}
		CommonException(string&& methodSigniture, string& message, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, lineNumber)
		{}
		CommonException(string&& methodSigniture, string&& message, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, lineNumber)
		{}
		CommonException(string& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, fileLocation, lineNumber)
		{}
		CommonException(string&& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, fileLocation, lineNumber)
		{}
		CommonException(string&& methodSigniture, string&& message, string& fileLocation, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, fileLocation, lineNumber)
		{}
		CommonException(string&& methodSigniture, string& message, string&& fileLocation, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, fileLocation, lineNumber)
		{}
		CommonException(string&& methodSigniture, string&& message, string&& fileLocation, long long lineNumber = 0)
			:LiaoException("[CommonException]: ", methodSigniture, message, fileLocation, lineNumber)
		{}
		~CommonException()
		{
			instance.flashOut();
			this->toFile();
		}
	};
}
#endif

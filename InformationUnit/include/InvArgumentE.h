#ifndef INVALIDARGUMENTEXCEPTION
#define INVALIDARGUMENTEXCEPTION
#include "FatalException.h"
namespace liaoInfor
{
	class InvArgumentE FATALEXCEPTION
	{
	public:
		InvArgumentE(string& methodSigniture, string& message, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, lineNumber)
		{}
		InvArgumentE(string&& methodSigniture, string& message, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, lineNumber)
		{}
		InvArgumentE(string&& methodSigniture, string&& message, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, lineNumber)
		{}
		InvArgumentE(string& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvArgumentE(string&& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvArgumentE(string&& methodSigniture, string&& message, string& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvArgumentE(string&& methodSigniture, string& message, string&& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvArgumentE(string&& methodSigniture, string&& message, string&& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidArgument", methodSigniture, message, fileLocation, lineNumber)
		{}
	};
}

#endif
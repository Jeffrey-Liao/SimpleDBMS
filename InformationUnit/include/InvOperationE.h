#ifndef INVALIDOPERATIONEXCEPTION
#define INVALIDOPERATIONEXCEPTION
#include"FatalException.h"
namespace liaoInfor
{
	class InvOperationE FATALEXCEPTION
	{
	public:
		InvOperationE(string& methodSigniture, string& message, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, lineNumber)
		{}
		InvOperationE(string&& methodSigniture, string& message, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, lineNumber)
		{}
		InvOperationE(string&& methodSigniture, string&& message, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, lineNumber)
		{}
		InvOperationE(string& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvOperationE(string&& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvOperationE(string&& methodSigniture, string&& message, string& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvOperationE(string&& methodSigniture, string& message, string&& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, fileLocation, lineNumber)
		{}
		InvOperationE(string&& methodSigniture, string&& message, string&& fileLocation, long long lineNumber = 0)
			:FatalException("InvalidOperation", methodSigniture, message, fileLocation, lineNumber)
		{}
	};
}
#endif
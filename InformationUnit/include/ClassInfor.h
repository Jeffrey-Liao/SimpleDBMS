#ifndef CLASSINFOR_H
#define CLASSINFOR_H
#include "common.h"
namespace liaoInfor
{
	enum class ClassInforPart
	{
		ClassName,
		MethodName,
		ReturnType,
		ParameterList
	};
	class ClassInfor
	{
		using string = std::string;
		static ClassInfor* instance;
		void reallocate(const string& classInfor);
		void reconstruct(const string& classInfor)
		{
			className = classInfor.substr(0,classInfor.find_last_of("::")-1);
			className = className.substr(className.find_last_of(' ')+1);
			functionName = classInfor.substr(classInfor.find_last_of(':')+1, classInfor.find_first_of('(')- classInfor.find_last_of(':')-1);
			functionParameter = classInfor.substr(classInfor.find('(') + 1, classInfor.find(')')- classInfor.find('(') - 1);
			functionReturnType = classInfor.substr(0, classInfor.find_first_of('_'));
		}
		ClassInfor();
		ClassInfor(const string& classInfor);
		static void initializer()
		{
			if (instance == NULL)
				instance = new ClassInfor();
		}
		static void initializer(const string & dataInfor)
		{
			if (instance == NULL)
				instance = new ClassInfor(dataInfor);
		}
		string functionName;
		string className;
		string functionReturnType;
		string functionParameter;
	public:
		ClassInfor& updateInfor(const string& dataInfor);
		ClassInfor& updateInfor(const string&& dataInfor);
		ClassInfor& newInfor(const string& dataInfor);
		ClassInfor& newInfor(const string&& dataInfor);
		bool isNULL();
		const string& take(ClassInforPart part);
		string convertToString();
		static ClassInfor& getInstance()
		{
			initializer();
			return *instance;
		}
		const string& operator[](ClassInforPart part);
	};
}
#endif // !CLASSINFOR_H


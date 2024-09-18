#pragma once
#ifndef ERRORS_H
#define ERRORS_H
#include "Infor.h"
#include<exception>
namespace liaoInfor
{
	/*
	* the basic class of Liao exception system
	* it contains 2 members:
	*>>the type of exception belong to (given by subclasses)
	* >>the error message (given by subclasses too)
	* it contains 2 methods:
	* >>display(): print error message to the console
	* >>error(): export error message to error.log file
	*/
	class LiaoException:public std::runtime_error
	{
	protected:
		using string = std::string;
		Infor instance;
		string information;
		LiaoException(const char* exceptionNanme, string& methodSigniture, string& message, long long lineNumber = 0);
		LiaoException(const char* exceptionNanme, string&& methodSigniture, string& message, long long lineNumber = 0);
		LiaoException(const char* exceptionNanme, string&& methodSigniture, string&& message, long long lineNumber = 0);
		LiaoException(const char* exceptionNanme, string& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0);
		LiaoException(const char* exceptionNanme, string&& methodSigniture, string& message, string& fileLocation, long long lineNumber = 0);
		LiaoException(const char* exceptionNanme, string&& methodSigniture, string&& message, string& fileLocation, long long lineNumber = 0);
		LiaoException(const char* exceptionNanme, string&& methodSigniture, string& message, string&& fileLocation, long long lineNumber = 0);
		LiaoException(const char* exceptionNanme, string&& methodSigniture, string&& message, string&& fileLocation, long long lineNumber = 0);
		//输出错误信息到控制台
	public:
		const string& getFuncName();
		const string& getFuncType();
		const string& getParameterList();
		const string& getClassName();
		void printAll();
		void printErrorObjectInfor();
		void printFuncName();
		void printFuncType();
		void printParameterList();
		void printClassName();
		void toFile();
		virtual ~LiaoException();
	};
	//auto save error message
}
#endif
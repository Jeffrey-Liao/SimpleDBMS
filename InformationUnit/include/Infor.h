#ifndef INFOR_H
#define INFOR_H

#include "common.h"
#include "ClassInfor.h"
#include <format>
namespace liaoInfor
{
#define MESSAGEBREAK ""
#define INFORLABEL "[INFOR]"
#define DEBUGLABEL "[DEBUG]"
#define ERRORLABEL "[ERROR]"
#define EXCEPTIONLABEL "|>EXCEPTION<|"
#define THISLINE __LINE__
#define THISFILE __FILE__
#ifdef _WIN32
#define THISFUNC __FUNCSIG__
#else 
#define THISFUNC __PRETTY_FUNCTION__
#endif
	enum class InforType:char
	{
		Common,
		Debug,
		Error,
		Exception
	};
	/*provide 3 different output methods :
	* 1:display():print current message and switch line;
	* 2:print(): print current message but do not switch line
	* 3:send(): store given message and display stored messages at the death of object
	*/
	class Infor
	{
	protected:
		using string = std::string;
		using enum InforType;
		InforType currentType;
		mutable char bits;
		string Cache;
		static void switchLine()
		{
			cout << "\n";
		}
		constexpr const char* getLabel()const;
		constexpr bool whenActive()const;
	public:
		Infor(InforType currentType = Common);
		Infor(InforType currentType, bool useDefaultProcess);
		static string getTime(/*only show date if it is true*/bool onlyDate = false) noexcept
		{
			string timeMessage;
			time_t now = std::time(NULL);
			tm timeStru;
			localtime_s(&timeStru, &now);
			string datePart;
			string timePart;
			datePart = STD to_string(timeStru.tm_year + 1900);
			datePart += "-";
			if (timeStru.tm_mon < 10)
				datePart += STD to_string(0) + STD to_string(timeStru.tm_mon + 1);
			else
				datePart += STD to_string(timeStru.tm_mon);
			datePart += "-";
			if (timeStru.tm_mday < 10)
				datePart += STD to_string(0) + STD to_string(timeStru.tm_mday);
			else
				datePart += STD to_string(timeStru.tm_mday);
			timeMessage = "[" + datePart;
			if (!onlyDate)
			{
				if (timeStru.tm_hour < 10)
					timePart = STD to_string(0) + STD to_string(timeStru.tm_hour);
				else
					timePart = STD to_string(timeStru.tm_hour);
				timePart += ":";
				if (timeStru.tm_min < 10)
					timePart += STD to_string(0) + STD to_string(timeStru.tm_min);
				else
					timePart += STD to_string(timeStru.tm_min);
				timePart += ":";
				if (timeStru.tm_sec < 10)
					timePart += STD to_string(0) + STD to_string(timeStru.tm_sec);
				else
					timePart += STD to_string(timeStru.tm_sec);
				timeMessage += "  " + timePart ;
			}
			return timeMessage+="]";
		}
		static string Log(const char* message,bool useTimeStamp = true)
		{
			string str = Print(message, useTimeStamp);
			cout <<"\n";
			return str+="\n";
		}
		static string Print(const char* message, bool useTimeStamp=false)
		{
			string str;
			if (useTimeStamp)
				cout << (str=getTime());
			cout << message << "\n";
			str += message;
			return str += "\n";
		}
		static string Debug(const char* classInfor, long long line = 0)
		{
			string str;
			ClassInfor::getInstance().newInfor(classInfor);
			cout << (str=ClassInfor::getInstance().convertToString());
			if (line > 0)
				cout<<"line number: " << line;
			return str += "line number" + std::to_string(line);
		}
		string log(const string& message, bool useTimeStamp = true)const;
		string log(string&& message, bool useTimeStamp = true)const;
		string log(const char* classInformation, const string& message, bool useTimeStamp = true)const;
		string log(const char* classInformation, string&& message, bool useTimeStamp = true) const;
		string print(const string& message, bool useTimeStamp = false)const;
		string print(string&& message, bool useTimeStamp = false)const;
		string print(const char* classInformation, const string& message, bool useTimeStamp = false) const;
		string print(const char* classInformation, string&& message, bool useTimeStamp = false) const;
		Infor& time();
		Infor& label();
		Infor& append(string&& message);
		Infor& append(string& message);
		Infor& classInfor(string& funcSig);
		void end();
		Infor& when(bool condition);
		void toFile(string& fileName);
		void toFile(string&& fileName);
		Infor& operator<<(string& message);
		Infor& operator<<(const char* message);
		DYNAMIC
		Infor& operator<<(T& value)
		{
			Cache += std::to_string(value);
			return *this;
		}
		string flashOut();
		void clear();
		const string& getCache() const;
		Infor& head();
		~Infor();
	};
}
#endif
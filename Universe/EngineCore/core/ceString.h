#pragma once

#include "precompiled.h"

namespace ce
{
	using ConstCharPtr = const char*;
	class String
	{
	private:
		std::string data;
	public:
		String() :data("")
		{}

		String(const char* str) :data(str)
		{}

		friend const char* operator<<(std::ostream&, String& str)
		{
			return str.data.c_str();
		}

		template<typename T>
		String& operator+(T&val)
		{
			std::stringstream ss;
			ss << val;
			std::string str;
			ss >> str;
			data.append(str);
			return *this;
		}
	};

	template<>
	String& String::operator+<const char*>(const char*& val)
	{
		data.append(val);
		return *this;
	}
}




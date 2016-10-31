//! \file		Assert.h
//! \brief
//! \detail
//! \author		sehyun

#pragma once

#include <stdio.h>
#include <crtdbg.h>
#include <stdarg.h>



inline void Assertion(const char* file, int line, const char* module, const char* format, ...)
{
	char temp[1024];
	va_list list;
	va_start(list, format);
	vsprintf_s(temp, 1024, format, list);
	va_end(list);

	int RetVal = _CrtDbgReport(_CRT_ASSERT, file, line, module, temp);
	if (1 != RetVal)
	{
		__debugbreak();
	}
}


#if defined(_DEBUG)
#define ASSERT_C(condition, expression, ...)															\
	if(!(condition))																					\
		Assertion(__FILE__, __LINE__, nullptr, expression, __VA_ARGS__);

#define ASSERT_FALSE(condition, expression, ...)														\
	if (!(condition))																					\
		ASSERT_C(condition, expression, __VA_ARGS__);													\
		return false;																					\
	return true;

#else
#define ASSERT_C(condition, expression, ...)
#define ASSERT_FALSE(condition, expression, ...)														\
	if(!(condition))																					\
		return false;																					\
	return true;

#endif


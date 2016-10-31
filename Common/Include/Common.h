//! \file		Common.h
//! \brief
//! \detail
//! \author		sehyun


#pragma once

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


#if defined(COMMON_EXPORTS)
	#define COMMON_API	__declspec(dllexport)
#else
	#define	COMMON_API	__declspec(dllimport)
#endif


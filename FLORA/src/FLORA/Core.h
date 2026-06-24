#pragma once

#ifdef FL_PLATFORM_WINDOWS
	#ifdef FL_BUILD_DLL
		#define FLORA_API __declspec(dllexport)
	#else
		#define FLORA_API __declspec(dllimport)
	#endif
#else
	#error FLORA only support Windows!
#endif 

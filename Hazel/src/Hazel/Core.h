#pragma once

#define BIT(num) (0x00000001<<(num)) 

#ifdef HZ_PLATFORM_WINDOWS

	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif


#else

	#error Hazel Engine only supports Windows

#endif
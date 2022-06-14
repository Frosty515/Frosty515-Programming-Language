#pragma once

#ifdef F515_PLATFORM_WINDOWS
	#ifdef F515_BUILD_DLL
		#define FROSTY515_API __declspec(dllexport)
	#else
		#define FROSTY515_API __declspec(dllimport)
	#endif
#else
	#error Frosty515 FileIO only supports Windows
#endif
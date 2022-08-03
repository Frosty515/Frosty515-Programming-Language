#ifndef _STDLOGGER_CORE_H
#define _STDLOGGER_CORE_H

#ifdef F515_PLATFORM_WINDOWS
	#ifdef F515_BUILD_DLL
		#define FROSTY515_API __declspec(dllexport)
	#else
		#define FROSTY515_API __declspec(dllimport)
	#endif
#else
	#ifdef F515_PLATFORM_LINUX
		#ifdef F515_BUILD_SO
			#define FROSTY515_API 
		#else
			#define FROSTY515_API 
		#endif
	#else
		#error Frosty515 FileIO only supports Windows and Linux
	#endif
#endif

#endif /* _STDLOGGER_CORE_H */
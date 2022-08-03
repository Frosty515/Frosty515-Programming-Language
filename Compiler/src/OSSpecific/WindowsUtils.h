#ifndef _WINDOWS_UTILS_H
#define _WINDOWS_UTILS_H

#ifdef F515_PLATFORM_WINDOWS

#include <Windows.h>
#include <string>
#include <stdint.h>

#include <StandardLogger.h>

namespace F515_OSSpecific {

	class WindowsUtils {
	public:
		WindowsUtils();
		~WindowsUtils();

		void RunProcess(std::string cmdline, std::string startDirectory = std::to_string(NULL), uint32_t flags = 0, bool waitForProcessToComplete = false);
	
	private:
		F515_StandardLogger::Logger m_Logger;
	};

}

#endif

#endif
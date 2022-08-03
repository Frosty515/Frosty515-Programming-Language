#ifdef F515_PLATFORM_WINDOWS
#include "WindowsUtils.h"

namespace F515_OSSpecific {

	WindowsUtils::WindowsUtils() {
        m_Logger.setLoggerLevel((int)F515_StandardLogger::LoggerLevels::INFO);
        m_Logger.info("WindowsUtils initialized");
	}
	WindowsUtils::~WindowsUtils() {

	}

	void WindowsUtils::RunProcess(std::string cmdline, std::string startDirectory, DWORD flags, bool waitForProcessToComplete) {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        std::wstring temp(cmdline.begin(), cmdline.end());
        std::wstring temp2(startDirectory.begin(), startDirectory.end());

        // Start the child process. 
        if (!CreateProcess(NULL, &temp[0], NULL, NULL, FALSE, flags, NULL, &temp2[0], &si, &pi)) {
            std::string error = "Error " + std::to_string(GetLastError()) + " occurred while attempting to create Windows process!"; //tostring
            m_Logger.error(error);
            return;
        }

        if (waitForProcessToComplete)
            WaitForSingleObject(pi.hProcess, INFINITE);

        // Close process and thread handles. 
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
	}

}
#endif
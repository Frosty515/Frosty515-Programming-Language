#ifndef _LINUX_UTILS_H
#define _LINUX_UTILS_H

#ifdef F515_PLATFORM_LINUX

#include <stdint.h>
#include <string>
#include <thread>

namespace F515_OSSpecific {

    class LinuxUtils {
    public:
        LinuxUtils();
        ~LinuxUtils();

        uint64_t RunProccess(std::string cmdline, std::string startDirectory, uint32_t flags, bool waitForProcessToComplete);

    private:
        std::thread m_Thread;
    };

}

#endif /* F515_PLATFORM_LINUX */

#endif /* _LINUX_UTILS_H */
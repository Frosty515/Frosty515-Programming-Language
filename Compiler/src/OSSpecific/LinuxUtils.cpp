#include "LinuxUtils.h"

#ifdef F515_PLATFORM_LINUX

#include <cstdio>
#include <sstream>

namespace F515_OSSpecific {

    std::string m_Process;

    void Run();

    LinuxUtils::LinuxUtils() {
    }

    LinuxUtils::~LinuxUtils() {

    }

    uint64_t LinuxUtils::RunProccess(std::string cmdline, std::string startDirectory, uint32_t flags, bool waitForProcessToComplete) {
        std::stringstream ss;
        ss << "bash -c \"";
        if (startDirectory.length() != 0)
            ss << "cd " << startDirectory << " && ";
        ss << cmdline << '\"';

        if (waitForProcessToComplete)
            return system(ss.str().c_str());
        else {
            m_Process = ss.str();
            m_Thread = std::thread(Run);
        }

        return 0;
    }

    /* Private methods */

    void Run() {
        system(m_Process.c_str());
    }
    
}

#endif /* F515_PLATFORM_LINUX */

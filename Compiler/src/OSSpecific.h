#ifndef _OS_SPECIFIC_H
#define _OS_SPECIFIC_H

#ifdef F515_PLATFORM_WINDOWS
    #include "OSSpecific/WindowsUtils.h"
        namespace F515_OSSpecific {
            typedef WindowsUtils OSUtils;
        }
#else
    #ifdef F515_PLATFORM_LINUX
        #include "OSSpecific/LinuxUtils.h"
        namespace F515_OSSpecific {
            typedef LinuxUtils OSUtils;
        }
    #else
        #error Only Windows and Linux are supported
    #endif
#endif

#endif /* _OS_SPECIFIC_H */
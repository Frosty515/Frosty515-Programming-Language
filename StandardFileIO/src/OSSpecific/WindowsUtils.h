#ifndef _STDFILEIO_WINDOWS_UTILS_H
#define _STDFILEIO_WINDOWS_UTILS_H

#ifdef F515_PLATFORM_WINDOWS

#include "../Core.h"
#include <stdint.h>
#include <string>

namespace F515_StandardFileIO_OSSpecific {
    class FROSTY515_API WindowsUtils {
    public:
        WindowsUtils();
        ~WindowsUtils();

        uint64_t _MKDIR(const std::string& path);
        uint64_t _MKDIR(const char* path);

        uint64_t _RMDIR(const std::string& path);
        uint64_t _RMDIR(const char* path);
    };
}

#endif /* F515_PLATFORM_WINDOWS */

#endif /* _STDFILEIO_LINUX_UTILS_H */
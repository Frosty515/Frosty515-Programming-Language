#include "WindowsUtils.h"

#ifdef F515_PLATFORM_WINDOWS

#include <direct.h>

namespace F515_StandardFileIO_OSSpecific {

    WindowsUtils::WindowsUtils() {

    }

    WindowsUtils::~WindowsUtils() {

    }

    uint64_t WindowsUtils::_MKDIR(const std::string& path) {
        return _mkdir(path.c_str());
    }

    uint64_t WindowsUtils::_MKDIR(const char* path) {
        return _mkdir(path);
    }

    uint64_t WindowsUtils::_RMDIR(const std::string& path) {
        return _rmdir(path.c_str());
    }

    uint64_t WindowsUtils::_RMDIR(const char* path) {
        return _rmdir(path);
    }

};

#endif /* F515_PLATFORM_WINDOWS */

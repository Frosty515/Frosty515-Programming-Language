#include "LinuxUtils.h"

#ifdef F515_PLATFORM_LINUX

#include <sys/stat.h>

namespace F515_StandardFileIO_OSSpecific {

    LinuxUtils::LinuxUtils() {

    }

    LinuxUtils::~LinuxUtils() {

    }

    uint64_t LinuxUtils::_MKDIR(const std::string& path) {
        return mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }

    uint64_t LinuxUtils::_MKDIR(const char* path) {
        return mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }

    uint64_t LinuxUtils::_RMDIR(const std::string& path) {
        return remove(path.c_str());
    }

    uint64_t LinuxUtils::_RMDIR(const char* path) {
        return remove(path);
    }

}

#endif /* F515_PLATFORM_LINUX */
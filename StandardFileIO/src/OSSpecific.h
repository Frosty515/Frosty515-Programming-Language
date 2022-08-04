#ifndef _STDFILEIO_OSSPECIFIC_H
#define _STDFILEIO_OSSPECIFIC_H

#ifdef F515_PLATFORM_WINDOWS
    #include "OSSpecific/WindowsUtils.h"
    namespace F515_StandardFileIO_OSSpecific {
        typedef WindowsUtils OSUtils;
    }
#else
    #include "OSSpecific/LinuxUtils.h"
    namespace F515_StandardFileIO_OSSpecific {
        typedef LinuxUtils OSUtils;
    }
#endif

#endif /* _STDFILEIO_OSSPECIFIC_H */
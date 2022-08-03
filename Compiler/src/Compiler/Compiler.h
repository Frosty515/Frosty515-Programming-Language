#ifndef _COMPILER_H
#define _COMPILER_H

#include <stdint.h>
#include <string>

#include "../Parser/Parser.h"

namespace F515_Compiler {

    class Compiler {
    public:
        Compiler();
        ~Compiler();

        uint64_t compile(F515_Parser::Node in, std::string* out);
    };

}

#endif /* _COMPILER_H */
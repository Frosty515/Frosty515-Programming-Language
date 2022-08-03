#ifndef _LEXER_H
#define _LEXER_H

#include <stdint.h>
#include <vector>


namespace F515_Parser {

    struct Item {
        uint64_t   type;
        uint64_t   size;
        uint8_t   *bytes;
    };

    enum class Types {
        /* TODO */
    };

    typedef std::vector<Item> ItemList;

    class Lexer {
    public:
        Lexer();
        ~Lexer();

        uint64_t convert(uint8_t* in, uint64_t inSize, ItemList* out); /* TODO: Complete definition */
    };

}

#endif /* _LEXER_H */
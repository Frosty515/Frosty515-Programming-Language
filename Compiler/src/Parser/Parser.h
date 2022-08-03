#ifndef _PARSER_H
#define _PARSER_H

#include "Lexer.h"

#define SUCCESS 0
#define BAD_ARGS 1
#define MEM_ERROR 2

/* 

TODO:

complete definition for F515_Parser::Parser::parse
add all the different errors

Resources:

https://youtu.be/S90a2_UyO5w?t=90

*/


namespace F515_Parser {

    struct Node {
        uint8_t  type;
        Item     data;
        uint64_t SubNodesCount;
        Node*    SubNodes;
    };

    class Parser {
    public:
        Parser();
        ~Parser();

        uint64_t parse(ItemList in, Node* out);
    };

}

#endif /* _PARSER_H */
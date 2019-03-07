#ifndef ast_identifier_list_hpp
#define ast_identifier_list_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Identifier_list
    : public Tree
{

private:
    std::String* identifier;
    Identifier_list* ident_list;
public:
    virtual ~Identifier_list() {}

    Identifier_list(
        std::String* identifier_in,
        Identifier_list* ident_list_in) :
        identifier(identifier_in),
        ident_list(ident_list_in) {}
};

#endif

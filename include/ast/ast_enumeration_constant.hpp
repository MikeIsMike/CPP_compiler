#ifndef ast_enumeration_constant_hpp
#define ast_enumeration_constant_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Enumeration_constant
    : public Tree
{

private:
    std::String* identifier;
public:
    virtual ~Enumeration_constant() {}

    Enumeration_constant(
        std::String* identifier_in) :
        identifier(identifier_in){}
};

#endif

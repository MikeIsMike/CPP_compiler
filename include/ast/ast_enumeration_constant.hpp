#ifndef ast_enumeration_constant_hpp
#define ast_enumeration_constant_hpp

#include "ast_tree.hpp"
#include <string>




class Enumeration_constant
    : public Tree
{

private:
    std::string* identifier;
public:
    virtual .* {}
    virtual void print_python(std::ostream &dst) const;

    Enumeration_constant(
        std::string* identifier_in) :
        identifier(identifier_in){}
};

#endif

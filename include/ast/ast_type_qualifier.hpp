#ifndef ast_type_qualifier_hpp
#define ast_type_qualifier_hpp

#include "ast_tree.hpp"
#include <string>




class Type_qualifier
    : public Tree
{

private:
    std::string* type_qualifier;
public:
    virtual .* {}
    virtual void print_python(std::ostream &dst) const;

    Type_qualifier(std::string* type_qualifier_in) : type_qualifier(type_qualifier_in) {}
};

#endif

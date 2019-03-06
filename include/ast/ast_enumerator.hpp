#ifndef ast_enumerator_hpp
#define ast_enumerator_hpp

#include "ast_tree.hpp"
#include <string>




class Enumerator
    : public Tree
{

private:
    Enumeration_constant* enum_constant;
    Constant_expression* cont_expr;
public:
    virtual ~Enumerator() {}

    Enumerator(
        Enumeration_constant* enum_constant_in,
        Constant_expression* cont_expr_in) :
        enum_constant(enum_constant_in),
        cont_expr(cont_expr_in){}
};

#endif

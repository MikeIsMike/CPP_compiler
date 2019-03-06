#ifndef ast_cast_expression_hpp
#define ast_cast_expression_hpp

#include "ast_tree.hpp"
#include <string>




class Cast_expression
    : public Tree
{

private:
    Unary_expression* unary_expr;
    Type_name* type_name;
    Cast_expression* cast_expr;

public:
    virtual ~Cast_expression() {}

    Cast_expression(
        Unary_expression* unary_expr_in,
        Type_name* type_name_in,
        Cast_expression* cast_expr_in):
        unary_expr(unary_expr_in),
        type_name(type_name_in),
        cast_expr(cast_expr_in) {}
};

#endif

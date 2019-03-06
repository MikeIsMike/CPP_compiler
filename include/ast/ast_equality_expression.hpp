#ifndef ast_equality_expression_hpp
#define ast_equality_expression_hpp

#include "ast_tree.hpp"
#include <string>




class Equality_expression
    : public Tree
{

private:
    Relational_expression* relat_expr;
    Equality_expression* equality_expr;
    std::string* op;
public:
    virtual ~Equality_expression() {}

    Equality_expression(
        Relational_expression* relat_expr_in,
        Equality_expression* equality_expr_in,
        std::string* op_in):
        relat_expr(relat_expr_in),
        equality_expr(equality_expr_in),
        op(op_in) {}
};

#endif
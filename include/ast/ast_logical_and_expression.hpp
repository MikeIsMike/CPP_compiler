#ifndef ast_logical_and_expression_hpp
#define ast_logical_and_expression_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Logical_or_expression
    : public Tree
{

private:
    Inclusive_or_expression* inclusive_or_expr;
    Logical_and_expression* logical_and_expr;
public:
    virtual ~Logical_and_expression() {}

    Logical_and_expression(
        Inclusive_or_expression* inclusive_or_expr_in,
        Logical_and_expression* logical_or_expr_in) :
        inclusive_or_expr(inclusive_or_expr_in),
        logical_and_expr(logical_and_expr_in) {}
};

#endif

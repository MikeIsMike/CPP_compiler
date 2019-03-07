#ifndef ast_exclusive_or_expression_hpp
#define ast_exclusive_or_expression_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Exclusive_or_expression
    : public Tree
{

private:
    And_expression* and_expr;
    Exclusive_or_expression* exclusive_or_expr;
public:
    virtual ~Exclusive_or_expression() {}

    Exclusive_or_expression(
        And_expression* and_expr_in,
        Exclusive_or_expression* exclusive_or_expr_in) :
        and_expr(and_expr_in),
        exclusive_or_expr(exclusive_or_expr_in) {}
};

#endif

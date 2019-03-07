#ifndef ast_conditional_expression_hpp
#define ast_conditional_expression_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Conditional_expression
    : public Tree
{

private:
    Logical_or_expression* logic_or_expr;
    Expression* expr;
    Conditional_expression* cond_expr;
public:
    virtual ~Conditional_expression() {}

    Conditional_expression(Logical_or_expression* logic_or_expr_in, Expression* expr_in, Conditional_expression* cond_expr_in) : logic_or_expr(logic_or_expr_in), expr(expr_in), cond_expr(cond_expr_in){}
};

#endif

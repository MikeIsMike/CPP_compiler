#ifndef ast_constant_expression_hpp
#define ast_constant_expression_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Constant_expression
    : public Tree
{

private:
    Conditional_expression* cond_expr;
public:
    virtual ~Constant_expression() {}

    Constant_expression(Conditional_expression* cond_expr_in) : cond_expr(cond_expr_in){}
};

#endif

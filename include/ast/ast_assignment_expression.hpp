#ifndef ast_assignment_expression_hpp
#define ast_assignment_expression_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Assignment_expression
    : public Tree
{

private:
    Conditional_expression* cond_expr;
    Unary_expression* unary_expr;
    Assignment_operator* assign_op;
    Assignment_expression* assign_expr;
public:
    virtual ~Assignment_expression() {}

    Assignment_expression(Conditional_expression* cond_expr_in, Unary_expression* unary_expr_in, Assignment_operator* assign_op_in, Assignment_expression* assign_expr_in) : cond_expr(cond_expr_in), unary_expr(unary_expr_in), assign_op(assign_op_in), assign_expr(assign_expr_in){}
};

#endif

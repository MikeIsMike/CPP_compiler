#ifndef ast_expression_hpp
#define ast_expression_hpp

#include "ast_tree.hpp"
#include"ast_assignment_expression.hpp"
#include <string>




class Expression
    : public Tree
{

private:
    Assignment_expression* assign_expr;
    Expression* expr;
public:
    virtual ~Expression() {}
    virtual void print_python(std::ostream &dst) const{};

    Expression(
        Assignment_expression* assign_expr_in,
        Expression* expr_in) :
        assign_expr(assign_expr_in),
        expr(expr_in){}
};

#endif

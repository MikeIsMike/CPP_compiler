#ifndef ast_additive_expression_hpp
#define ast_additive_expression_hpp

#include "ast_tree.hpp"
#include <string>




class Additive_expression
    : public Tree
{

private:
    Multiplicative_expression* mult_expr;
    Additive_expression* additive_expr;
    std::string* op;

public:
    virtual ~Additive_expression() {}

    Additive_expression(
        Multiplicative_expression* mult_expr_in,
        Additive_expression* additive_expr_in,
        std::string* op_in):
        mult_expr(mult_expr_in),
        additive_expr(additive_expr_in),
        op(op_in) {}
};

#endif

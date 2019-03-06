#ifndef ast_shift_expression_hpp
#define ast_shift_expression_hpp

#include "ast_tree.hpp"
#include <string>




class Shift_expression
    : public Tree
{

private:
    Additive_expression* additive_expr;
    Shift_expression* shift_expr;
    std::string* op;

public:
    virtual ~Shift_expression() {}

    Shift_expression(
        Additive_expression* additive_expr_in,
        Shift_expression* shift_expr_in,
        std::string* op_in):
        additive_expr(additive_expr_in),
        shift_expr(shift_expr_in),
        op(op_in) {}
};

#endif
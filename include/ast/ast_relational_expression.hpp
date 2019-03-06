#ifndef ast_relational_expression_hpp
#define ast_relational_expression_hpp

#include "ast_tree.hpp"
#include <string>




class Relational_expression
    : public Tree
{

private:
    Shift_expression* shift_expr;
    Relational_expression* relat_expr;
    std::string* op;

public:
    virtual ~Relational_expression() {}

    Relational_expression(
        Shift_expression* shift_expr_in,
        Relational_expression* relat_expr_in,
        std::string* op_in):
        shift_expr(shift_expr_in),
        relat_expr(relat_expr_in),
        op(op_in) {}
};

#endif
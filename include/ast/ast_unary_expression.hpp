#ifndef ast_unary_expression_hpp
#define ast_unary_expression_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Unary_expression
    : public Tree
{

private:
    Postfix_expression* postf_expr;
    std::String operator;
    Unary_expression* unary_expr;
    std::String* unary_op;
    Cast_expression* cast_expr;
    Type_name* type_name;

public:
    virtual ~Unary_expression() {}

    Unary_expression(
        Postfix_expression* postf_expr_in,
        std::String operator_in,
        Unary_expression* unary_expr_in,
        std::String* unary_op_in,
        Cast_expression* cast_expr_in,
        Type_name* type_name_in) :
        postf_expr(postf_expr_in),
        operator(operator_in),
        unary_expr(unary_expr_in),
        unary_op(unary_op_in),
        cast_expr(cast_expr_in),
        type_name(type_name_in)
        {}
};

#endif

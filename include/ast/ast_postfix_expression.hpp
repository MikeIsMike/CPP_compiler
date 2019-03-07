#ifndef ast_postfix_expression_hpp
#define ast_postfix_expression_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Postfix_expression
    : public Tree
{

private:
    Primary_expression* prim_expr;
    Postfix_expression* postf_expr;
    Expression* expr;
    Argument_expression_list* arg_expr_list;
    std::String operator;
    std::String identifier;

public:
    virtual ~Postfix_expression() {}

    Postfix_expression(
        Primary_expression* prim_expr_in,
        Postfix_expression* postf_expr_in,
        Expression* expr_in,
        Argument_expression_list* arg_expr_list_in,
        std::String operator_in,
        std::String identifier_in) :
        prim_expr(prim_expr_in),
        postf_expr(postf_expr_in),
        expr(expr_in),
        arg_expr_list(arg_expr_list_in),
        operator(operator_in),
        identifier(identifier_in)
        {}
};

#endif

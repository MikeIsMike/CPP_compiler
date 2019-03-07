#ifndef ast_iteration_statement_hpp
#define ast_iteration_statement_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Iteration_statement
    : public Tree
{

private:
    Expression* expr;
    Statement* statement;
    Expression_statement* expr_stmnt_1;
    Expression_statement* expr_stmnt_2;
    std::String* keyword;

public:
    virtual ~Iteration_statement() {}

    Iteration_statement(
        Expression* expr_in,
        Statement* statement_in,
        Expression_statement* expr_stmnt_1_in,
        Expression_statement* expr_stmnt_2_in,
        std::String* keyword_in) :
        expr(expr_in),
        statement(statement_in),
        expr_stmnt_1(expr_stmnt_1_in),
        expr_stmnt_2(expr_stmnt_2_in),
        keyword(keyword_in) {}
};

#endif

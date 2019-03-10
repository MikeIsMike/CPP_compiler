#ifndef ast_expression_statement_hpp
#define ast_expression_statement_hpp

#include "ast_tree.hpp"
#include "ast_expression.hpp"
#include <string>




class Expression_statement
    : public Tree
{

private:
    Expression* expr;

public:
    virtual ~Expression_statement() {}
    virtual void print_python(std::ostream &dst) {};

    Expression_statement(
        Expression* expr_in) :
        expr(expr_in) {}
};

#endif

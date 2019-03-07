#ifndef ast_labeled_statement_hpp
#define ast_labeled_statement_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Labeled_statement
    : public Tree
{

private:
    std::String* identifier;
    Statement* stmnt;
    Constant_expression* cont_expr;

public:
    virtual ~Labeled_statement() {}

    Labeled_statement(
        std::String* identifier_in,
        Statement* stmnt_in,
        Constant_expression* cont_expr_in) :
        identifier(identifier_in),
        stmnt(stmnt_in),
        cont_expr(cont_expr_in) {}
};

#endif

#ifndef ast_statement_list_hpp
#define ast_statement_list_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Statement_list
    : public Tree
{

private:
    Statement_list* stmnt_list;
    Statement* stmnt;
public:
    virtual ~Statement_list() {}

    Statement_list(
        Statement_list* stmnt_list_in,
        Statement* stmnt_in) :
        stmnt_list(stmnt_list_in),
        stmnt(stmnt_in) {}
};

#endif

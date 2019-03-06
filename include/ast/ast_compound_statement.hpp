#ifndef ast_compound_statement_hpp
#define ast_compound_statement_hpp

#include "ast_tree.hpp"
#include <string>




class Compound_statement
    : public Tree
{

private:
    Statement_list* stmnt_list;
    Declaration_list* decl_list;
public:
    virtual ~Compound_statement() {}

    Compound_statement(
        Statement_list* stmnt_list_in,
        Declaration_list* decl_list_in) :
        stmnt_list(stmnt_list_in),
        decl_list(decl_list_in) {}
};

#endif

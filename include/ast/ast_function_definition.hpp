#ifndef ast_function_definition_hpp
#define ast_function_definition_hpp

#include "ast_tree.hpp"
#include "ast_declarator.hpp"
#include "ast_declaration_specifiers.hpp"
#include "ast_compound_statement.hpp"
#include "ast_declaration_list.hpp"
#include <string>




class Function_definition
    : public Tree
{

private:
    Declarator* decl;
    Declaration_specifiers* decl_spec;
    Compound_statement* compound_stmnt;
    Declaration_list* decl_list;
public:
    virtual ~Function_definition() {}

    Function_definition(
        Declaration_specifiers* decl_spec_in,
        Declarator* decl_in,
        Compound_statement* compound_stmnt_in,
        Declaration_list* decl_list_in) :
        decl_spec(decl_spec_in),
        decl(decl_in),
        compound_stmnt(compound_stmnt_in),
        decl_list(decl_list_in) {}
};

#endif

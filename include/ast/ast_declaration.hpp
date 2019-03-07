#ifndef ast_declaration_hpp
#define ast_eclaration_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"




class Declaration
    : public Tree
{

protected:
    Declaration_specifiers* decl_spec;
	Init_declarator_list* decl_list;
public:
    virtual ~Declaration() {}

    Declaration(Declaration_specifiers* decl_spec_in, Init_declarator_list* decl_list_in) : decl_spec(decl_list_in),  decl_list(decl_list_in) {}
};

#endif

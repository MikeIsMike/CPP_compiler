#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include "ast_tree.hpp"
#include "ast_declaration_specifiers.hpp"
#include "ast_init_declarator_list.hpp"



class Declaration
    : public Tree
{

protected:
    Declaration_specifiers* decl_spec;
	Init_declarator_list* decl_list;
public:
    virtual .* {}
    virtual void print_python(std::ostream &dst) const;

    Declaration(
        Declaration_specifiers* decl_spec_in,
        Init_declarator_list* decl_list_in) :
        decl_spec(decl_spec_in),
        decl_list(decl_list_in) {}
};

#endif

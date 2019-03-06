#ifndef ast_parameter_declaration_hpp
#define ast_parameter_declaration_hpp

#include "ast_tree.hpp"
#include <string>




class Parameter_declaration
    : public Tree
{

private:
    Declaration_specifiers* decl_spec;
    Declarator* declarator;
    Abstract_declarator* abstr_decl;

public:
    virtual ~Parameter_declaration() {}

    Parameter_declaration(
        Declaration_specifiers* decl_spec_in,
        Declarator* declarator_in,
        Abstract_declarator* abstr_decl;
        ) :
        decl_spec(decl_spec_in),
        declarator(declarator_in),
        abstr_decl(abstr_decl_in) {}
};

#endif

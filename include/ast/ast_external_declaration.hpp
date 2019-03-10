#ifndef ast_external_declaration_hpp
#define ast_external_declaration_hpp

#include "ast_tree.hpp"
#include "ast_function_definition.hpp"
#include "ast_declaration.hpp"




class External_declaration
    : public Tree
{

protected:
    Function_definition* funct_def;
	Declaration* decl;
	// External_declaration* external_decl;
	// std::string* preprocessor_ptr;
public:
    virtual ~External_declaration() {}

    External_declaration(
        Function_definition* funct_def_in,
        Declaration* decl_in) :
        funct_def(funct_def_in),
        decl(decl_in) {
        // external_decl = NULL;
        // preprocessor_ptr = NULL;
    }
};

#endif

#ifndef ast_declaration_list_hpp
#define ast_declaration_list_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Declaration_list
    : public Tree
{

private:
    Declaration* decl;
    Declaration_list* decl_list;
public:
    virtual ~Declaration_list() {}

    Declaration_list(
        Declaration* decl_in,
        Declaration_list* decl_list_in) :
        decl(decl_in),
        decl_list(decl_list_in){}
};

#endif

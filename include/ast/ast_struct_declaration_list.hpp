#ifndef ast_struct_declaration_list_hpp
#define ast_struct_declaration_list_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Struct_declaration_list
    : public Tree
{

private:
    Struct_declaration* struct_decl;
    Struct_declaration_list* struct_decl_list;
public:
    virtual ~Struct_declaration_list() {}

    Struct_declaration_list(
        Struct_declaration* struct_decl_in,
        Struct_declaration_list* struct_decl_list_in) :
        struct_decl(struct_decl_in),
        struct_decl_list(struct_decl_list_in) {}
};

#endif

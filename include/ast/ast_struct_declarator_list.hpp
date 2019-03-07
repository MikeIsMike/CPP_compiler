#ifndef ast_struct_declarator_list_hpp
#define ast_struct_declarator_list_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Struct_declarator_list
    : public Tree
{

private:
    Struct_declarator* struct_decl;
    Struct_declarator_list* struct_decl_list;
public:
    virtual ~Struct_declarator_list() {}

    Struct_declarator_list(
        Struct_declarator* struct_decl_in,
        Struct_declarator_list* struct_decl_list_in) :
        struct_decl(struct_decl_in),
        struct_decl_list(struct_decl_list_in) {}
};

#endif

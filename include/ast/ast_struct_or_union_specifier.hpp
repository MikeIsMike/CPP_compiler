#ifndef ast_struct_or_union_specifier_hpp
#define ast_struct_or_union_specifier_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Struct_or_union_specifier
    : public Tree
{

private:
    std::string* identifier;
    Struct_declaration_list* struct_decl_list;
public:
    virtual ~Struct_or_union_specifier() {}

    Struct_or_union_specifier(
        std::string* identifier_in,
        Struct_declaration_list* struct_decl_list_in) :
        identifier(identifier_in),
        struct_decl_list(struct_decl_list_in) {}
};

#endif

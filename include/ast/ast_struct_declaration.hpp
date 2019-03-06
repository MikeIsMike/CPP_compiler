#ifndef ast_struct_declaration_hpp
#define ast_struct_declaration_hpp

#include "ast_tree.hpp"
#include <string>




class Struct_declaration
    : public Tree
{

private:
    Specifier_qualifier_list* spec_qual_list;
    Struct_declarator_list* struct_declarator_list;
public:
    virtual ~Struct_declaration() {}

    Struct_declaration(
        Specifier_qualifier_list* spec_qual_list_in,
        Struct_declarator_list* struct_declarator_list_in) :
        spec_qual_list(spec_qual_list_in),
        struct_declarator_list(struct_declarator_list_in) {}
};

#endif

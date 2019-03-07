#ifndef ast_type_name_hpp
#define ast_type_name_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Type_name
    : public Tree
{

private:
    Specifier_qualifier_list* spec_qual_list;
    Abstract_declarator* abstr_decl;
public:
    virtual ~Type_name() {}

    Type_name(
        Specifier_qualifier_list* spec_qual_list_in,
        Abstract_declarator* abstr_decl_in) :
        spec_qual_list(spec_qual_list_in),
        abstr_decl(abstr_decl_in) {}
};

#endif

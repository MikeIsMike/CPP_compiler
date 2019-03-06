#ifndef ast_declaration_specifiers_hpp
#define ast_declaration_specifiers_hpp

#include "ast_tree.hpp"




class Declaration_specifiers
    : public Tree
{

protected:
    Storage_class_specifier* stor_class_spec;
    Type_specifier* type_spec;
    Type_qualifier* type_qual;
	Declaration_specifiers* decl_spec;
public:
    virtual ~Declaration_specifiers() {}

    Declaration_specifiers(Storage_class_specifier* stor_class_spec_in, Type_specifier* type_spec_in, Type_qualifier* type_qual_in, Declaration_specifiers* decl_spec_in) : stor_class_spec(stor_class_spec_in), type_spec(type_spec_in), type_qual(type_qual_in), decl_spec(decl_list_in) {}
};

#endif
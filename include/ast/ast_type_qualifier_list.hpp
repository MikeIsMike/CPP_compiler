#ifndef ast_type_qualifier_list_hpp
#define ast_type_qualifier_list_hpp

#include "ast_tree.hpp"
#include <string>




class Type_qualifier_list
    : public Tree
{

private:
    Type_qualifier* type_qual;
    Type_qualifier_list* type_qual_list;
public:
    virtual ~Type_qualifier_list() {}

    Type_qualifier_list(
        Type_qualifier* type_qual_in,
        Type_qualifier_list* type_qual_list_in) :
        type_qual(type_qual_in),
        type_qual_list(type_qual_list_in) {}
};

#endif
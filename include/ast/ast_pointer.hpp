#ifndef ast_pointer_hpp
#define ast_pointer_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Pointer
    : public Tree
{

private:
    Type_qualifier_list* type_qual_list;
    Pointer* ptr;
public:
    virtual ~Pointer() {}

    Pointer(
        Type_qualifier_list* type_qual_list_in,
        Pointer* ptr_in) :
        type_qual_list(type_qual_list_in),
        ptr(ptr_in) {}
};

#endif

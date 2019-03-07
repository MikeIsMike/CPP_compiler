#ifndef ast_enumerator_list_hpp
#define ast_enumerator_list_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Enumerator_list
    : public Tree
{

private:
    Enumerator* enumer;
    Enumerator_list* enum_list;
public:
    virtual ~Enumerator_list() {}

    Enumerator_list(
        Enumerator* enumer_in,
        Enumerator_list* enum_list_in) :
        enumer(enumer_in),
        enum_list(enum_list_in){}
};

#endif

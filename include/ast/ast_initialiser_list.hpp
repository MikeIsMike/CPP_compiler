#ifndef ast_initialiser_list_hpp
#define ast_initialiser_list_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Initializer_list
    : public Tree
{

private:
    Initializer* init;
    Initializer_list* init_list;
public:
    virtual ~Initializer_list() {}

    Initializer_list(
        Initializer* init_in,
        Initializer_list* init_list_in) :
        init(init_in),
        init_list(init_list_in){}
};

#endif

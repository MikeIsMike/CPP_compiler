#ifndef ast_init_declarator_hpp
#define ast_init_declarator_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Init_declarator
    : public Tree
{

private:
    Declarator* declarator;
    Initialiser* initialiser;
public:
    virtual ~Init_declarator() {}

    Init_declarator(Declarator* declarator_in, Initialiser* initialiser_in) : declarator(declarator_in), initialiser(initialiser_in) {}
};

#endif

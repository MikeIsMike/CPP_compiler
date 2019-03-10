#ifndef ast_init_declarator_hpp
#define ast_init_declarator_hpp

#include "ast_tree.hpp"
#include "ast_declarator.hpp"
#include "ast_initializer.hpp"
#include <string>




class Init_declarator
    : public Tree
{

private:
    Declarator* declarator;
    Initializer* initializer;
public:
    virtual .* {}
    virtual void print_python(std::ostream &dst) const;

    Init_declarator(Declarator* declarator_in, Initializer* initializer_in) : declarator(declarator_in), initializer(initializer_in) {}
};

#endif

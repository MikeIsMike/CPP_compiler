#ifndef ast_tree_hpp
#define ast_tree_hpp
#include <iostream>

class Tree;

typedef const Tree *TreePtr;

class Tree
{
public:
    virtual ~Tree() { };
    virtual void print_python(std::ostream &dst) const{ };
    virtual void compile(std::ostream &dst) const{};
};


#endif

#ifndef ast_tree_hpp
#define ast_tree_hpp


class Tree;

typedef const Tree *TreePtr;

class Tree
{
public:
    virtual ~Tree()
    {}

    virtual void print_python(std::ostream &dst) const;
};


#endif

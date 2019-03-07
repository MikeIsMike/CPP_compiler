#ifndef ast_struct_declarator_hpp
#define ast_struct_declarator_hpp

#include "ast_tree.hpp"
#include"../ast.hpp"
#include <string>




class Struct_declarator
    : public Tree
{

private:
    Declarator* decl;
    Constant_expression* const_expr;
public:
    virtual ~Struct_declarator() {}

    Struct_declarator(
        Declarator* decl_in,
        Constant_expression* const_expr_in) :
        decl(decl_in),
        const_expr(const_expr_in) {}
};

#endif

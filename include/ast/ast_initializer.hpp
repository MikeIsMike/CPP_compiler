#ifndef ast_initializer_hpp
#define ast_initializer_hpp

#include "ast_tree.hpp"
#include "ast_assignment_expression.hpp"
#include "ast_initializer_list.hpp"
#include <string>




class Initializer
    : public Tree
{

private:
    Assignment_expression* assignment_expr;
    Initializer_list* init_list;
    bool comma_present;
public:
    virtual ~Initializer() {}

    Initializer(
        Assignment_expression* assignment_expr_in,
        Initializer_list* init_list_in,
        bool comma_present_in) :
        assignment_expr(assignment_expr_in),
        init_list(init_list_in),
        comma_present(comma_present_in){}
};

#endif

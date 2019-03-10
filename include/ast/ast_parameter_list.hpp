#ifndef ast_parameter_list_hpp
#define ast_parameter_list_hpp

#include "ast_tree.hpp"
#include "ast_parameter_declaration.hpp"
#include <string>




class Parameter_list
    : public Tree
{

private:
    Parameter_declaration* param_decl;
    Parameter_list* param_list;

public:
    virtual ~Parameter_list() {}

    Parameter_list(
        Parameter_declaration* param_decl_in,
        Parameter_list* param_list_in) :
        param_decl(param_decl_in),
        param_list(param_list_in) {}
};

#endif

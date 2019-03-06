#ifndef ast_direct_abstract_declarator_hpp
#define ast_direct_abstract_declarator_hpp

#include "ast_tree.hpp"
#include <string>




class Direct_abstract_declarator
    : public Tree
{

private:
    Int parse_rule_followed; //Rule parser follows to create this node
    Abstract_declarator* abstr_decl;
    Constant_expression* const_expr;
    Direct_abstract_declarator* direct_abstr_decl;
    Parameter_type_list* pparam_type_list;
public:
    virtual ~Direct_abstract_declarator() {}

    Direct_abstract_declarator(
        Int parse_rule_followed_in, //Rule parser follows to create this node
        Abstract_declarator* abstr_decl_in,
        Constant_expression* const_expr_in,
        Direct_abstract_declarator* direct_abstr_decl_in,
        Parameter_type_list* pparam_type_list_in) :
        parse_rule_followed(parse_rule_followed_in),
        abstr_decl(abstr_decl_in),
        const_expr(const_expr_in),
        direct_abstr_decl(direct_abstr_decl_in),
        pparam_type_list(pparam_type_list_in){}
};

#endif

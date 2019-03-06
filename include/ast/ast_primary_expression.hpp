#ifndef ast_primary_expression_hpp
#define ast_primary_expression_hpp

#include "ast_tree.hpp"
#include <string>




class Primary_expression
    : public Tree
{

private:
    std::String* identifier;
    std::String* constant;
    std::String* string_literal;
    Expression* expression;
public:
    virtual ~Primary_expression() {}

    Primary_expression(
        std::String* identifier_in,
        std::String* constant_in,
        std::String* string_literal_in,
        Expression* expression_in) :
        identifier(identifier_in),
        constant(constant_in),
        string_literal(string_literal_in),
        expression(expression_in){}
};

#endif

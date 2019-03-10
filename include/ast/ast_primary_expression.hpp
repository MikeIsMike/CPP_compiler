#ifndef ast_primary_expression_hpp
#define ast_primary_expression_hpp

#include "ast_tree.hpp"
#include "ast_expression.hpp"
#include <string>




class Primary_expression
    : public Tree
{

private:
    std::string* identifier;
    std::string* constant;
    std::string* string_literal;
    Expression* expression;
public:
    virtual ~Primary_expression() {}
    virtual void print_python(std::ostream &dst) const;

    Primary_expression(
        std::string* identifier_in,
        std::string* constant_in,
        std::string* string_literal_in,
        Expression* expression_in) :
        identifier(identifier_in),
        constant(constant_in),
        string_literal(string_literal_in),
        expression(expression_in){}
};

#endif

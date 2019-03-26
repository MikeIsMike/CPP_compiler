#ifndef mips_forward_declaration_hpp
#define mips_forward_declaration_hpp

#include <vector>
#include <string>


struct Binding{
    bool is_initialised = false;
    double value = 0;
    std::string name = "";
    std::vector<int> scope;
    int stack_offset;
    int enumerator_value=0;
    bool is_enum=false;

};

struct Context{
    std::vector<Binding> variables;
    std::vector<Binding> enumerators;

    bool in_assignment_expression = false;
    int assignment_expression_lvl = 0;
    int variable_position;
    bool variable_found = false;
    bool enum_found = false;
    int element_position;
    int current_fp;

    bool external_decl = false;
    bool print_function_identifier = false;
    bool variable_returned;
    bool first_var_in_stack = false;

    std::vector<int> current_scope;
    std::vector<int> last_scope;

    Binding tmp;
    bool parameter_declaration = false;
    int decl_to_reg = 4;//function parameter input register index when writing
    int val_to_reg = 4;//function parameter register index when reading

    bool stack_counting=false;
    int declaration_count=0;
    int largest_decl = 8;

    bool function_declaration = false;
    bool in_argument_expression_list = false;

    int current_stack_offset = 24;

    std::vector<std::string> break_scope;
};

#endif

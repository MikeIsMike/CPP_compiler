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

};

struct Context{
    std::vector<Binding> variables;
    int element_position;
    int current_sp;
    int current_fp;

    std::vector<int> current_scope;
    std::vector<int> last_scope;

    Binding tmp;

    bool stack_counting=false;
    int declaration_count=0;
    int largest_decl = 4;

    bool function_declaration = false;

    int current_stack_offset = 8;
};

#endif

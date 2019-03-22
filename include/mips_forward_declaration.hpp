#ifndef mips_forward_declaration_hpp
#define mips_forward_declaration_hpp

#include <vector>
#include <string>

struct bindings{
    bool is_initialised = false;
    double value = 0;
    std::string name = "";
    std::string scope = "";
    int stack_offset;

};

struct context{
    std::vector<bindings> variables;
    int element_position;
    int current_sp;
};

#endif

#ifndef mips_forward_declaration_hpp
#define mips_forward_declaration_hpp

#include <vector>
#include <string>


struct Binding{
    bool is_initialised = false;
    double value = 0;
    std::string name = "";
    std::string scope = "";
    int stack_offset;

};

struct Context{
    std::vector<Binding> variables;
    int element_position;
    int current_sp;
    int current_fp;

    Binding tmp;

    bool stack_counting=false;
    int declaration_count=0;
};

#endif

#ifndef mips_forward_declaration_hpp
#define mips_forward_declaration_hpp

#include <vector>
#include <string>


struct Bindings{
    bool is_initialised = false;
    double value = 0;
    std::string name = "";
    std::string scope = "";
    int stack_offset;

};

struct Context{
    std::vector<Bindings> variables;
    int element_position;
    int current_sp;
    int current_fp;


    bool stack_counting = false;
    int delaration_count = 0;
};

#endif

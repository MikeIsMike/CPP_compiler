#include "ast.hpp"
#include <iostream>

// "///" for action needed
// "//" for comment to help understanding

void Translation_unit::compile(std::ostream &dst) const{
    if(translation_unit!=NULL){
        translation_unit->compile(dst);
        external_decl->compile(dst);
    }
    else if(translation_unit==NULL){
        external_decl->compiler(dst);
    }
}


void External_declaration::compile(std::ostream &dst) const{
    if(funct_def!=NULL){
        funct_def->compile(dst);
    }
    else if(decl!=NULL){
        decl->compile(dst);
    }
}


void function_definition::compile(std::ostream &dst) const{
    switch(parse_rule_followed){///case 1 and 3 support K&R style, not to be implemented
        case 2: ///function int abc(){sflkdsjf}
            // function = true;

            decl_spec->compile(dst);
            decl->compile(dst);
            compound_stmnt->compile(dst);
            break;
        case 4: ///function abc(){saldkfjsdflk} ///this defaults to return type int!!!!!!!!!
            // function = true;
            decl->print_python(dst);
            compound_stmnt->print_python(dst);
            break;

    }
}

void Declaration_specifiers::print_python(std::ostream &dst) const{
    if(type_spec!=NULL){///only rule 3 and 4 implemented
        if((*type_spec)=="int"){
            ///
        }

        if(decl_spec!=NULL){
            std::cout<<"3b"<<std::endl;
            //nothing to do here
            // decl_spec->print_python(dst);
        }
    }

}

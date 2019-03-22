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


void Function_definition::compile(std::ostream &dst) const{
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

<<<<<<< HEAD
void Compound_statement::(std::ostream &dst, Context &context) const{
    if(context->stack_counting){
        decl_list->compile(dst, context);
    }
}

void Declaration_list::(std::ostream &dst, Context &context) const{
    if(context->stack_counting){
        context->delaration_count++;
        decl_list->compile(dst, context);
    }
}

void Declaration_specifiers::print_python(std::ostream &dst) const{
=======

void Declaration_specifiers::compile(std::ostream &dst) const{
>>>>>>> b36b901c3192a0708a78388239a870cda949aa34
    if(type_spec!=NULL){///only rule 3 and 4 implemented
        if((*type_spec)=="int"){
            ///do something in MIPS that corresponds to int return type
        }


    }
    else if(type_qual!=NULL){}///to support const and volatile, probably won't implement
    else if(stor_class_spec!=NULL){}///to suppport static and stuff, probably won't implement

    if(decl_spec!=NULL){

        decl_spec->compile(dst);
    }

}


void Declarator::compile(std::ostream &dst) const{
    if(pointer==NULL){//second rule
        dir_decl->compile(dst);
    }
    ///pointer to be implemented
}


void Direct_declarator::compile(std::ostream &dst) const{ //global and other variebles handeled needed aghhh
    switch(parse_rule_followed){///only 1 and 7 implemented, need to expand
        case 1://function name printed as MIPS label

            dst<<*identifier<<":\n";
            break;
        // case 2:
        //     // std::cout<<"Direct_declarator switch_1"<<std::endl;
        //     dst<<"(";
        //     decl->print_python(dst);
        //     dst<<"):"<<"\n";
        //     function = false;
        //
        //     break;
        // case 5:
        //     // std::cout<<"Direct_declarator switch_5"<<std::endl;
        //     direct_decl->print_python(dst);
        //     dst<<"(";
        //     param_type_list->print_python(dst);
        //     dst<<"):"<<"\n";
        //     function = false;
        //
        //     break;
        // case 6:
        //     // std::cout<<"Direct_declarator switch_6"<<std::endl;
        //     direct_decl->print_python(dst);
        //     dst<<"(";
        //     identif_list->print_python(dst);
        //     dst<<"):"<<"\n";
        //     function = false;
        //
        //     break;
        case 7://funct_abc()
            // std::cout<<"Direct_declarator switch_7"<<std::endl;
            direct_decl->compile(dst);
            ///this is a function now
            // function = false;

            break;
    }
}

void Assignment_expression::compile(std::ostream &dst) const{
    if(cond_expr!=NULL){
        cond_expr->compile(dst);
    }
    else if()

}

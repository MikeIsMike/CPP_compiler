#include "ast.hpp"
#include <iostream>

// "///" for action needed
// "//" for comment to help understanding

void Translation_unit::compile(std::ostream &dst, Context& context) const{
    if(translation_unit!=NULL){
        translation_unit->compile(dst, context);
        external_decl->compile(dst, context);
    }
    else if(translation_unit==NULL){
        external_decl->compile(dst, context);
    }
}


void External_declaration::compile(std::ostream &dst, Context& context) const{
    if(funct_def!=NULL){
        funct_def->compile(dst, context);
    }
    else if(decl!=NULL){
        decl->compile(dst, context);
    }
}


void Function_definition::compile(std::ostream &dst, Context& context) const{
    switch(parse_rule_followed){///case 1 and 3 support K&R style, not to be implemented
        case 2: ///function int abc(){sflkdsjf}
            // function = true;
            //Count minimum number of variables
            context->declaration_count = 0;
            context->stack_counting = true;
            compound_stmnt->compile(dst, context);
            context->stack_counting = false;

            decl_spec->compile(dst, context);
            decl->compile(dst, context);

            context->current_sp = context->current_sp - (context->declaration_count+32);
            dst<<"\taddiu\t$sp,$sp,-"<<(context->declaration_count+32)<<"\n";

            dst<<"\tsw\t$fp,"<<(context->declaration_count+28)<<"($sp)\n";

            context->current_fp = context->current_sp;
            dst<<"\tmove\t$fp,$sp\n"




            compound_stmnt->compile(dst, context);



            dst<<"\tmove\t$sp,$fp\n"
            dst<<"\tlw\t$fp,"<<(context->declaration_count+28)<<"($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<(context->declaration_count+32)<<"\n";
            dst<<"\tj\t$31"<<"\n";
            dst<<"\tnoop"


            break;



        case 4: ///function abc(){saldkfjsdflk} ///this defaults to return type int!!!!!!!!!
            // function = true;
            decl->compile(dst, context);
            compound_stmnt->compile(dst, context);
            break;

    }
}

void Compound_statement::compile(std::ostream &dst, Context &context) const{
    if(context->stack_counting){
        decl_list->compile(dst, context);
    }
}

void Declaration_list::compile(std::ostream &dst, Context &context) const{
    if(context->stack_counting){
        context->delaration_count++;
        decl_list->compile(dst, context);
    }
}

void Declaration_specifiers::compile(std::ostream &dst) const{
    if(type_spec!=NULL){///only rule 3 and 4 implemented
        if((*type_spec)=="int"){
            ///do something in MIPS that corresponds to int return type
        }


    }
    else if(type_qual!=NULL){}///to support const and volatile, probably won't implement
    else if(stor_class_spec!=NULL){}///to suppport static and stuff, probably won't implement

    if(decl_spec!=NULL){

        decl_spec->compile(dst, context);
    }

}


void Declarator::compile(std::ostream &dst, Context& context) const{
    if(pointer==NULL){//second rule
        dir_decl->compile(dst, context);
    }
    ///pointer to be implemented
}


void Direct_declarator::compile(std::ostream &dst, Context& context) const{ //global and other variebles handeled needed aghhh
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
            direct_decl->compile(dst, context);
            ///this is a function now
            // function = false;

            break;
    }
}

void Assignment_expression::compile(std::ostream &dst, Context& context) const{
    if(cond_expr!=NULL){
        cond_expr->compile(dst, context);
    }
    else if()

}

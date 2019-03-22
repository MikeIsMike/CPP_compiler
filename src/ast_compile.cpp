#include "ast.hpp"
#include <iostream>
#include "mips_forward_declaration.hpp"
#include <string>

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
            context.declaration_count = 0;
            context.stack_counting = true;
            if(compound_stmnt!=NULL){
                compound_stmnt->compile(dst, context);
                context.stack_counting = false;
            }

            decl_spec->compile(dst, context);
            decl->compile(dst, context);

            context.current_sp = context.current_sp - (context.declaration_count+32);
            dst<<"\taddiu\t$sp,$sp,-"<<(context.declaration_count+32)<<"\n";

            dst<<"\tsw\t$fp,"<<(context.declaration_count+28)<<"($sp)\n";

            context.current_fp = context.current_sp;
            dst<<"\tmove\t$fp,$sp\n";




            compound_stmnt->compile(dst, context);



            dst<<"\tmove\t$sp,$fp\n";
            dst<<"\tlw\t$fp,"<<(context.declaration_count+28)<<"($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<(context.declaration_count+32)<<"\n";
            dst<<"\tj\t$31"<<"\n";
            dst<<"\tnop\n";


            break;



        case 4: ///function abc(){saldkfjsdflk} ///this defaults to return type int!!!!!!!!!
            // function = true;
            decl->compile(dst, context);
            compound_stmnt->compile(dst, context);
            break;

    }
}

void Compound_statement::compile(std::ostream &dst, Context &context) const{
    if(decl_list!=NULL){
        if(context.stack_counting){
            decl_list->compile(dst, context);
        }
    }
}

void Declaration_list::compile(std::ostream &dst, Context &context) const{
    if(context.stack_counting){
        if(decl_list!=NULL){
            context.delaration_count++;
            decl_list->compile(dst, context);
        }
    }
    else{
        if(decl_list!=NULL){
            decl_list->compile(dst, context);
            decl->compile(dst, context);
        }
        else{
            decl->compile(dst, context);
        }
    }
}


void Declaration::compile(std::ostream &dst, Context& context) const{
    if(init_decl_list!=NULL){///only the initilised case
        // decl_spec->compile(dst);///ignore this for now because only int

        init_decl_list->compile(dst, context);
    }
    else if(init_decl_list==NULL){

        for( int i = 0; i<indent_count; i++) { dst << "\t"; }

        // decl_spec->print_python(dst);
        //nothing to do here

    }
}


void Init_declarator_list::compile(std::ostream &dst, Context& context) const{
    if(init_decl_list==NULL && init_decl!=NULL){
        init_decl->compile(dst, context);
    }
    else if(init_decl_list!=NULL){
        init_decl_list->compile(dst, context);
        init_decl->compile(dst, context);
    }
}


void Init_declarator::compile(std::ostream &dst, Context& context) const{
    if(declarator!=NULL&&initializer!=NULL){
        declarator->compile(dst, context);
        initializer->compile(dst, context);
    }
}


void Declarator::compile(std::ostream &dst, Context& context) const{
    if(direct_decl!=NULL){///pointer not implemented yet
        direct_decl->compile(dst, context);
    }
}


void Direct_declarator::compile(std::ostream &dst, Context& context) const{
    if(*identifier!=NULL){//left hand side
        context.tmp.name=*identifier;

    }
}


void Initializer::compile(std::ostream &dst, Context& context) const{
    if(assignment_expr!=NULL){
        assignment_expr->compile(dst, context);
    }
}


void Declaration_specifiers::compile(std::ostream &dst, Context& context) const{
    if(type_spec!=NULL){///only rule 3 and 4 implemented
        // if((*type_spec)=="int"){
        //     ///do something in MIPS that corresponds to int return type
        // }


    }
    else if(type_qual!=NULL){}///to support const and volatile, probably won't implement
    else if(stor_class_spec!=NULL){}///to suppport static and stuff, probably won't implement

    if(decl_spec!=NULL){

        decl_spec->compile(dst, context);
    }

}

void Statement::compile(std::ostream &dst, Context& context) const{
    if(context.stack_counting){
        if( labeled_stmnt != NULL ) {
            labeled_stmnt->compile(dst, context);
            // std::cout<<"Statement if_1"<<std::endl;
        }

        else if( compound_stmnt != NULL ) {
            // std::cout<<"Statement if_2"<<std::endl;
            compound_stmnt->compile(dst, context);
        }

        else if( expression_stmnt != NULL ) {
            // std::cout<<"Statement if_3"<<std::endl;
            expression_stmnt->compile(dst, context);
        }

        else if( selection_stmnt != NULL ) {
            // std::cout<<"Statement if_4"<<std::endl;
            selection_stmnt->compile(dst, context);
        }

        else if( iteration_stmnt != NULL ) {
            // std::cout<<"Statement if_5"<<std::endl;
            iteration_stmnt->compile(dst, context);
        }

        else if( jump_stmnt != NULL ) {
            // std::cout<<"Statement if_6"<<std::endl;
            jump_stmnt->compile(dst, context);
        }
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
    else{
        if(assignment_expr!=NULL){
            assignment_expr->compile(dst, context);
        }

        if(unary_expr!=NULL){
            unary_expr->compile(dst,context);
        }



    }

}


void Conditional_expression::compile(std::ostream &dst, Context& context) const{
    if(logic_or_expr!=NULL){
        logic_or_expr->compile(dst,context);
    }
    else{
        ////////////
    }
}


void Logical_or_expression::compile(std::ostream &dst, Context& context) const{
    if(logical_and_expr!=NULL){
        logical_and_expr->compile(dst,context);
    }
}

void Logical_and_expression::compile(std::ostream &dst, Context& context) const{
    if(inclusive_or_expr!=NULL){
        inclusive_or_expr->compile(dst,context);
    }
}

void Inclusive_or_expression::compile(std::ostream &dst, Context& context) const{
    if(exclusive_or_expr!=NULL){
        exclusive_or_expr->compile(dst,context);
    }
}

void Exclusive_or_expression::compile(std::ostream &dst, Context& context) const{
    if(and_expr!=NULL){
        and_expr->compile(dst,context);
    }
}

void And_expression::compile(std::ostream &dst, Context& context) const{
    if(equality_expr!=NULL){
        equality_expr->compile(dst,context);
    }
}

void Equality_expression::compile(std::ostream &dst, Context& context) const{
    if(relat_expr!=NULL){
        relat_expr->compile(dst,context);
    }
}
void Relational_expression::compile(std::ostream &dst, Context& context) const{
    if(shift_expr!=NULL){
        shift_expr->compile(dst,context);
    }
}

void Shift_expression::compile(std::ostream &dst, Context& context) const{
    if(additive_expr!=NULL){
        additive_expr->compile(dst,context);
    }
}

void Additive_expression::compile(std::ostream &dst, Context& context) const{
    if(mult_expr!=NULL){
        mult_expr->compile(dst,context);
    }
}

void Multiplicative_expression::compile(std::ostream &dst, Context& context) const{
    if(cast_expr!=NULL){
        cast_expr->compile(dst,context);
    }
}

void Cast_expression::compile(std::ostream &dst, Context& context) const{
    if(unary_expr!=NULL){
        unary_expr->compile(dst,context);
    }
}

void Unary_expression::compile(std::ostream &dst, Context& context) const{
    if(postf_expr!=NULL){
        postf_expr->compile(dst,context);
    }
}

void Postfix_expression::compile(std::ostream &dst, Context& context) const{
    if(prim_expr!=NULL){
        prim_expr->compile(dst,context);
    }
}

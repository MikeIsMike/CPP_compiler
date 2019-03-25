#include "ast.hpp"
#include <iostream>
#include "mips_forward_declaration.hpp"
#include <string>

// "///" for action needed
// "//" for comment to help understanding
static int makeNameUnq=0;

static std::string makeName(std::string base)
{
    return "_"+base+"_"+std::to_string(makeNameUnq++);
}


void Translation_unit::compile(std::ostream &dst, Context& context) const{
    dst<<"#translation_unit\n";

    if(translation_unit!=NULL){
        translation_unit->compile(dst, context);
        external_decl->compile(dst, context);
    }
    else if(translation_unit==NULL){
        external_decl->compile(dst, context);
    }
}


void External_declaration::compile(std::ostream &dst, Context& context) const{
    dst<<"#External_declaration\n";
    if(funct_def!=NULL){
        funct_def->compile(dst, context);
    }
    else if(decl!=NULL){
        context.external_decl = true;
        decl->compile(dst, context);
        context.external_decl = true;

    }
}


void Function_definition::compile(std::ostream &dst, Context& context) const{
    dst<<"#Function_definition\n";

    switch(parse_rule_followed){///case 1 and 3 support K&R style, not to be implemented
        case 2: ///function int abc(){sflkdsjf}
            // function = true;

            //Count minimum number of variables for memory allocation
            context.declaration_count = 0;
            context.stack_counting = true;
            if(compound_stmnt!=NULL){
                compound_stmnt->compile(dst, context);
            }
            context.stack_counting = false;
            context.first_var_in_stack = true;

            context.function_declaration = true;
            decl_spec->compile(dst, context);
            decl->compile(dst, context);
            context.function_declaration = false;

            //Setup stack
            context.element_position = context.element_position - (context.declaration_count*context.largest_decl+32);
            dst<<"\taddiu\t$sp,$sp,-"<<(context.declaration_count*context.largest_decl+32)<<"\n";
            dst<<"\tsw\t$31,"<<(context.declaration_count*context.largest_decl+28)<<"($sp)\n";
            dst<<"\tsw\t$fp,"<<(context.declaration_count*context.largest_decl+24)<<"($sp)\n";

            context.current_fp = context.element_position;
            dst<<"\tmove\t$fp,$sp\n";
            context.current_stack_offset = 24;



            //Change Context
            if(context.current_scope.size()<context.last_scope.size()){
                std::vector<int> tmp = context.current_scope;
                context.current_scope.push_back(context.last_scope.back() + 1);
                context.last_scope = tmp;
            }
            else{
                std::vector<int> tmp = context.current_scope;
                context.current_scope.push_back(1);
                context.last_scope = tmp;
            }

            compound_stmnt->compile(dst, context);

            //Change Context
            context.last_scope = context.current_scope;
            context.current_scope.pop_back();


            //Deallocate stack
            dst<<"\tmove\t$sp,$fp\n";
            dst<<"\tlw\t$31,"<<(context.declaration_count*context.largest_decl+28)<<"($sp)\n";
            dst<<"\tlw\t$fp,"<<(context.declaration_count*context.largest_decl+24)<<"($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<(context.declaration_count*context.largest_decl+32)<<"\n";
            dst<<"\tjr\t$31"<<"\n";
            dst<<"\tnop\n";


            break;



        case 4: ///function abc(){saldkfjsdflk} ///this defaults to return type int!!!!!!!!!
        // function = true;

        //Count minimum number of variables for memory allocation
        context.declaration_count = 0;
        context.stack_counting = true;
        if(decl_list!=NULL){
            decl_list->compile(dst, context);
        }

        int no_of_inputs = context.declaration_count;

        if(compound_stmnt!=NULL){
            compound_stmnt->compile(dst, context);
        }
        context.stack_counting = false;
        context.first_var_in_stack = true;

        context.function_declaration = true;
        decl_spec->compile(dst, context);
        decl->compile(dst, context);

        //Setup stack
        context.element_position = context.element_position - (context.declaration_count*context.largest_decl+32);
        dst<<"\taddiu\t$sp,$sp,-"<<(context.declaration_count*context.largest_decl+32)<<"\n";
        dst<<"\tsw\t$31,"<<(context.declaration_count*context.largest_decl+28)<<"($sp)\n";
        dst<<"\tsw\t$fp,"<<(context.declaration_count*context.largest_decl+24)<<"($sp)\n";

        context.current_fp = context.element_position;
        dst<<"\tmove\t$fp,$sp\n";
        context.current_stack_offset = 24;



        //Change Context
        if(context.current_scope.size()<context.last_scope.size()){
            std::vector<int> tmp = context.current_scope;
            context.current_scope.push_back(context.last_scope.back() + 1);
            context.last_scope = tmp;
        }
        else{
            std::vector<int> tmp = context.current_scope;
            context.current_scope.push_back(1);
            context.last_scope = tmp;
        }

        ///////////Handle Inputs

        decl_list->compile(dst, context);
        context.function_declaration = false;
        //////////Handle function
        compound_stmnt->compile(dst, context);

        //Change Context
        context.last_scope = context.current_scope;
        context.current_scope.pop_back();


        //Deallocate stack
        dst<<"\tmove\t$sp,$fp\n";
        dst<<"\tlw\t$31,"<<(context.declaration_count*context.largest_decl+28)<<"($sp)\n";
        dst<<"\tlw\t$fp,"<<(context.declaration_count*context.largest_decl+24)<<"($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<(context.declaration_count*context.largest_decl+32)<<"\n";
        dst<<"\tjr\t$31"<<"\n";
        dst<<"\tnop\n";


        break;

    }
    // dst<<".end "<<*identifier<<"\n";

}

void Expression_statement::compile(std::ostream &dst, Context &context) const{
    if(context.stack_counting){;}
    else{
        if(expr!=NULL){
            expr->compile(dst, context);
        }
    }
}

void Compound_statement::compile(std::ostream &dst, Context &context) const{
    //Change Context
    if(context.current_scope.size()<context.last_scope.size()){
        std::vector<int> tmp = context.current_scope;
        context.current_scope.push_back(context.last_scope.back() + 1);
        context.last_scope = tmp;
    }
    else{
        std::vector<int> tmp = context.current_scope;
        context.current_scope.push_back(1);
        context.last_scope = tmp;
    }

    //////////////////////////////////////////
    if(decl_list!=NULL){
        decl_list->compile(dst, context);
    }
    if(stmnt_list!=NULL){
        stmnt_list->compile(dst, context);
    }
    /////////////////////////////////////////////

    //Change Context
    context.last_scope = context.current_scope;
    context.current_scope.pop_back();
}

void Declaration_list::compile(std::ostream &dst, Context &context) const{
    if(context.stack_counting){
        context.declaration_count++;
        if(decl_list!=NULL){
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
    dst<<"#Declaration\n";

    if(init_decl_list!=NULL){///only the initilised case
        // decl_spec->compile(dst);///ignore this for now because only int

        init_decl_list->compile(dst, context);
    }
    else if(init_decl_list==NULL){


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

    if(declarator!=NULL && initializer==NULL){
        if(context.external_decl){
            declarator->compile(dst, context);
            dst<<"data\n";
            dst<<context.tmp.name<<": .word 0\n";
        }
        else{
            //WRONG
            declarator->compile(dst, context);
            context.variables.push_back(context.tmp);
        }
    }
    if(declarator!=NULL&&initializer!=NULL){
        if(context.external_decl){
            //WRONG
            declarator->compile(dst, context);
            dst<<"data\n";
            dst<<context.tmp.name<<": .word 0\n";
        }
        else{
            declarator->compile(dst, context);
            context.variables.push_back(context.tmp);
            initializer->compile(dst, context);

            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";

            dst<<"\tsw\t$2,"<<context.current_stack_offset-8<<"($fp)"<<std::endl;
        }
    }
}


void Declarator::compile(std::ostream &dst, Context& context) const{
    if(pointer==NULL&&dir_decl!=NULL){///pointer not implemented yet
        dir_decl->compile(dst, context);
    }
}




void Initializer::compile(std::ostream &dst, Context& context) const{
    //returns to $2
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


    else{
        dst<<"#statement\n";
        if( labeled_stmnt != NULL ) {
            dst<<"#labeled_stmnt\n";
            labeled_stmnt->compile(dst, context);
            // std::cout<<"Statement if_1"<<std::endl;
        }

        else if( compound_stmnt != NULL ) {
            dst<<"#compound_stmnt\n";
            // std::cout<<"Statement if_2"<<std::endl;
            compound_stmnt->compile(dst, context);
        }

        else if( expression_stmnt != NULL ) {
            dst<<"#expression_stmnt\n";
            // std::cout<<"Statement if_3"<<std::endl;
            expression_stmnt->compile(dst, context);
        }

        else if( selection_stmnt != NULL ) {
            dst<<"#selection_stmnt\n";
            // std::cout<<"Statement if_4"<<std::endl;
            selection_stmnt->compile(dst, context);
        }

        else if( iteration_stmnt != NULL ) {
            dst<<"#iteration_stmnt\n";
            // std::cout<<"Statement if_5"<<std::endl;
            iteration_stmnt->compile(dst, context);
        }

        else if( jump_stmnt != NULL ) {
            dst<<"#jump_stmnt\n";
            // std::cout<<"Statement if_6"<<std::endl;
            jump_stmnt->compile(dst, context);
        }
    }
}

void Statement_list::compile(std::ostream &dst, Context& context) const{

    if(context.stack_counting){
        if(stmnt_list!=NULL && stmnt!=NULL){
            stmnt_list->compile(dst, context);
            stmnt->compile(dst, context);
        }
        else if(stmnt_list==NULL && stmnt!=NULL){
            stmnt->compile(dst, context);
        }
    }
    else{
        dst<<"#statement_list\n";
        if(stmnt_list!=NULL && stmnt!=NULL){
            stmnt_list->compile(dst, context);
            stmnt->compile(dst, context);
        }
        else if(stmnt_list==NULL && stmnt!=NULL){
            stmnt->compile(dst, context);
        }
    }
}

void Jump_statement::compile(std::ostream &dst, Context& context) const{
    if(context.stack_counting){;}
    else{
        if(*keyword=="return"){

            if(context.stack_counting){
                if(expr!=NULL){
                    expr->compile(dst, context);
                }
            }

            else if(expr!=NULL){


                expr->compile(dst, context);
                dst<<"#jump_statement with return value\n";

                dst<<"\tlw\t$2,($sp)\n";
                dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";

                //Change Context
                context.last_scope = context.current_scope;
                context.current_scope.pop_back();


                //Deallocate stack
                dst<<"\tmove\t$sp,$fp\n";
                dst<<"\tlw\t$fp,"<<(context.declaration_count*context.largest_decl+24)<<"($sp)\n";
                dst<<"\tlw\t$31,"<<(context.declaration_count*context.largest_decl+28)<<"($sp)\n";
                dst<<"\taddiu\t$sp,$sp,"<<(context.declaration_count*context.largest_decl+32)<<"\n";
                dst<<"\tjr\t$31"<<"\n";
                dst<<"\tnop\n";

            }
            else{

                dst<<"#jump_statement without return value\n";

                //Change Context
                context.last_scope = context.current_scope;
                context.current_scope.pop_back();


                //Deallocate stack
                dst<<"\tmove\t$sp,$fp\n";
                dst<<"\tlw\t$fp,"<<(context.declaration_count*context.largest_decl+24)<<"($sp)\n";
                dst<<"\tlw\t$31,"<<(context.declaration_count*context.largest_decl+28)<<"($sp)\n";
                dst<<"\taddiu\t$sp,$sp,"<<(context.declaration_count*context.largest_decl+32)<<"\n";
                dst<<"\tjr\t$31"<<"\n";
                dst<<"\tnop\n";

            }

        }

    }

}

void Selection_statement::compile(std::ostream &dst, Context& context) const{
    if(context.stack_counting){
        if(if_statement!=NULL){
            if_statement->compile(dst, context);
        }
        if(else_statement!=NULL){
            if_statement->compile(dst, context);
        }
    }
    else{
        if(!switch_stmnt){
            if(else_statement==NULL && expr!=NULL && if_statement!=NULL){
                std::string branch=makeName("if");

                expr->compile(dst, context);
                dst<<"\tlw\t$8,($sp)\n";
                dst<<"\taddiu\t$sp,$sp,"<<"8"<<"\n";


                dst<<"\tbeq\t$8,$0,"<<"$FALSE"<<branch<<"\n";
                dst<<"\tnop\n";

                //Change Context
                if(context.current_scope.size()<context.last_scope.size()){
                    std::vector<int> tmp = context.current_scope;
                    context.current_scope.push_back(context.last_scope.back() + 1);
                    context.last_scope = tmp;
                }
                else{
                    std::vector<int> tmp = context.current_scope;
                    context.current_scope.push_back(1);
                    context.last_scope = tmp;
                }

                if_statement->compile(dst, context);


                //Change Context
                context.last_scope = context.current_scope;
                context.current_scope.pop_back();

                dst<<"$FALSE"<<branch<<":\n";
            }
            else if(else_statement!=NULL && expr!=NULL && if_statement!=NULL){
                std::string branch=makeName("if");

                expr->compile(dst, context);
                dst<<"\tlw\t$8,($sp)\n";
                dst<<"\taddiu\t$sp,$sp,"<<"8"<<"\n";

                dst<<"\tbne\t$8,$0,"<<"$TRUE"<<branch<<"\n";
                dst<<"nop\n";

                //Change Context
                if(context.current_scope.size()<context.last_scope.size()){
                    std::vector<int> tmp = context.current_scope;
                    context.current_scope.push_back(context.last_scope.back() + 1);
                    context.last_scope = tmp;
                }
                else{
                    std::vector<int> tmp = context.current_scope;
                    context.current_scope.push_back(1);
                    context.last_scope = tmp;
                }

                else_statement->compile(dst, context);

                //Change Context
                context.last_scope = context.current_scope;
                context.current_scope.pop_back();


                dst<<"\tj "<<"$END"<<branch<<"\n";
                dst<<"nop\n";
                dst<<"$TRUE"<<branch<<":\n";

                //Change Context
                if(context.current_scope.size()<context.last_scope.size()){
                    std::vector<int> tmp = context.current_scope;
                    context.current_scope.push_back(context.last_scope.back() + 1);
                    context.last_scope = tmp;
                }
                else{
                    std::vector<int> tmp = context.current_scope;
                    context.current_scope.push_back(1);
                    context.last_scope = tmp;
                }

                if_statement->compile(dst, context);

                //Change Context
                context.last_scope = context.current_scope;
                context.current_scope.pop_back();

                dst<<"$END"<<branch<<":\n";
            }
        }
    }
}


void Iteration_statement::compile(std::ostream &dst, Context& context) const{
    if(context.stack_counting){
        if(statement!=NULL){
            statement->compile(dst, context);
        }
    }

    else{
        if(*keyword=="while"){
            std::string branch=makeName("while");
            dst<<"$START"<<branch<<":\n";

            expr->compile(dst, context);

            dst<<"\tlw\t$8,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<"8"<<"\n";


            dst<<"\tbeq\t$8,$0,"<<"$END"<<branch<<"\n";
            dst<<"nop\n";

            //Change Context
            if(context.current_scope.size()<context.last_scope.size()){
                std::vector<int> tmp = context.current_scope;
                context.current_scope.push_back(context.last_scope.back() + 1);
                context.last_scope = tmp;
            }
            else{
                std::vector<int> tmp = context.current_scope;
                context.current_scope.push_back(1);
                context.last_scope = tmp;
            }

            statement->compile(dst, context);

            //Change Context
            context.last_scope = context.current_scope;
            context.current_scope.pop_back();

            dst<<"\tj "<<"$START"<<branch<<"\n";
            dst<<"nop\n";
            dst<<"$END"<<branch<<":\n";

        }
        else if(*keyword=="do"){
            std::string branch=makeName("do");
            dst<<"$START"<<branch<<":\n";

            //Change Context
            if(context.current_scope.size()<context.last_scope.size()){
                std::vector<int> tmp = context.current_scope;
                context.current_scope.push_back(context.last_scope.back() + 1);
                context.last_scope = tmp;
            }
            else{
                std::vector<int> tmp = context.current_scope;
                context.current_scope.push_back(1);
                context.last_scope = tmp;
            }

            statement->compile(dst, context);

            //Change Context
            context.last_scope = context.current_scope;
            context.current_scope.pop_back();

            expr->compile(dst, context);

            dst<<"\tlw\t$8,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<"8"<<"\n";

            dst<<"\tbeq\t$8,$0,"<<"$END"<<branch<<"\n";
            dst<<"nop\n";

            dst<<"\tj "<<"$START"<<branch<<"\n";
            dst<<"nop\n";

            dst<<"$END"<<branch<<":\n";

        }

    }
}


void Direct_declarator::compile(std::ostream &dst, Context& context) const{ //global and other variebles handeled needed aghhh
    switch(parse_rule_followed){///only 1 and 7 implemented, need to expand
        case 1://function name printed as MIPS label
            if(!context.function_declaration){
                if(identifier!=NULL){//left hand side
                    context.tmp.name=*identifier;
                    context.tmp.scope = context.current_scope;
                    context.tmp.stack_offset = context.current_stack_offset;
                    context.current_stack_offset = context.current_stack_offset + 8; //Change to address different variable types and padding, this only works for int

                }

            }
            else{
                dst<<".text"<<"\n";
                dst<<".align 2"<<"\n";
                dst<<".globl "<<*identifier<<"\n";
                // dst<<".ent "<<*identifier<<"\n";
                dst<<".type "<<*identifier<<", @function"<<"\n";

                dst<<*identifier<<":\n";

            }


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
    context.assignment_expression_lvl++;
    if(cond_expr!=NULL){
        cond_expr->compile(dst, context);
    }
    else{
        if(assign_expr!=NULL){
            assign_expr->compile(dst, context);
        }

        if(unary_expr!=NULL){
            context.in_assignment_expression = true;
            unary_expr->compile(dst,context);
            context.in_assignment_expression = false;
        }

        dst<<"\tlw\t$2,($sp)\n";//rhs value loaded into register 2
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";


        if(context.variable_found&&assign_op!=NULL){//lefthandside variable, rhs is already evaluated
            dst<<"\tlw\t$t0,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";//lhs value loaded into t0

            if(*assign_op=="="){
                //do nothing
            }
            else if(*assign_op=="*="){

                dst<<"\tmult\t$t0,$2\n";
                dst<<"\tmflo\t$2\n";
            }
            else if(*assign_op=="/="){
                dst<<"\tdiv\t$t0,$2\n";
                dst<<"\tmflo\t$2\n";
            }
            else if(*assign_op=="%="){
                dst<<"\tdiv\t$t0,$2\n";
                dst<<"\tmfhi\t$2\n";
            }
            else if(*assign_op=="+="){
                dst<<"\taddu\t$2,$t0,$2\n";
            }
            else if(*assign_op=="-="){
                dst<<"\tsubu\t$2,$t0,$2\n";
            }
            else if(*assign_op=="<<="){
                dst<<"\tsll\t$2,$t0,$2\n";
            }
            else if(*assign_op==">>="){
                dst<<"\tsrl\t$2,$t0,$2\n";
            }
            else if(*assign_op=="&="){
                dst<<"\tand\t$2,$t0,$2\n";
            }
            else if(*assign_op=="^="){
                dst<<"\txor\t$2,$t0,$2\n";
            }
            else if(*assign_op=="|="){
                dst<<"\tor\t$2,$t0,$2\n";
            }

            dst<<"\tsw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
            if(context.assignment_expression_lvl!=1){
                dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n";
                dst<<"\tsw\t$2,($sp)\n";
            }

        }
    }
    context.assignment_expression_lvl--;
}

void Conditional_expression::compile(std::ostream &dst, Context& context) const{
    if(logic_or_expr!=NULL&&expr==NULL&&cond_expr==NULL){
        logic_or_expr->compile(dst,context);
    }
    else{

        std::string branch=makeName("conditional");

        logic_or_expr->compile(dst,context);
        dst<<"\tlw\t$8,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<"8"<<"\n";

        dst<<"\tbne\t$8,$0,"<<"$TRUE"<<branch<<"\n";
        dst<<"nop\n";

        cond_expr->compile(dst,context);

        dst<<"\tj "<<"$END"<<branch<<"\n";
        dst<<"nop\n";
        dst<<"$TRUE"<<branch<<":\n";
        expr->compile(dst,context);
        dst<<"$END"<<branch<<":\n";
    }
}


void Logical_or_expression::compile(std::ostream &dst, Context& context) const{
    if(logical_or_expr==NULL&&logical_and_expr!=NULL){
        logical_and_expr->compile(dst,context);
    }
    else if(logical_or_expr!=NULL&&logical_and_expr!=NULL){
        logical_or_expr->compile(dst,context);
        logical_and_expr->compile(dst,context);
        dst<<"#Logical_or_expression_if_2_1\n";
        std::string branch1 = makeName("L_O_E");
        std::string branch2 = makeName("L_O_E");
        std::string branch3 = makeName("L_O_E");

        dst<<"#Logical_and_expression_if_2_1\n";

        dst<<"\tlw\t$t0,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tlw\t$2,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tbeq\t$2,$0,$"<<branch1<<"\n";
        dst<<"\tnop\n";
        dst<<"\tbeq\t$t0,$0,$"<<branch2<<"\n";
        dst<<"\tnop\n";

        dst<<"$"<<branch1<<":\n";
        dst<<"\tli\t$2,1\n";
        dst<<"\tb\t$"<<branch3<<"\n";

        dst<<"$"<<branch2<<":\n";
        dst<<"\tmove\t$2,$0\n";

        dst<<"$"<<branch3<<":\n";
        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";
    }
}

void Logical_and_expression::compile(std::ostream &dst, Context& context) const{
    if(logical_and_expr==NULL&&inclusive_or_expr!=NULL){
        inclusive_or_expr->compile(dst,context);
    }
    else if(logical_and_expr!=NULL&&inclusive_or_expr!=NULL){
        logical_and_expr->compile(dst,context);
        inclusive_or_expr->compile(dst,context);
        dst<<"#Logical_and_expression_if_2_1\n";
        std::string branch1 = makeName("L_A_E");
        std::string branch2 = makeName("L_A_E");
        dst<<"#Logical_and_expression_if_2_1\n";

        dst<<"\tlw\t$t0,($sp)\n";//later one in stack
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tlw\t$2,($sp)\n";//earlier one in stack
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tbeq\t$2,$0,$"<<branch1<<"\n";
        dst<<"\tnop\n";
        dst<<"\tbeq\t$t0,$0,$"<<branch1<<"\n";
        dst<<"\tnop\n";

        dst<<"\tli\t$2,1\n";
        dst<<"\tb\t$"<<branch2<<"\n";

        dst<<"$"<<branch1<<":\n";
        dst<<"\tmove\t$2,$0\n";

        dst<<"$"<<branch2<<":\n";
        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";
    }
}

void Inclusive_or_expression::compile(std::ostream &dst, Context& context) const{
    if(inclusive_or_expr==NULL&&exclusive_or_expr!=NULL){
        exclusive_or_expr->compile(dst,context);
    }
    else if(inclusive_or_expr!=NULL&&exclusive_or_expr!=NULL){
        inclusive_or_expr->compile(dst,context);
        exclusive_or_expr->compile(dst,context);
        dst<<"#Inclusive_or_expression_if_2_1\n";

        dst<<"\tlw\t$t0,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tlw\t$2,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tor\t$2,$2,$t0\n";

        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";
    }
}

void Exclusive_or_expression::compile(std::ostream &dst, Context& context) const{
    if(exclusive_or_expr==NULL&&and_expr!=NULL){
        and_expr->compile(dst,context);
    }
    else if(exclusive_or_expr!=NULL&&and_expr!=NULL){
        exclusive_or_expr->compile(dst,context);
        and_expr->compile(dst,context);
        dst<<"#Exclusive_or_expression_if_2_1\n";

        dst<<"\tlw\t$t0,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tlw\t$2,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\txor\t$2,$2,$t0\n";

        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";
    }
}

void And_expression::compile(std::ostream &dst, Context& context) const{
    if(and_expr==NULL&&equality_expr!=NULL){
        equality_expr->compile(dst,context);
    }
    else if(and_expr!=NULL&&equality_expr!=NULL){
        and_expr->compile(dst,context);
        equality_expr->compile(dst,context);
        dst<<"#And_expr_if_2_1\n";

        dst<<"\tlw\t$t0,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tlw\t$2,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tand\t$2,$2,$t0\n";

        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";
    }
}

void Equality_expression::compile(std::ostream &dst, Context& context) const{
    if(equality_expr==NULL&&relat_expr!=NULL){
        relat_expr->compile(dst,context);
    }
    else if(equality_expr!=NULL&&relat_expr!=NULL){
        equality_expr->compile(dst,context);
        relat_expr->compile(dst,context);
        if(*op=="=="){
            dst<<"#Equality_expr_if_2_1\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\txori\t$2,$2,$t0\n";
            dst<<"\tsltu\t$2,$2,1\n";

            dst<<"\tandi\t$2,$2,0x00ff\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
        else if(*op=="!="){
            dst<<"#Equality_expr_if_2_2\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\txori\t$2,$2,$t0\n";
            dst<<"\tsltu\t$2,$0,$2\n";

            dst<<"\tandi\t$2,$2,0x00ff\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
    }
}
void Relational_expression::compile(std::ostream &dst, Context& context) const{
    if(relat_expr==NULL&&shift_expr!=NULL){
        shift_expr->compile(dst,context);
    }
    else if(relat_expr!=NULL&&shift_expr!=NULL){
        relat_expr->compile(dst,context);
        shift_expr->compile(dst,context);
        if(*op=="<"){
            dst<<"#Relat_expr_if_2_1\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tslt\t$2,$2,$t0\n";
            dst<<"\tandi\t$2,$2,0x00ff\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
        else if(*op==">"){
            dst<<"#Relat_expr_if_2_2\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tslt\t$2,$t0,$2\n";
            dst<<"\tandi\t$2,$2,0x00ff\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
        else if(*op=="<="){
            dst<<"#Relat_expr_if_2_3\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\taddiu\t$t0,$t0,1\n";
            dst<<"\tslt\t$2,$2,$t0\n";
            dst<<"\tandi\t$2,$2,0x00ff\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
        else if(*op==">="){
            dst<<"#Relat_expr_if_2_4\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tslt\t$2,$2,$t0\n";
            dst<<"\txori\t$2,$2,0x1\n";
            dst<<"\tandi\t$2,$2,0x00ff\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
    }

}

void Shift_expression::compile(std::ostream &dst, Context& context) const{
    if(shift_expr==NULL&&additive_expr!=NULL){
        additive_expr->compile(dst,context);
    }
    else if(shift_expr!=NULL&&additive_expr!=NULL){
        shift_expr->compile(dst,context);
        additive_expr->compile(dst,context);
        if(*op=="<<"){
            dst<<"#shift_expr_if_2_1\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tsll\t$2,$2,$t0\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
        else if(*op==">>"){
            dst<<"#shift_expr_if_2_2\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tsrl\t$2,$2,$t0\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }

    }
}

void Expression::compile(std::ostream &dst, Context& context) const{
    if(expr==NULL && assign_expr!=NULL){
        assign_expr->compile(dst,context);
    }
}

void Additive_expression::compile(std::ostream &dst, Context& context) const{
    if(additive_expr==NULL&&mult_expr!=NULL){// rule 1
        mult_expr->compile(dst,context);
        dst<<"#add_expr_if_1\n";

    }
    else if(additive_expr!=NULL&&mult_expr!=NULL){//rule 2 and 3
        additive_expr->compile(dst,context);
        mult_expr->compile(dst,context);
        if(*op=="+"){
            dst<<"#add_expr_if_2_1\n";

            dst<<"\tlw\t$t0,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\taddu\t$2,$2,$t0\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";
        }
        else if(*op=="-"){
            dst<<"#add_expr_if_2_2\n";

            dst<<"\tlw\t$t0,($sp)\n";//this is taking out right oprand
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tlw\t$2,($sp)\n";//this is taking out left oprand
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
            // context.element_position-=context.largest_decl;
            dst<<"\tsubu\t$2,$2,$t0\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";

        }

    }

}

void Multiplicative_expression::compile(std::ostream &dst, Context& context) const{
    if(mult_expr==NULL&&cast_expr!=NULL){//value stored in $2
        cast_expr->compile(dst,context);
        dst<<"#mult_expr_if_1\n";

        //cast_expr will store to stack
    }
    else if(mult_expr!=NULL&&cast_expr!=NULL){
        mult_expr->compile(dst,context);//result will be in the second top of stack
        cast_expr->compile(dst,context);//result top of stack

        dst<<"\tlw\t$t0,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        // context.element_position-=context.largest_decl;
        dst<<"\tlw\t$2,($sp)\n";
        dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";

        if(*op=="/"){
            dst<<"#add_expr_if_2_1\n";


            dst<<"\tdiv\t$2,$t0\n";
            dst<<"\tmflo\t$2\n";

        }
        else if(*op=="*"){
            dst<<"#add_expr_if_2_2\n";

            dst<<"\tmult\t$2,$t0\n";
            dst<<"\tmflo\t$2\n";
            dst<<"\tmfhi\t$3\n";
        }
        else if(*op=="%"){
            dst<<"#add_expr_if_2_3\n";

            dst<<"\tdiv\t$2,$t0\n";
            dst<<"\tmfhi\t$2\n";
        }
        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";
    }

}

void Cast_expression::compile(std::ostream &dst, Context& context) const{
    if(type_name==NULL&&unary_expr!=NULL){
        unary_expr->compile(dst,context);
        //unary_expr will store to stack
    }
    else if(type_name!=NULL&&unary_expr!=NULL){
        ///to implement type cast
    }

}

void Unary_expression::compile(std::ostream &dst, Context& context) const{
    if(postf_expr!=NULL){
        postf_expr->compile(dst,context);
        //postf_expr will store to stack
    }
    else if(unary_expr!=NULL&&oper!=NULL){
        if(*oper=="++"){
            //Increment variable
            postf_expr->compile(dst,context);
            //FOUND?
            if(context.variable_found){
                dst<<"\tlw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
                dst<<"\taddi\t$2,$2,1\n";
                dst<<"\tsw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
                //Increment value returned in the stack
                dst<<"\tlw\t$2,($sp)\n";
                dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
                dst<<"\taddi\t$2,$2,1\n";

                dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n";
                dst<<"\tsw\t$2,($sp)\n";
            }
        }
        else if(*oper=="--"){
            //Increment variable
            postf_expr->compile(dst,context);

            if(context.variable_found){
                dst<<"\tlw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
                dst<<"\taddi\t$2,$2,-1\n";
                dst<<"\tsw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
                //Increment value returned in the stack
                dst<<"\tlw\t$2,($sp)\n";
                dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
                dst<<"\taddi\t$2,$2,-1\n";

                dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n";
                dst<<"\tsw\t$2,($sp)\n";
            }
        }
        else if(*oper=="sizeof"){;}
    }
    else if(cast_expr!=NULL&&unary_op!=NULL){
        cast_expr->compile(dst,context);
        if(context.variable_found){
            dst<<"\tlw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";//load variable
        }
        else{
            dst<<"\tlw\t$2,($sp)\n";//load from stack a constant when it's not a variable
            dst<<"\taddiu\t$sp,$sp,"<<context.largest_decl<<"\n";
        }


        if(*unary_op=="+"){///value of variable unchanged
            //nothing to do
        }
        else if(*unary_op=="-"){///value of variable negated
            dst<<"\tsubu\t$2,$0,$2\n";
        }
        else if(*unary_op=="!"){///value of logical value flipped
            dst<<"\tsltu\t$2,$2,1\n";
            dst<<"\tandi\t$2,$2,0x00ff\n";
        }
        else if(*unary_op=="~"){///all bits inverted
            dst<<"\tnor\t$2,$0,$2\n";
        }
        else if(*unary_op=="&"){///return address of variable
            ///to be implemented later
        }
        else if(*unary_op=="*"){///operates on pointer and return the value of the memory space that the pointer is pointing to
            ///to be implemented later
        }


        if(context.variable_found){
            dst<<"\tsw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
        }

        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n";
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";  
    }///to do other rules
}

void Postfix_expression::compile(std::ostream &dst, Context& context) const{
    if(prim_expr!=NULL){///rule 3,4,5 to be implemented(function call with argument, function field and pointer)
        prim_expr->compile(dst,context);
    }
    else if(postf_expr!=NULL&&oper!=NULL&&identifier==NULL){
        ///need to retrieve variable value from stack and update its value
        if(*oper=="++"){
            postf_expr->compile(dst,context);
            //Increment variable
            dst<<"\tlw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
            dst<<"\taddi\t$2,$2,1\n";
            dst<<"\tsw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";


        }
        else if(*oper=="--"){
            postf_expr->compile(dst,context);
            dst<<"\tlw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
            dst<<"\taddi\t$2,$2,-1\n";
            dst<<"\tsw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";
        }
    }
    else if(postf_expr!=NULL&&expr!=NULL){
        ///rule 2, array
    }
    else if(postf_expr!=NULL && expr==NULL && arg_expr_list==NULL && oper==NULL && identifier==NULL){ //f()
        context.print_function_identifier = true;
        postf_expr->compile(dst,context);
        context.print_function_identifier = true;

    }

}


void Primary_expression::compile(std::ostream &dst, Context& context) const{
    if(constant!=NULL){
        dst<<"\tli\t$2,"<<*constant<<"\n";
        dst<<"#primary_expression_if_1\n";
        // dst<<"\tmove\t,$sp,$fp\n"
        dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
        // context.element_position+=context.largest_decl;
        dst<<"\tsw\t$2,($sp)\n";
    }
    if(identifier!=NULL){
        if(context.in_assignment_expression){
            for(int i = 0; i < context.variables.size(); i++){
                if(context.variables[i].name == *identifier){
                    context.variable_position = i;
                    context.variable_found = true;
                    return;
                }
            }
            context.variable_found = false;
        }
        else if(context.print_function_identifier){
            dst<<"\tjal\t"<<*identifier<<"\nnop\n";
            dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n"; ///might need to start pushing at 0 first instead of -4
            // context.element_position+=context.largest_decl;
            dst<<"\tsw\t$2,($sp)\n";

        }
        else{
            context.variable_found = false;
            std::vector<int> vect_decr= context.current_scope;

            for(int size = vect_decr.size(); size>0 && !context.variable_found; size--){
                for(int i = 0; i < context.variables.size() && !context.variable_found; i++){
                    if(context.variables[i].name == *identifier && context.variables[i].scope == vect_decr){
                        context.variable_position = i;
                        context.variable_found = true;
                    }
                }
                vect_decr.pop_back();
            }

            if(!context.variable_found){
                ;
                //Shift through global variables
            }

            if(context.variable_found){
                dst<<"\tlw\t$2,"<<context.variables[context.variable_position].stack_offset<<"($fp)\n";

                dst<<"\taddiu\t$sp,$sp,-"<<context.largest_decl<<"\n";
                dst<<"\tsw\t$2,($sp)\n";
            }

        }
    }
}

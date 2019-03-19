#include "ast.hpp"
#include "forward_declaration.hpp"
#include <iostream>


void Primary_expression::print_python(std::ostream &dst) const{
    if(constant != NULL){///only second rule implemented now
        std::cout<<"26"<<std::endl;
        dst<<strtod((*constant).c_str(), NULL);
    }
}


void Postfix_expression::print_python(std::ostream &dst) const{
    if(prim_expr != NULL){///first rule
        prim_expr->print_python(dst);
    }
    //rule 2 not applicable
    else if(postf_expr!=NULL){//rule 3 and 4
        for( int i = 0; i<indent_count; i++) { dst << "\t"; }
        dst<<"(";
        if(arg_expr_list!=NULL){
            arg_expr_list->print_python(dst);
        }
        dst<<")";
        in_function=false;
    }
    //other rules not applicable to python?
}


void Unary_expression::print_python(std::ostream &dst) const{
    if(postf_expr != NULL){//rule 1
        postf_expr->print_python(dst);
    }
    else if(unary_op==NULL){//rule 3
        std::cout<<"Should there be a unary operator linked?"<<std::endl;
    }
    else{
        dst<<" "<<*unary_op << " ";
        if(cast_expr!=NULL){
            cast_expr->print_python(dst);
        }
    }
    //should not need any more rules for python?
}


void Cast_expression::print_python(std::ostream &dst) const{
    if(unary_expr !=NULL){///first rule
        unary_expr->print_python(dst);
    }
    //no casting in python translator needed
}


void Multiplicative_expression::print_python(std::ostream &dst) const{
    if(cast_expr!=NULL && mult_expr==NULL){//only first rule implemented now
        std::cout<<"22a"<<std::endl;
        cast_expr->print_python(dst);
    }
}


void Additive_expression::print_python(std::ostream &dst) const{
    if(mult_expr!=NULL && additive_expr==NULL){///only first rule implemented now
        std::cout<<"21a"<<std::endl;
        mult_expr->print_python(dst);
    }
}


void Shift_expression::print_python(std::ostream &dst) const{
    if(additive_expr!=NULL && shift_expr==NULL){///only first rule implemented now
        std::cout<<"20a"<<std::endl;
        additive_expr->print_python(dst);
    }
}


void Relational_expression::print_python(std::ostream &dst) const{
    if(shift_expr!=NULL && relat_expr==NULL){///only first rule implemented now
        std::cout<<"19a"<<std::endl;
        shift_expr->print_python(dst);
    }
}


void Equality_expression::print_python(std::ostream &dst) const{
    if(relat_expr!=NULL && equality_expr==NULL){///only first rule implemented now
        std::cout<<"18a"<<std::endl;
        relat_expr->print_python(dst);
    }
}

void And_expression::print_python(std::ostream &dst) const{
    if(equality_expr!=NULL && and_expr==NULL){///only first rule implemented now
        std::cout<<"17a"<<std::endl;
        equality_expr->print_python(dst);
    }
}


void Exclusive_or_expression::print_python(std::ostream &dst) const{
    if(and_expr!=NULL && exclusive_or_expr==NULL){///only first rule implemened now
        std::cout<<"16a"<<std::endl;
        and_expr->print_python(dst);
    }
}


void Inclusive_or_expression::print_python(std::ostream &dst) const{
    if(exclusive_or_expr!=NULL && inclusive_or_expr==NULL){///only first rule implemented now
        std::cout<<"15a"<<std::endl;
        exclusive_or_expr->print_python(dst);
    }
}


void Logical_and_expression::print_python(std::ostream &dst) const{
    if(inclusive_or_expr!=NULL && logical_and_expr==NULL){///only first rule implemented
        std::cout<<"14a"<<std::endl;
        inclusive_or_expr->print_python(dst);
    }
}


void Logical_or_expression::print_python(std::ostream &dst) const{
    if(logical_and_expr!=NULL && logical_or_expr==NULL){///only first rule
        std::cout<<"13a"<<std::endl;
        logical_and_expr->print_python(dst);
    }
}

void Conditional_expression::print_python(std::ostream &dst) const{
    if(logic_or_expr!=NULL && cond_expr==NULL){///only first rule
        std::cout<<"12a"<<std::endl;
        logic_or_expr->print_python(dst);
    }
}


void Initializer::print_python(std::ostream &dst) const{
    if(assignment_expr!=NULL){///only first rule
        std::cout<<"11a"<<std::endl;
        assignment_expr->print_python(dst);
    }
}



void Assignment_expression::print_python(std::ostream &dst) const{

    if(cond_expr!=NULL){
        cond_expr->print_python(dst);
    }
    else if(unary_expr!=NULL){
        for(int i = 0; i<indent_count; i++){dst << "\t";}
        unary_expr->print_python(dst);

        if(assign_op == NULL){
            std::cout<<"Assignment operators are not linked to the Assignment_expression node, RIP"<<std::endl;
        }
        else{
            dst<<*assign_op<< " ";
        }
        if(assign_expr!=NULL){
            assign_expr->print_python(dst);

        }
    }
    if(!in_iteration && !in_function && !newline_selective){
        dst<<std::endl;
    }


}


void Init_declarator::print_python(std::ostream &dst) const{
    if(declarator!=NULL && initializer!=NULL){/// to be finished with declarator
        std::cout<<"9a"<<std::endl;

        declarator->print_python(dst);
        dst<<"=";
        initializer->print_python(dst);
        dst<<std::endl;
    }
    else if(declarator!=NULL && initializer==NULL){
        declarator->print_python(dst);
        dst<<"=0";
        dst<<std::endl;
    }
}


void Init_declarator_list::print_python(std::ostream &dst) const{
    if(init_decl_list==NULL && init_decl!=NULL){///only second rule implemented
        std::cout<<"8a"<<std::endl;
        init_decl->print_python(dst);
    }
    else if(init_decl_list!=NULL){
        std::cout<<"8b"<<std::endl;
        init_decl_list->print_python(dst);
        dst<<", ";
        init_decl->print_python(dst);
    }
}


void Direct_declarator::print_python(std::ostream &dst) const{
    switch(parse_rule_followed){
        case 1:
            std::cout<<"7a"<<std::endl;

            dst<<*identifier;
            break;
        case 7:
            std::cout<<"7b"<<std::endl;

            direct_decl->print_python(dst);
            dst<<"():"<<"\n";
            break;
    }
}


void Declarator::print_python(std::ostream &dst) const{
    if(pointer==NULL){///second rule
        std::cout<<"6a"<<std::endl;

        dir_decl->print_python(dst);
    }
    else if(pointer!=NULL){///first rule to be implemented here
        std::cout<<"6b"<<std::endl;

    }
}


void Declaration::print_python(std::ostream &dst) const{
    if(init_decl_list!=NULL){///only the initilised case
        std::cout<<"5a"<<std::endl;
        // decl_spec->print_python(dst);
        init_decl_list->print_python(dst);
    }
    else if(init_decl_list==NULL){
        std::cout<<"5b"<<std::endl;
        // decl_spec->print_python(dst);
        //nothing to do here

    }
}


void Type_specifier::print_python(std::ostream &dst) const{
//     if(type_spec!=NULL){///last few rules not implemented
//         std::cout<<"4a"<<std::endl;
//
//
//     }
}


void Declaration_specifiers::print_python(std::ostream &dst) const{
//     if(type_spec!=NULL){///only rule 3 and 4 implemented
//         std::cout<<"3a"<<std::endl;//only gets here when variable declared, not when function declared
//         //nothing to do here
//     }
//     if(decl_spec!=NULL){
//         std::cout<<"3b"<<std::endl;
//         //nothing to do here
//         // decl_spec->print_python(dst);
//     }
}


void Function_definition::print_python(std::ostream &dst) const{
    switch(parse_rule_followed){///case 1 and 3 support K&R style, not to be implemented
        // case 1:///decl_list might not need to be implemented in our compiler
        //     decl_spec->print_python(dst);
        //     decl->print_python(dst);
        //     decl_list->print_python(dst);
        //     compound_stmnt->print_python(dst);
        //     break;
        case 2: ///function int abc(){sflkdsjf}
            std::cout<<"2a"<<std::endl;

            // decl_spec->print_python(dst);//not needed because function only has return type int and void
            dst<<"def ";
            decl->print_python(dst);
            compound_stmnt->print_python(dst);
            break;
        // case 3:///decl_list might not need to be implemented in our compiler
        //     decl->print_python(dst);
        //     decl_list->print_python(dst);
        //     compound_stmnt->print_python(dst);
        //     break;
        case 4: ///function abc(){saldkfjsdflk}
            std::cout<<"2b"<<std::endl;

            decl->print_python(dst);
            compound_stmnt->print_python(dst);
            std::cout<<"hihihih"<<std::endl;
            std::cout<<"sdfsdfihih"<<std::endl;

            break;

    }
}


void External_declaration::print_python(std::ostream &dst) const{
    if(decl!=NULL){
        std::cout<<"1a"<<std::endl;

        dst<<std::endl;
        decl->print_python(dst);
        dst<<std::endl;
    }
    else if(funct_def!=NULL){
        std::cout<<"1b"<<std::endl;

        dst<<std::endl;
        funct_def->print_python(dst);
        dst<<std::endl;
    }
}



void Translation_unit::print_python(std::ostream &dst) const{
    std::cout<<"helloTranslationUnit"<<std::endl;

    if(external_decl!=NULL&&translation_unit==NULL){
        external_decl->print_python(dst);
    }
    else if(external_decl!=NULL && translation_unit!=NULL){
        translation_unit->print_python(dst);
        external_decl->print_python(dst);
    }
}


void Iteration_statement::print_python(std::ostream& dst) const{
    if(*keyword == "while" ){
        if(statement != NULL && expr != NULL){
            in_iteration = true;
            dst<<std::endl;

            for( int i = 0; i<indent_count; i++) { dst << "\t"; }

			dst << "while(";
			expr->print_python(dst);
			dst << "):" << std::endl;
            in_iteration = false;

            indent_count++;
            dst << std::endl;
            statement->print_python(dst);
            dst << std::endl;
            indent_count--;
	    }
    }
}


void Statement_list::print_python(std::ostream& dst) const{
    if(stmnt_list!=NULL){
        stmnt_list->print_python(dst);
        stmnt->print_python(dst);
    }
    else if(stmnt_list==NULL){
        stmnt->print_python(dst);
    }
}


void Statement::print_python(std::ostream& dst) const{

    if( labeled_stmnt != NULL ) {
        labeled_stmnt->print_python(dst);
    }

    else if( compound_stmnt != NULL ) {
        compound_stmnt->print_python(dst);
    }

    else if( expression_stmnt != NULL ) {
        expression_stmnt->print_python(dst);
    }

    else if( selection_stmnt != NULL ) {
        selection_stmnt->print_python(dst);
    }

    else if( iteration_stmnt != NULL ) {
        iteration_stmnt->print_python(dst);
    }

    else if( jump_stmnt != NULL ) {
        jump_stmnt->print_python(dst);
    }

}


void Compound_statement::print_python(std::ostream& dst) const{

    indent_count++;
    if(stmnt_list == NULL && decl_list == NULL) {
        std::cout<<"100a"<<std::endl;

        for( int i(0); i<indent_count; i++) { dst << "\t"; }
        dst << "pass" << std::endl;
    }
    else if(stmnt_list != NULL && decl_list != NULL) {
        std::cout<<"100b"<<std::endl;

        decl_list->print_python(dst);
        stmnt_list->print_python(dst);
    }
    else if(stmnt_list == NULL && decl_list != NULL) {
        std::cout<<"100c"<<std::endl;

        decl_list->print_python(dst);
    }
    else if(stmnt_list != NULL && decl_list == NULL) {
        std::cout<<"100d"<<std::endl;

        stmnt_list->print_python(dst);
    }
    indent_count--;

}


void Selection_statement::print_python(std::ostream& dst) const{

    if(!switch_stmnt){
        if(else_statement == NULL){

            newline_selective = true;

            for(int i = 0; i<indent_count; i++){dst << "\t";}
            dst<<"if(";
            expr->print_python(dst);
            dst<<"):"<<std::endl;

            newline_selective = false;
            indent_count++;
            dst << std::endl;
            if_statement->print_python(dst);
            dst << std::endl;
            indent_count--;
        }
        else{
            newline_selective = true;

            for(int i = 0; i<indent_count; i++){dst << "\t";}
            dst<<"if(";
            expr->print_python(dst);
            dst<<"):"<<std::endl;

            newline_selective = false;

            indent_count++;
            dst << std::endl;
            if_statement->print_python(dst);
            dst << std::endl;
            indent_count--;

            for(int i = 0; i<indent_count; i++){dst << "\t";}
            dst<<"else:" <<std::endl;

            indent_count++;
            dst << std::endl;
            else_statement->print_python(dst);
            dst << std::endl;
            indent_count--;
        }
    }

}

void Jump_statement::print_python(std::ostream& dst) const{
    for(int i = 0; i<indent_count; i++){dst << "\t";}
    if(*keyword == "return"){
        dst << *keyword << " ";
        if(expr != NULL){
            expr->print_python(dst);
        }
    }

}

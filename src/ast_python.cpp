print_python/// #include <all the ast nodes somehow>
int indent_count(0);
bool in_iteration(false);
bool in_selective(false);
bool in_function(false);


virtual void Primary_expression::print_python(std::ostream &dst) const{
    if(constant != NULL){///only second rule implemented now
        dst<<strtod(constant);
    }
}


virtual void Postfix_expression::print_python(std::ostream &dst) const{
    if(prim_expr != NULL){///only first rule implemented now
        prim_expr->print_python(dst);
    }
}


virtual void Unary_expression::print_python(std::ostream &dst) const{
    if(postf_expr != NULL){///only first rule implemented now
        postf_expr->print_python(dst);
    }
}


virtual void Cast_expression::print_python(std::ostream &dst) const{
    if(unary_expr !=NULL){///only first rule implemented now
        unary-expr->print_python(dst);
    }
}


virtual void Multiplicative_expression::print_python(std::ostream &dst) const{
    if(cast_expr!=NULL && mult_expr==NULL){//only first rule implemented now
        cast_expr->print_python(dst);
    }
}


virtual void Additive_expression::print_python(std::ostream &dst) const{
    if(mult_expr!=NULL && additive_expr==NULL){///only first rule implemented now
        mult_expr->print_python(dst);
    }
}


virtual void Shift_expression::print_python(std::ostream &dst) const{
    if(additive_expr!=NULL && shift_expr==NULL){///only first rule implemented now
        additive_expr->print_python(dst);
    }
}


virtual void Relational_expression::print_python(std::ostream &dst) const{
    if(shift_expr!=NULL && relat_expr==NULL){///only first rule implemented now
        shift_expr->print_python(dst);
    }
}


virtual void Equality_expression::print_python(std::ostream &dst) const{
    if(relat_expr!=NULL && equality_expr==NULL){///only first rule implemented now
        relat_expr->print_python(dst);
    }
}

virtual void And_expression::print_python(std::ostream &dst) const{
    if(equality_expr!=NULL && and_expr==NULL){///only first rule implemented now
        equality_expr->print_python(dst);
    }
}


virtual void Exclusive_or_expression::print_python(std::ostream &dst) const{
    if(and_expr!=NULL && exclusive_or_expr==NULL){///only first rule implemened now
        and_expr->print_python(dst);
    }
}


virtual void Inclusive_or_expression::print_python(std::ostream &dst) const{
    if(exclusive_or_expr!=NULL && inclusive_or_expr==NULL){///only first rule implemented now
        exclusive_or_expr->print_python(dst);
    }
}


virtual void Logical_and_expression::print_python(std::ostream &dst) const{
    if(inclusive_or_expr!=NULL && logical_and_expr==NULL){///only first rule implemented
        inclusive_or_expr->print_python(dst);
    }
}


virtual void Logical_or_expression::print_python(std::ostream &dst) const{
    if(logical_and_expr!=NULL && logical_or_expr==NULL){///only first rule
        logical_and_expr->print_python(dst);
    }
}

virtual void Conditional_expression::print_python(std::ostream &dst) const{
    if(logic_or_expr!=NULL && cond_expr==NULL){///only first rule
        logic_or_expr->print_python(dst);
    }
}


virtual void Initializer::print_python(std::ostream &dst) const{
    if(assignment_expr!=NULL){///only first rule
        assignment_expr->print_python(dst);
    }
}



virtual void Assignment_expression::print_python(std::ostream &dst) const{
    if(cond_expr!=NULL){///only first rule
        cond_expr->print_python(dst);
    }
}


virtual void Init_declarator::print_python(std::ostream &dst) const{
    if(declarator!=NULL && initializer!=NULL){//// to be finished with declarator
        dst<<declarator->print_python(dst)<<"="<<initializer->print_python(dst)<<std::endl;
    }
}


virtual void Init_declarator_list::print_python(std::ostream &dst) const{
    if(init_decl_list==NULL && init_decl!=NULL){///only second rule implemented
        init_decl->print_python(dst);
    }
    else if(init_decl_list!=NULL){
        init_decl_list->print_python(dst);
        init_decl->print_python(dst);
    }
}


virtual void Declaration::print_python(std::ostream &dst) const{
    if(init_decl_list!=NULL){///only the initilised case
        init_decl_list->print_python(dst);
    }
}

virtual void External_declaration::print_python(std::ostream &dst) const{
    if(decl!=NULL){///only second rule
        decl->print_python(dst);
    }
}


virtual void Translation_unit::print_python(std::ostream &dst) const{
    if(external_decl!=NULL&&translation_unit==NULL){
        external_decl->print_python(dst);
    }
}


void Iteration_statement:print_python(std::ofstream& dst){
    if(*keyword == "while" ){
        if(statement != NULL && expr != NULL){
            in_while = true;
            dst<<std::endl;

            for( int i = 0; i<indent_count; i++) { dst << "\t"; }

			dst << "while(";
			expr->print_python(dst);
			dst << "):" << std::endl;

            if(statement->compound_stmnt != NULL) {   //dont need to indent here if it is a compound statement, compound statement should allways be indented when called      independantly, so no need to indent twice
                statement->print_python(dst);
                dst << std::endl;
            }
            else{
                indent_count++;
                statement->print_python(dst);
                indent_count--;
                dst << std::endl;
            }
	    }
    }
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

            decl_spec->print_python(dst);
            decl->print_python(dst);
            compound_stmnt->print_python(dst);
            break;
        // case 3:///decl_list might not need to be implemented in our compiler
        //     decl->print_python(dst);
        //     decl_list->print_python(dst);
        //     compound_stmnt->print_python(dst);
        //     break;
        case 4: ///
            std::cout<<"2b"<<std::endl;

            decl->print_python(dst);
            compound_stmnt->print_python(dst);
            std::cout<<"hihihih"<<std::endl;
            break;
    }
}


void Statement:print_python(std::ofstream& dst){

    if( labeled_stmnt != NULL ) {
        labeled_stmnt->print_python(dst);
    }

    else if( compound_stmnt != NULL ) {
        indent_count++;
        compound_stmnt->print_python(dst);
        indent_count--;
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


void Compound_statement:print_python(std::ofstream& dst){

    if( stmnt_list == NULL && decl_list == NULL ) {
        for( int i(0); i<counter_py; i++) { dst << "\t"; }
        dst << "pass" << std::endl;
    }
    else if( stmnt_list != NULL && decl_list != NULL ) {
        decl_list->print_py(dst);
        stmnt_list->print_py(dst);
    }
    else if( stmnt_list == NULL && decl_list != NULL ) {
        decl_list->print_py(dst);
    }
    else if( stmnt_list != NULL && decl_list == NULL ) {
        stmnt_list->print_py(dst);
    }

}

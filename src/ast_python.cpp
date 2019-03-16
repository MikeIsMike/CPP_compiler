/// #include <all the ast nodes somehow>
#include "ast.hpp"

void Primary_expression::print_python(std::ostream &dst) const{
    if(constant != NULL){///only second rule implemented now
        dst<<strtod((*constant).c_str(), NULL);
    }
}


void Postfix_expression::print_python(std::ostream &dst) const{
    if(prim_expr != NULL){///only first rule implemented now
        prim_expr->print_python(dst);
    }
}


void Unary_expression::print_python(std::ostream &dst) const{
    if(postf_expr != NULL){///only first rule implemented now
        postf_expr->print_python(dst);
    }
}


void Cast_expression::print_python(std::ostream &dst) const{
    if(unary_expr !=NULL){///only first rule implemented now
        unary-expr->print_python(dst);
    }
}


void Multiplicative_expression::print_python(std::ostream &dst) const{
    if(cast_expr!=NULL && mult_expr==NULL){//only first rule implemented now
        cast_expr->print_python(dst);
    }
}


void Additive_expression::print_python(std::ostream &dst) const{
    if(mult_expr!=NULL && additive_expr==NULL){///only first rule implemented now
        mult_expr->print_python(dst);
    }
}


void Shift_expression::print_python(std::ostream &dst) const{
    if(additive_expr!=NULL && shift_expr==NULL){///only first rule implemented now
        additive_expr->print_python(dst);
    }
}


void Relational_expression::print_python(std::ostream &dst) const{
    if(shift_expr!=NULL && relat_expr==NULL){///only first rule implemented now
        shift_expr->print_python(dst);
    }
}


void Equality_expression::print_python(std::ostream &dst) const{
    if(relat_expr!=NULL && equality_expr==NULL){///only first rule implemented now
        relat_expr->print_python(dst);
    }
}

void And_expression::print_python(std::ostream &dst) const{
    if(equality_expr!=NULL && and_expr==NULL){///only first rule implemented now
        equality_expr->print_python(dst);
    }
}


void Exclusive_or_expression::print_python(std::ostream &dst) const{
    if(and_expr!=NULL && exclusive_or_expr==NULL){///only first rule implemened now
        and_expr->print_python(dst);
    }
}


void Inclusive_or_expression::print_python(std::ostream &dst) const{
    if(exclusive_or_expr!=NULL && inclusive_or_expr==NULL){///only first rule implemented now
        exclusive_or_expr->print_python(dst);
    }
}


void Logical_and_expression::print_python(std::ostream &dst) const{
    if(inclusive_or_expr!=NULL && logical_and_expr==NULL){///only first rule implemented
        inclusive_or_expr->print_python(dst);
    }
}


void Logical_or_expression::print_python(std::ostream &dst) const{
    if(logical_and_expr!=NULL && logical_or_expr==NULL){///only first rule
        logical_and_expr->print_python(dst);
    }
}

void Conditional_expression::print_python(std::ostream &dst) const{
    if(logic_or_expr!=NULL && cond_expr==NULL){///only first rule
        logic_or_expr->print_python(dst);
    }
}


void Initializer::print_python(std::ostream &dst) const{
    if(assignment_expr!=NULL){///only first rule
        assignment_expr->print_python(dst);
    }
}



void Assignment_expression::print_python(std::ostream &dst) const{
    if(cond_expr!=NULL){///only first rule
        cond_expr->print_python(dst);
    }
}


void Init_declarator::print_python(std::ostream &dst) const{
    if(declarator!=NULL && initializer!=NULL){//// to be finished with declarator
        dst<<declarator->print_python(dst)<<"="<<initializer->print_python(dst)<<std::endl;
    }
}


void Init_declarator_list::print_python(std::ostream &dst) const{
    if(init_decl_list==NULL && init_decl!=NULL){///only second rule implemented
        init_decl->print_python(dst);
    }
    else if(init_decl_list!=NULL){
        init_decl_list->print_python(dst);
        init_decl->print_python(dst);
    }
}


void Direct_declarator::print_python(std::ostream &dst) const{
    switch(parse_rule_followed){
        case 1:
            dst<<*identifier;
        case 7:
            dir_decl->print_python(dst);
            dst<<"():"<<"\n";
            break;
    }
}


void Declarator::print_python(std::ostream &dst) const{
    if(pointer==NULL){///only second rule implemented
        dir_decl->print_python(dst);
    }
    else if(pointer!=NULL){///first rule to be implemented here

    }
}


void Declaration::print_python(std::ostream &dst) const{
    if(init_decl_list!=NULL){///only the initilised case
        init_decl_list->print_python(dst);
    }
}


void Declaration_specifiers::print_python(std::ostream &dst) const{
    if(type_spec!=NULL){///last few rules not implemented
        dst<<def<<" ";
    }


void Declaration_specifiers::print_python(std::ostream &dst) const{
    if(type_spec!=NULL){///only rule 3 and 4 implemented
        type_spec->print_python(dst);
    }
    if(decl_spec!=NULL){
        decl_spec->print_python(dst);
    }



void Function_definition::print_python(std::ostream &dst) const{
    switch(parse_rule_followed){
        // case 1:///decl_list might not need to be implemented in our compiler
        //     decl_spec->print_python(dst);
        //     decl->print_python(dst);
        //     decl_list->print_python(dst);
        //     compound_stmnt->print_python(dst);
        //     break;
        case 2:
            decl_spec->print_python(dst);
            decl->print_python(dst);
            compound_stmnt->print_python(dst);
            break;
        // case 3:///decl_list might not need to be implemented in our compiler
        //     decl->print_python(dst);
        //     decl_list->print_python(dst);
        //     compound_stmnt->print_python(dst);
        //     break;
        case 4:
            decl->print_python(dst);
            compound_stmnt->print_python(dst);
            break;
    }
}


virtual void External_declaration::print_python(std::ostream &dst) const{
    if(decl!=NULL){///only second rule
        decl->print_python(dst);
    }
    else if(funct_def!=NULL){
        funct_def->print_python(dst);
    }
}


virtual void Translation_unit::print_python(std::ostream &dst) const{
    if(external_decl!=NULL&&translation_unit==NULL){
        external_decl->print_python(dst);
    }
    else if(external_decl!=NULL && translation_unit!=NULL){
        translation_unit->print_python(dst);
        external_decl->print_python(dst);
    }
}

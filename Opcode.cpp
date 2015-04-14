//
//  Opcode.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 14/04/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include "Opcode.h"

namespace CPU_6811 {
    
    
    Opcode::Opcode()
    :
    name("INVALID"),
    prebyte(""),
    opcode(""),
    op_size(0),
    total_size(0)
    {
    }
    
    Opcode::Opcode(std::string name, std::string prebyte, std::string opcode, int op_size, int total_size)
    :
    name(name),
    prebyte(prebyte),
    opcode(opcode),
    op_size(op_size),
    total_size(total_size)
    {
    }
    
    Opcode::~Opcode(){}
    
    std::string Opcode::get_name(){
        return this->name;
    }
    
    std::string Opcode::get_prebyte(){
        return this->prebyte;
    }
    
    std::string Opcode::get_opcode(){
        return this->opcode;
    }
    
    int Opcode::get_op_size(){
        return this->op_size;
    }
    
    int Opcode::get_total_size(){
        return this->total_size;
    }


}
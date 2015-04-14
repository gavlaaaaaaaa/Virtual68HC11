//
//  CPU.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 12/04/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include "CPU.h"

#include <iostream>

namespace CPU_6811
{
    
    CPU::CPU(std::shared_ptr<Memory> p_TheMemory)
    :
    c_ReservedAddress(0),
    c_BaseAddress(1),
    c_AddressCeiling(765),
    ACC_A(0),
    ACC_B(0),
    DBL_ACC_D(0),
    REG_X(0),
    REG_Y(0),
    SP(c_BaseAddress),
    PC(c_BaseAddress),
    b_carry(false),
    b_overflow(false),
    b_zero(false),
    b_negative(false),
    b_interrupt(false),
    b_half(false),
    b_Xinterrupt(false),
    b_stop_disable(false),
    b_halt(false),
    m_TheMemory(p_TheMemory),
    opcodes({})
    {
    }
    
    CPU::~CPU()
    {
        m_TheMemory = nullptr;
    }
    
    void CPU::Reset()
    {
        PC = c_BaseAddress;
        b_carry = false;
        b_overflow = false;
        b_zero = false;
        b_negative = false;
        b_interrupt = false;
        b_half = false;
        b_Xinterrupt = false;
        b_stop_disable = false;
        b_halt = false;
    }
    
    void CPU::Run(){
        
        while (!b_halt) {
            std::cout << "Reading from location: " << PC << std::endl;
            this->Decode(this->Fetch());
        }
    }
    
    const int8_t CPU::Fetch(){
        char opcode = m_TheMemory->read(PC);
        ++PC;

        return opcode;
    }
    
    void CPU::Decode(const int8_t &p_OpCode){
        
        switch (p_OpCode) {
            case 0:
                std::cout << "\n!!!! Halt has been called !!!!\n" << std::endl;
                b_halt = true;
                break;
                
            default:
                break;
        }
    }
    
    std::vector<Opcode>& CPU::get_opcodes(){
        
        if(!opcodes.empty()){
            //Already initialised... so just return opcode vector
            return opcodes;
        }
        
        //Opcode vector is empty... so lets initialise it
        
        return opcodes;
    }
    

}
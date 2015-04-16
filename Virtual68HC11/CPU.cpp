//
//  CPU.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 12/04/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include "CPU.h"

#include <iostream>
#include <fstream>
#include <sstream>

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

        std::ifstream opcode_file(ops_metadata_path);
        std::string curr_line = "";
        
        std::string name, prebyte, opcode, total_size, temp;
        int op_size = 1;
        std::getline(opcode_file, curr_line);
        
        std::string prev_name = "";
        while(std::getline(opcode_file, curr_line)){
            
            std::istringstream split_me(curr_line);
            std::getline(split_me, name,',');
            std::getline(split_me, prebyte,',');
            std::getline(split_me, opcode,',');
            //throw away operands for now
            std::getline(split_me, temp, ',');
            std::getline(split_me, total_size,',');
            
            if (name == "") { name = prev_name; } else { prev_name = name; }
            if (!std::isdigit(prebyte[0])){ prebyte = ""; } else { op_size++; }

            opcodes.push_back(Opcode(name, prebyte, opcode, op_size, std::stoi(total_size)));
            // reset op_size;
            op_size = 1;
        }
        
        
        
        return opcodes;
    }
    
    int CPU::get_value(char loc){
        
        switch (loc) {
            case 'A':
                return ACC_A;
                break;
            case 'B':
                return ACC_B;
                break;
            case 'X':
                return REG_X;
                break;
            case 'Y':
                return REG_Y;
                break;
            default:
                return 0;
                break;
        }
    }
    
    void CPU::set_result(char loc, int16_t result){
        
        switch (loc) {
            case 'A':
                ACC_A = result;
                break;
            case 'B':
                ACC_B = result;
                break;
            case 'X':
                REG_X = result;
                break;
            case 'Y':
                REG_Y = result;
                break;
                // 'Z' means split result into A and B
            case 'Z':
                ACC_A = result >> 8;
                ACC_B = result & 0xFF;
                break;
            default:
                //TODO: throw a proper error here
                std::cout << "ERROR: INCORRECT LOCATION GIVEN TO SET_RESULT" << std::endl;
                break;
        }
    }
    
    
    void CPU::Add(char left, char right, char result_location, bool carry){
        int16_t result = get_value(left) + get_value(right);

        set_result(result_location, result);
        
    }
    

}
//
//  CPU.h
//  Virtual68HC11
//
//  Created by Lewis Gavin on 12/04/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#ifndef __Virtual68HC11__CPU__
#define __Virtual68HC11__CPU__

#include "Memory.h"
#include "Opcode.h"
#include <vector>

namespace CPU_6811 {
    
    class CPU{
        
    public:
        const int c_ReservedAddress;
        const int c_BaseAddress;
        const int c_AddressCeiling;
        
    private:
        //accumulators and registers
        std::vector<Opcode> opcodes;
        int8_t ACC_A;
        int8_t ACC_B;
        int16_t DBL_ACC_D;
        int16_t REG_X;
        int16_t REG_Y;
        int16_t SP;
        int16_t PC;
        //condition code register values
        bool b_carry, b_overflow, b_zero, b_negative, b_interrupt, b_half, b_Xinterrupt, b_stop_disable;
        //Halt flag
        bool b_halt;
        
        const std::string ops_metadata_path = "/Users/Gav/Documents/Programming/Virtual68HC11/Virtual68HC11/6811_ops_metadata.csv";
        
        std::shared_ptr<Memory> m_TheMemory;
        const int8_t Fetch();
        void Decode(const int8_t& p_OpCode);
        void Halt();
        void Add();
        void Beep();
        void Store();
        void Print();
        
        
        
    public:
        CPU(std::shared_ptr<Memory> p_TheMemory);
        ~CPU();
        void Reset();
        void Run();
        std::vector<Opcode>& get_opcodes();
        
    };
}



#endif /* defined(__Virtual68HC11__CPU__) */

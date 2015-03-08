//
//  Memory.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//
//
#include "Memory.h"

namespace CPU_6811 {
    
    Memory::Memory():
    c_MaxMemSize(768),
    p_TheMemory(new byte[c_MaxMemSize])
    {
    }
    
    Memory::~Memory(){}

    void Memory::write(const byte& p_Address, const byte& p_Value){
        p_TheMemory[p_Address] = p_Value;
    }

    const byte& Memory::read(const byte& p_Address){
        return p_TheMemory[p_Address];
    }

}
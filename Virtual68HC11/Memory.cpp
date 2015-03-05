//
//  Memory.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include "Memory.h"

namespace CPU_6811 {
    
    Memory::Memory(){}
    
    Memory::~Memory(){}

    void Memory::write(const byte& p_Address, const byte& p_Value){
        
    }

    const byte& Memory::read(const byte& p_Address){
        return 10;
    }

}
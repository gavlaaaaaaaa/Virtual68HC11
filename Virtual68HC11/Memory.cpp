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
    c_MaxMemSize(768)
    {
        clear();
    }
    
    Memory::~Memory(){
        
    }

    void Memory::clear(){
        for(int i = 0; i < c_MaxMemSize; ++i){
            p_TheMemory[i] = 0;
        }
    }
    
    void Memory::write(const int& p_Address, const char& p_Value){
        if(p_Address > c_MaxMemSize){
            fprintf(stderr, "Address out of bounds - could not complete write\n");
            exit(1);
        }
        else{
            p_TheMemory[p_Address] = p_Value;
        }
    }

    const char& Memory::read(const int& p_Address){
        if(p_Address > c_MaxMemSize){
            fprintf(stderr, "Address out of bounds - could not complete read\n");
            exit(1);
        }
        else{
            return p_TheMemory[p_Address];
        }
        
    }

}
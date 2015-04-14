//
//  Memory.h
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#ifndef __Virtual68HC11__Memory__
#define __Virtual68HC11__Memory__

#include <iostream>
#include <array>

namespace CPU_6811 {
    
    class Memory{
        
    
        
    private:
        std::array<char, 768> p_TheMemory;
        
    public:
        int c_MaxMemSize;
        
    private:
        
        void clear();
    
    public:
        Memory();
        
        ~Memory();
        
        void write(const int& p_Address, const char& p_Value);
        
        const char& read(const int& p_Address);


};
    
}
#endif /* defined(__Virtual68HC11__Memory__) */

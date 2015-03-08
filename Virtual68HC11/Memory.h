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

namespace CPU_6811 {
    
    //byte sized char to act as a byte
    typedef unsigned char byte;


    class Memory{
        
    private:
        byte* p_TheMemory;
        
    public:
        int c_MaxMemSize;
    
    public:
        Memory();
        
        ~Memory();
        
        void write(const int& p_Address, const byte& p_Value);
        
        const byte& read(const int& p_Address);


};
    
}
#endif /* defined(__Virtual68HC11__Memory__) */

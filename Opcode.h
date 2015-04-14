//
//  Opcode.h
//  Virtual68HC11
//
//  Created by Lewis Gavin on 14/04/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#ifndef __Virtual68HC11__Opcode__
#define __Virtual68HC11__Opcode__

#include <iostream>

namespace CPU_6811 {
    
    class Opcode {
        
        
    private:
        std::string name;
        std::string prebyte;
        std::string opcode;
        //without operands
        int op_size;
        // with operands
        int total_size;
        
    public:
        
        Opcode();
        Opcode(std::string name, std::string prebyte, std::string opcode, int op_size, int total_size);
        ~Opcode();
        
        std::string get_name();
        std::string get_prebyte();
        std::string get_opcode();
        int get_op_size();
        int get_total_size();
        
        
    };
}

#endif /* defined(__Virtual68HC11__Opcode__) */

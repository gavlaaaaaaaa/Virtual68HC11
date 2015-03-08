//
//  MemoryTest.h
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#ifndef __Virtual68HC11__MemoryTest__
#define __Virtual68HC11__MemoryTest__


#include "gtest/gtest.h"

class MemoryTest : public ::testing::Test {
    
private:
    CPU_6811::Memory* mem;
    int address;
    CPU_6811::byte value;
    
public:
    
    void init(const int& addr, const CPU_6811::byte& val);
    
    void de_init();
    
    //Test 1
    void permitted_write();
    
    //Test 2
    void permitted_read();
    
    //Test3
    void bad_write();
    
    //Test 4
    void bad_read();
    
};

#endif /* defined(__Virtual68HC11__MemoryTest__) */

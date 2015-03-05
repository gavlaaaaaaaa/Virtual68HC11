//
//  MemoryTest.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include "Memory.h"
#include "MemoryTest.h"

//Test 1 - Test whether a value is written successfully to memory
TEST_F(MemoryTest, PermittedTest){
    permitted_write();
}
void MemoryTest::permitted_write(){
    CPU_6811::Memory* mem = new CPU_6811::Memory();
    CPU_6811::byte address = 1;
    CPU_6811::byte value = 10;
    
    mem->write(address, value);
    
    EXPECT_EQ((int)value, (int)mem->read(address));
    
    delete mem;
}
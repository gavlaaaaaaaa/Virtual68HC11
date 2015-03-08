//
//  MemoryTest.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include "Memory.h"
#include "MemoryTest.h"

void MemoryTest::init(const int& addr, const CPU_6811::byte& val){
    mem = new CPU_6811::Memory();
    address = addr;
    value = val;
}

void MemoryTest::de_init(){
    address = 0;
    value = 0;
    delete mem;
}

//Test 1 - Test whether a value is written successfully to memory
TEST_F(MemoryTest, PermittedWrite){
    permitted_write();
}
void MemoryTest::permitted_write(){
    init(1,10);
    
    mem->write(address, value);
    
    EXPECT_EQ((int)value, (int)mem->read(address));
    
    de_init();
}


//Test 2
TEST_F(MemoryTest, PermittedRead){
    permitted_read();
}
void MemoryTest::permitted_read(){
    init(20,100);
    
    mem->write(address, value);
    EXPECT_EQ((int)value, (int)mem->read(address));
    
    de_init();
}

//Test3
TEST_F(MemoryTest, BadWrite){
    bad_write();
}
void MemoryTest::bad_write(){
    init(800,1);
    
    EXPECT_EXIT(mem->write(address, value), ::testing::ExitedWithCode(1), "Address out of bounds - could not complete write\n");
    
    de_init();
    
}


//Test 4
TEST_F(MemoryTest, BadRead){
    bad_read();
}
void MemoryTest::bad_read(){
    init(999,1);
    
    EXPECT_EXIT(mem->read(address), ::testing::ExitedWithCode(1), "Address out of bounds - could not complete read\n");
    
    de_init();
    
}

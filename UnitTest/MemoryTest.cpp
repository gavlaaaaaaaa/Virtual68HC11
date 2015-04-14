//
//  MemoryTest.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include "Memory.h"
#include "MemoryTest.h"

void MemoryTest::init(const int& addr, const char& val){
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


//Test 2 - Test whether a value is read successfully from memory
TEST_F(MemoryTest, PermittedRead){
    permitted_read();
}
void MemoryTest::permitted_read(){
    init(20,100);
    
    mem->write(address, value);
    EXPECT_EQ((int)value, (int)mem->read(address));
    
    de_init();
}

//Test3 - Test that an out of bounds write fails
TEST_F(MemoryTest, BadWrite){
    bad_write();
}
void MemoryTest::bad_write(){
    init(800,1);
    
    EXPECT_EXIT(mem->write(address, value), ::testing::ExitedWithCode(1), "Address out of bounds - could not complete write\n");
    
    de_init();
    
}


//Test 4 - Test that an out of bounds read fails
TEST_F(MemoryTest, BadRead){
    bad_read();
}
void MemoryTest::bad_read(){
    init(999,1);
    
    EXPECT_EXIT(mem->read(address), ::testing::ExitedWithCode(1), "Address out of bounds - could not complete read\n");
    
    de_init();
    
}

//Test 5 - Test that writing to an occupied memory address overwrites the value
TEST_F(MemoryTest, OverWrite){
    overwrite();
}
void MemoryTest::overwrite(){
    init(1,10);
    
    mem->write(address, value);
    
    EXPECT_EQ((int)value, (int)mem->read(address));
    
    mem->write(address,20);
    
    EXPECT_EQ(20, (int)mem->read(address));
    
    de_init();
    
}

//Test 6 - Test that the memory can hold multiple values in different addresses
TEST_F(MemoryTest, DoubleWrite){
    double_write();
}
void MemoryTest::double_write(){
    //will write value 10 to address 1
    permitted_write();
    
    init(2,10);
    
    mem->write(address, value);
    EXPECT_EQ((int)value, (int)mem->read(address));
    
    de_init();
}


//Test 7
TEST_F(MemoryTest, CheckClear){
    check_clear();
}
void MemoryTest::check_clear(){
    init(1,1);
    //Initialise memory variable - should call clear()
    
    for(int i = 0; i < mem->c_MaxMemSize; ++i){
        EXPECT_EQ(0, (int)mem->read(i));
    }
    
    de_init();
    
}

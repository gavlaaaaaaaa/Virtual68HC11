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
    
public:
    //Test 1
    void permitted_write();
    
};

#endif /* defined(__Virtual68HC11__MemoryTest__) */

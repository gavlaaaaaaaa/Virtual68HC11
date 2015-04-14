//
//  main.cpp
//  Virtual68HC11
//
//  Created by Lewis Gavin on 05/03/2015.
//  Copyright (c) 2015 GavPlusPlus. All rights reserved.
//

#include <iostream>
#include "Memory.h"
#include "CPU.h"

int main(int argc, const char * argv[])
{

    std::cout << "Init Memory...";
    std::shared_ptr<CPU_6811::Memory> theMemory(new CPU_6811::Memory);
    std::cout << "Ready" << std::endl;
    
    
    std::cout << "Memory Size: " << theMemory->c_MaxMemSize << std::endl;
    
    std::cout << "Do you want to list the memory?";
    char yesNo;
    std::cin >> yesNo;
    if ( yesNo == 'Y' || yesNo == 'y' )
    {
        for (int currentAddress = 0; currentAddress < theMemory->c_MaxMemSize; ++currentAddress)
        {
            std::cout << "Address [" << currentAddress << "] = " << (int)theMemory->read(currentAddress) << std::endl;
        }
    }
    
    
    std::cout << "Creating the CPU instance...";
    std::shared_ptr<CPU_6811::CPU> theCPU (new CPU_6811::CPU(theMemory));
    std::cout << "Ready" << std::endl;
    
    std::cout << "Starting..." << std::endl;
    theCPU->Run();
    std::cout << "Complete" << std::endl;

    
    
    return 0;
}


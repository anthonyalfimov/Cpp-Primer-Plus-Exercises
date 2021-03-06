//
//  801.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

namespace
{
    unsigned int callCount {0};      // Using global variable with internal linkage
                                     // to make it accesible to show801() function
    void weirdPrint(const char * text, int isWeird = 0);
}

//   =============================
//   |       Main function       |
//   =============================
void show801()
{
    std::cout << "Attempt repeated print with " << callCount << " function calls:\n";
    weirdPrint("Test text 1", 1);
    std::cout << "Normal print using the default parameter:\n";
    weirdPrint("Test text 2");
    std::cout << "Repeated print after " << callCount << " function calls:\n";
    weirdPrint("Test text 3", -5);
    std::cout << "Repeated print after " << callCount << " function calls:\n";
    weirdPrint("Test text 4", 15);
    std::cout << "\nDone\n";
}

namespace
{
    void weirdPrint(const char * text, int isWeird)
    {
        if (!isWeird)
            std::cout << text << "\n";
        else
        {
            for (int i = 0; i < callCount; i++)
                std::cout << text << "\n";
        }
        callCount++;
    }
}

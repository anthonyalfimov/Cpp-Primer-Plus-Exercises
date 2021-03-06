//
//  golf1003.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include "golf1003.hpp"


Golf::Golf(const char *fullName, int handicap)
{
    std::strncpy(m_fullName, fullName, nameLength);
    m_fullName[nameLength - 1] = '\0';              // ensure null-termination
    
    m_handicap = handicap;
}


bool Golf::set()
{
    std::string fullName;
    int handicap;
    
    std::cout << "Full name: ";
    if (!std::getline(std::cin, fullName) || fullName == "")
                                                    // on fail or if an empty string is read
    {
        std::cin.clear();                           // clear failbit
        return false;                               // report reading empty string
    }
    
    std::cout << "Handicap: ";
    while (!(std::cin >> handicap) || handicap < 0)
    {
        std::cout << "Invalid input, try again: ";
        std::cin.clear();                           // in case failbit was set, clear it
        clearInputBuffer();                         // remove leftover input
    }
    
    clearInputBuffer();                             // remove leftover input
    *this = Golf(fullName.c_str(), handicap);       // use constructor as required by the exercise
    return true;                                    // report successful input
}


const Golf& Golf::handicap(int newHandicap, bool isVerbose)
{
    if (isVerbose)
        std::cout
            << "Handicap for " << m_fullName << " changed from "
            << m_handicap << " to " << newHandicap << "\n";
    m_handicap = newHandicap;
    
    return *this;
}


void Golf::show() const
{ 
    std::cout << "> " << m_fullName << ", handicap: " << m_handicap << "\n";
}

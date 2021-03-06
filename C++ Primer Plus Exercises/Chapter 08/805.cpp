//
//  805.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

namespace
{
    constexpr int size {5};
    
    template <typename T>
    T max5(const T arr[]);
}

//   =============================
//   |       Main function       |
//   =============================
void show805()
{
    int test1[size] {23, 12, 1, -9, 0};
    double test2[size] {12.45, 4.5, 1.122e2, 23.2, -9.4};
    char test3[size] {'A', 'c', 'z', 'N', '/'};
    
    std::cout << "Max in int array:    " << max5(test1) << "\n";
    std::cout << "Max in double array: " << max5(test2) << "\n";
    std::cout << "Max in char array:   " << max5(test3) << "\n";
}

namespace
{
    template <typename T>
    T max5(const T arr[])
    {
        T max = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > max) max = arr[i];
        
        return max;
    }
}

#pragma once
#include <iostream>


//#define PRINT_ON
#ifdef PRINT_ON
    #define PRINT_BEGIN(x) 
    #define PRINT(x)  std::cout << x
    #define PRINTLN(x)  std::cout << x << std::endl
#endif

#ifndef PRINT_ON
    #define PRINT_BEGIN(x)  
    #define PRINT(x)  
    #define PRINTLN(x)  
#endif
#include <string>
#include <iostream>
#include <ostream>
#include "../include/sort-algs/lib.hpp"

std::string simple_lib_function() {
    return "Compiled in library";
}

void outputNameConsole(std::string& name)
{
    std::cout << "Hello " << name << std::endl;
}

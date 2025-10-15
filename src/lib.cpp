#include <string>
#include "../include/sort-algs/lib.hpp"

#include <iostream>
#include <ostream>

std::string simple_lib_function() {
    return "Compiled in library";
}

void outputNameConsole(std::string& name)
{
    std::cout << "Hello " << name << std::endl;
}

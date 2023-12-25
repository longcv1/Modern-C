#include <iostream>
#include <memory>
#include <vector>
#include "headers/dog.hpp"
#include "Templates/TypeDeduction.hpp"

void fnTypeDeduction()
{
    // MyContainer<bool> myContainer; // Error: cannot bind non-const lvalue ref of type 'bool&' to an rvalue of type 'bool'
    // myContainer[1] = true; // Error
    TypeDeduction::MyContainer<int> myContainer; // OK
    myContainer[0] = 100; // OK
}

int main(int, char**){
    std::cout << "Welcome to Modern C++ in advanced!\n";
    Dog *d1 = new Dog("DOG 01");
    d1->printInfo();
    fnTypeDeduction();
}
